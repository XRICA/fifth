#include<iostream>
#include <graphics.h>
#include <conio.h>
#include<ctime>
#include<math.h>
#include<vector>
using namespace std;
class Bullet{
    public:
    double x;
    double y;
    bool isMissed;
    double damage;
    Bullet(){
    }

    void Bullet_travel();
};


void Bullet::Bullet_travel(){

    putpixel(this->x,this->y,WHITE);
    this->y -= 3;
    
}

class Node{
    public:
    double x;
    double y;
};
class Plane{
    public:
    Node head;
    Node left;
    Node right;
    int HP;
    bool isDie;
    int speed;
    int score;
    int d;
    vector<Bullet> bullets;
    vector<Bullet>::iterator it;
    bool isEnmy;
    Plane(){
        this->head.x = 500;
        this->head.y = 500;
        this->left.x= this->head.x-20;
        this->left.y = this->head.y+20;
        this->right.x = this->head.x+20;
        this->right.y = this->head.y+20;
        this->HP = 20;
        this->isDie = false;
        this->score = 0;
        this->isEnmy = false;
        this->d = 5;
        for (int i = 0; i < 52; i++)
        {
            //初始化100枚弹药
            Bullet b;
            b.x = this->head.x;
            b.y = this->head.y;
            b.isMissed = false;
            b.damage = 20;
            this->bullets.push_back(b);
        }
         it = bullets.begin();
        
    }
    void draw_plane();

    void shot();
    
};

void Plane::draw_plane(){
    if (!this->isEnmy)
    {
        this->left.x = this->head.x-20;
        this->left.y = this->head.y+20;
        this->right.x = this->head.x+20;
        this->right.y = this->head.y+20;
        POINT pts[] = { {this->head.x, this->head.y}, {this->left.x, this->left.y}, {this->right.x, this->right.y} };
        	setpolyfillmode(WINDING);
         // 设置填充颜色为红色
         setfillcolor(WHITE);
        solidpolygon(pts, 3);
    }else{
        this->left.x = this->head.x-30;
        this->left.y = this->head.y-10;
        this->right.x = this->head.x+30;
        this->right.y = this->head.y-10;
        POINT pts[] = { {this->head.x, this->head.y}, {this->left.x, this->left.y}, {this->right.x, this->right.y} };
        	setpolyfillmode(WINDING);
         // 设置填充颜色为红色
         setfillcolor(RED);
        solidpolygon(pts, 3);
    }
}
vector<Plane> enemies;
    int as = 0;
void Plane::shot(){
   // cout << getheight() << endl;
   
        for (vector<Bullet>::iterator it = bullets.begin(); it != bullets.end(); it++)
    {
      
         if ((it->y <= 0))
         {
            it->y = this->head.y;
            it->x = this->head.x;
            it->isMissed = false;
         }
    }
    
    bullets.begin()->y -= 10; 
   //  cout << bullets.begin()->y << endl;
    for (vector<Bullet>::iterator it = bullets.begin()+1; it != bullets.end(); it++)
    {
      // cout << (it-1)->y << "," << it->y << endl;
        if (it->y > ((it-1)->y)+10 || it->y < bullets.begin()->y)
        {
            it->y -= 10;

            
        }
    }


    for (vector<Bullet>::iterator it = bullets.begin(); it != bullets.end(); it++)
    {    
            for (vector<Plane>::iterator et = enemies.begin(); et != enemies.end(); et++)
            {
                    POINT pts[] = { {et->head.x, et->head.y}, {et->left.x, et->left.y}, {et->right.x, et->right.y} };
                   
                if (!it->isMissed&&it->y<=et->head.y&&it->y>=et->left.y&&it->x>=et->left.x&&it->x<=et->right.x)
                {
                    et->HP -= it->damage;
                    
                    if (et->HP<=0)
                    {
                    et->isDie = true;
                    // cout << (et->HP==0) << endl;
                   
                    // clearpolygon(pts,3);
                    setfillcolor(WHITE);
                    solidcircle(et->head.x,et->head.y-10,40);
                    this->score++;
                     if (this->score%10 == 0&&this->score-as == 10){

                     for (vector<Bullet>::iterator it = bullets.begin(); it != bullets.end(); it++)
                        {
                        if(it->damage<10000){
                            it->damage+= (1+it->damage*0.15);
                            this->d = it->damage;
                            // cout << it->damage << endl;
                        }else{
                            break;
                        }
                        }
                        as = this->score;
                     }
                    }
                    else{
                    setpolyfillmode(WINDING);
                    setfillcolor(WHITE);
                    solidpolygon(pts, 3);
                    }
                   it->isMissed = true;
                  
                }
            }
        }
    Sleep(1);
     for (vector<Bullet>::iterator it = bullets.begin(); it != bullets.end(); it++)
    {
         
        if (!it->isMissed)
        {
            putpixel(it->x,it->y,WHITE);
        }
    }


 

       
    
   
    
}

void Ammunition_generation(Plane &plane){
 
}   


Plane plane;

void move(Plane &s,double x,double y){
   s.head.x += x;
   s.head.y += y;
   if (s.isEnmy&&(s.head.x<0||s.head.y>640))
   {
       s.head.x = rand()%getwidth();
        s.head.y = rand()%1;
   }
}
void enemy_create(){
    srand((unsigned int)time(NULL));
    for (int i = 0; i < 10; i++)
    {
        Plane enemy;
        enemy.HP = 500;
        enemy.isEnmy = true;
        enemy.head.x = rand()%getwidth();
        enemy.head.y = rand()%200;
        enemy.isDie = false;
        enemy.speed = rand()%4+1;
        // cout << enemy.head.x << "," <<enemy.head.y << endl;
        enemies.push_back(enemy);
    }
    
}

//按键处理
void keyControl(){
 
   if(GetAsyncKeyState(VK_LEFT)){
      move(plane,-5,0);
   }else if (GetAsyncKeyState(VK_RIGHT))
   {
       move(plane,5,0);
   }else if (GetAsyncKeyState(VK_UP))
   {
       move(plane,0,-5);
   }else if (GetAsyncKeyState(VK_DOWN))
   {
       move(plane,0,5);
   }
   
}

void init(){
   initgraph(1024, 640);
   setbkcolor(BLACK);
   cleardevice();
   enemy_create();
   plane.draw_plane();
    
}


void string2tchar(std::string &src, TCHAR* buf)
{
#ifdef UNICODE  
	_stprintf_s(buf, MAX_PATH, _T("%S"), src.c_str());//%S宽字符  
#else  
	_stprintf_s(buf, MAX_PATH, _T("%s"), src.c_str());//%s单字符
#endif
}
int main(){
   init();
    TCHAR a[] = _T("");
    TCHAR b[] = _T("");
    TCHAR c[] = _T("");
    int x = 1;
    string ps2;
   while (true)

   {
      //双缓冲绘图
      BeginBatchDraw();
      //绘制前清空
      cleardevice();
      // 输出字符串（MBCS 字符集）
        string ps = to_string(plane.score);
        string2tchar(ps,a);
       outtextxy(10, 20, a);
        string ps3 = to_string(plane.d);
        string2tchar(ps3,b);
        outtextxy(10, 40, b);
      for (vector<Plane>::iterator it = enemies.begin(); it != enemies.end(); it++)
      {
        if (!it->isDie)
        {
            it->draw_plane();
            move(*it,0,it->speed);
        }else{
        it->head.x = rand()%getwidth();
        it->head.y = rand()%1;
        it->isDie = false;
        it->HP=500*(1+x/10);
        cout <<it->HP <<endl;
        ps2= to_string(it->HP);
        string2tchar(ps2,c);
        //  outtextxy(10, 60, c);
        x++;
        }
      }
      plane.draw_plane();
      plane.shot();
      keyControl();
      EndBatchDraw();
   }
   
    getch();
    return 0;
}

