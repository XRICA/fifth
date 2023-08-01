#include<iostream>
#include <graphics.h>
#include <conio.h>
#include<ctime>
#include<math.h>
using namespace std;
const int GridSize = 10;
#define SPEED_LOW 100;
class Sprite
{
   public:
   friend void sprite_draw(Sprite &s);
   friend void move(Sprite &s,double x,double y);
   friend double getDis(Sprite &s1,Sprite &s2);
private:
   double x;
   double y;
   double r;
   DWORD color; //半径
   bool isDie;
   string name;
   int food_index;
  
public:
 double speed;
   Sprite(){
   }
   Sprite(double x,double y,double r,string name){
      this->x = x;
      this->y = y;
      this->r = r;
      this->name = name;
      this->color = RGB(rand()%256,rand()%256,rand()%256); //[0,255]
      this->isDie = false;
      this->food_index = -1;
      this->speed = 1.5;
  }

  double getR(){
   return this->r;
  }

  void setR(double r){
   this->r = r; 
  }

  void setIsDie(bool die){
   this->isDie = die;
  }

  bool getIsDie(){
   return this->isDie;
  }
  int & getIndex(){
      return this->food_index;
  }
  void setIndex(int index){
   this->food_index = index;
  }

  double & getX(){
   return this->x;
  }

   void setX(int x){
   this->x = x;
  }
   double & getY(){
   return this->y;
  }

   void setY(int Y){
   this->y = y;
  } 
};
#define FOOD_NUM 110
#define AI_NUM 10
Sprite player(100,100,20,"xzx");
Sprite foods[FOOD_NUM];
Sprite ais[AI_NUM];

void init(){
   //随机数种子
   srand((unsigned int) time(NULL));

   for (int i = 0; i < FOOD_NUM-AI_NUM; i++)
   {
      Sprite f(rand()%getwidth(),rand()%getheight(),5,to_string(rand()+i));
      foods[i] = f;
   }

   for (int i = 0; i < AI_NUM; i++)
   {
      Sprite ai(rand()%getwidth(),rand()%getheight(),rand()%15+6,to_string(rand()+i));
      ais[i] = ai;
   }

   for (int i = FOOD_NUM-AI_NUM; i < FOOD_NUM; i++)
   {
       foods[i] = ais[i-FOOD_NUM];
   }


   
}

void sprite_draw(Sprite &s){
   if (!s.isDie)
   {
     //颜色填充
     setfillcolor(s.color);
     //画圆
     solidcircle(s.x,s.y,s.r);
     //设置文字yanse
   //   settextcolor(RGB(222,22,65));
     //透明背景
     setbkmode(TRANSPARENT);
   //   settextstyle(28,0,"行楷");
   //   outtextxy(s.x-textwidth(s.name),s.y,s.name);
   }
}

void move(Sprite &s,double x,double y){
   s.x += x;
   s.y += y;
}
//追击
void att(Sprite &run,Sprite &chase){
   if(chase.getX() < run.getX() &&chase.getY() < run.getY()){
      chase.getX()+= chase.speed;
      chase.getY()+= chase.speed;
   }else if (chase.getX() > run.getX() && chase.getY() > run.getY())
   {
       chase.getX()-= chase.speed;
       chase.getY()-= chase.speed;
   }
   // else{

    if (chase.getX() < run.getX() )
   {
      chase.getX()+= chase.speed;
   }else if(chase.getX() > run.getX()){
       chase.getX()-= chase.speed;
   }
   
    if (chase.getY() < run.getY())
   {
      chase.getY()+= chase.speed;
   }else if(chase.getY() > run.getY()){
      chase.getY()-= chase.speed;
   }
   // }

   double d = getDis(chase,run);
   if (d<=chase.getR()-run.getR())
   {
      run.setIsDie(true);
      chase.setR(run.getR()/10+chase.getR());
      return;
   }
   
   //       for (int i = 0; i < FOOD_NUM-AI_NUM; i++)
   //       {
   //          cout << "66769" << endl;
   //    double d = getDis(chase,foods[i]);
   //    if (chase.getR()>foods[i].getR()&&!foods[i].getIsDie()&&(d<=chase.getR()-foods[i].getR()))
   //    {
   //       foods[i].setIsDie(true);
   //       // cout << "下标为: " << i << ",已被吃" << endl;
   //       double r = foods[i].getR()/10+chase.getR();
   //       // chase.speed -= foods[i].getR()/SPEED_LOW;
   //       chase.setR(r);
   //       break;
   //    }else if (chase.getR()<foods[i].getR()&&!foods[i].getIsDie()&&d<=foods[i].getR()-chase.getR())
   //    {
   //       chase.setIsDie(true);
   //       break;
   //    }
   // }
 
   
   
}
void aiMove(){
   //随便找一个食物去吃
for (int i = 0; i < AI_NUM; i++)
{
   if (ais[i].getIndex()==-1)
   {
      int index = rand()%FOOD_NUM;
       ais[i].setIndex(index);
   }
   
   if (!ais[i].getIsDie())
   {
      //判断目标食物是否存在，存在就去追，否则就设置
      // cout << "NO." << ais[i].getIndex() << " STATUS:" << foods[ais[i].getIndex()].getIsDie() 
      // << "::(" <<foods[ais[i].getIndex()].getX() << "," <<  foods[ais[i].getIndex()].getY() << ")"<< endl;
      // cout << (foods[ais[i].getIndex()].getIsDie()) << endl;
      if (foods[ais[i].getIndex()].getIsDie())
      {
         // int f = rand()%FOOD_NUM;
         // cout << "食物下标为：" << f << endl;
         //用容器，根据大小随机取
         int min = 0;
         for (int j = 0; j < FOOD_NUM; j++)
         { 
             if (foods[min].getIsDie())
               {
                  min++;
               }
            // cout << ((j-100)!=i&&!foods[j].getIsDie()&&ais[i].getR()>foods[j].getR()) << endl;
            if ((j-100)!=i&&!foods[j].getIsDie()&&ais[i].getR()>foods[j].getR())
            {
              
               //  cout << getDis(ais[i],foods[min]) << ":" << getDis(ais[i],foods[j]) << endl;
                if (getDis(ais[i],foods[min]) > getDis(ais[i],foods[j]))
                {
                   min = j;
                  //  cout <<"下标为："<<  j << endl;
                  //  cout << min << endl;
                }
                
            }
         }
           ais[i].setIndex(min);
      }else if(!foods[ais[i].getIndex()].getIsDie())
      
          // cout << ais[i].getIndex() << endl;
         // player.setIsDie(true);
       att(foods[ais[i].getIndex()],ais[i]);
       }else{
         // int min = 0;
         for(int s=0;s<AI_NUM;s++){
               //   if (ais[min].getIsDie())
               // {
               //    min++;
               // }
            if (s!=i&&!ais[s].getIsDie()&&ais[i].getR()>ais[s].getR())
            {
               // if (getDis(ais[i],ais[min]) > getDis(ais[i],ais[s]))
               // {
               //    min = s;
               // }
               ais[i].setIndex(s);
            }
         }
         // ais[i].setIndex(min);
           if (!ais[ais[i].getIndex()].getIsDie())
       {
         cout<<"//" << ais[ais[i].getIndex()].getIndex() << ",(" << ais[ais[i].getIndex()].getX() << ais[ais[i].getIndex()].getY() <<  ")" << endl;
         att(ais[ais[i].getIndex()],ais[i]);
       }else{
         cout << "该目标已死亡" << endl;
       }
         // cout << "？？" << endl;
       }
       
   }
  
}

//获取圆心距离
double getDis(Sprite &s1,Sprite &s2){
   return sqrt(pow(s1.x-s2.x,2)+pow(s1.y-s2.y,2));
}
//吃食物
void playerEat(){
   //玩家和食物比较
   for (int i = 0; i < FOOD_NUM; i++)
   {
      double d = getDis(player,foods[i]);
      if (player.getR()>foods[i].getR()&&!foods[i].getIsDie()&&(d<=player.getR()-foods[i].getR()))
      {
         foods[i].setIsDie(true);
         double r = foods[i].getR()/10+player.getR();
         player.setR(r);
         // player.speed -= foods[i].getR()/50;
         break;
      }else if (player.getR()<foods[i].getR()&&!foods[i].getIsDie()&&d<=foods[i].getR()-player.getR())
      {
         player.setIsDie(true);
         break;
      }
   }
}
//玩家和AI碰撞
void crash(){
   for (int i = 0; i < AI_NUM; i++)
   {
   //       double d = getDis(player,ais[i]);
   //    if (player.getR()>ais[i].getR()&&!ais[i].getIsDie()&&(d<=player.getR()-ais[i].getR()))
   //    {
   //       ais[i].setIsDie(true);
   //       double r = ais[i].getR()/10+player.getR();
   //       player.setR(r);
   //       // player.speed -= r/50;
   //    }else if (player.getR()<ais[i].getR()&&!ais[i].getIsDie()&&d<=ais[i].getR()-player.getR())
   //    {
   //       double r = ais[i].getR()+player.getR()/10;
   //       ais[i].setR(r);
   //       // ais[i].speed -=player.getR()/10;
   //       player.setIsDie(true);
   //    }

      for (int k = 0; k < AI_NUM; k++)
      {
         double d = getDis(ais[k],ais[i]);
         if (i!=k&&!ais[i].getIsDie()&&!ais[k].getIsDie()&&ais[i].getR() > ais[k].getR()
          && d <= (ais[i].getR()-ais[k].getR()))
         {
            ais[k].setIsDie(true);
            ais[i].setR(ais[i].getR()+ais[k].getR()/10);
            ais[i].speed -= ais[k].getR()/SPEED_LOW;
         }
         
      }
      
   }
   
}

//按键处理
void keyControl(){
 
   if(GetAsyncKeyState(VK_LEFT)){
      move(player,-player.speed,0);
   }else if (GetAsyncKeyState(VK_RIGHT))
   {
       move(player,player.speed,0);
   }else if (GetAsyncKeyState(VK_UP))
   {
       move(player,0,-player.speed);
   }else if (GetAsyncKeyState(VK_DOWN))
   {
       move(player,0,player.speed);
   }
   
}

void draw(){
   setlinecolor(RGB(31,31,31));
   //绘制格子
   for (int i = 0; i < getheight()/10; i++)
   {
      line(0,i*GridSize,getwidth(),i*GridSize);
   }

    for (int i = 0; i < getwidth()/10; i++)
   {
      line(i*GridSize,0,i*GridSize,getheight());
   }
   // sprite_draw(player);
   for (int i = 0; i < FOOD_NUM; i++)
   {
      sprite_draw(foods[i]);
   }

   for (int i = 0; i < AI_NUM; i++)
   {
      sprite_draw(ais[i]);
   }
   
   // foods[FOOD_NUM-1] = player;
   
}


int main()
{
    //创建图形窗口
   initgraph(1024, 640);
   //设置背景颜色S
   setbkcolor(WHITE);
   cleardevice();
   init();
   // !player.getIsDie()
   while (true)

   {
      //双缓冲绘图
      BeginBatchDraw();
      //绘制前清空
      cleardevice();
      draw();
      // keyControl();
      // playerEat();
      aiMove();
      crash();
      EndBatchDraw();
   }
   
   getch();
	return 0;
}