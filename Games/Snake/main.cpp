#include<iostream>
#include <graphics.h>
#include <conio.h>
#include<ctime>
#include<math.h>
#include<vector>

using namespace std;

class node{
    public:
    double x;
    double y;
    bool isDie;
    node(){
         this->isDie = true;
    }

    node(double x,double y){
        this->x = x;
        this->y = y;
        this->isDie = false;
    }
};
class Snake{
    public:
    node head;
    vector<node> body;
    int len;
    Snake(){}
    Snake(node head,int length){
        this->head = head;
        this->len = length;
        cout << 1 << endl;;
        for (int i = 0; i < len; i++)
        {
            // cout << head.x-(i+1)*5 << "," << head.y << endl;

            node n(head.x-(i+1)*30,head.y);
            this->body.push_back(n);
        }
        
    }
};

node head(0,320);
Snake snake(head,60);
void drawSnake(){
     setfillcolor(WHITE);

     solidcircle(snake.head.x,snake.head.y,3);
     for (int i = 0; i < snake.len; i++)
     {
        // 
        // cout << snake.body.at(i).x << "," <<snake.body.at(i).y << endl;
        solidcircle(snake.body.at(i).x,snake.body.at(i).y,3);
     }
     
   //   settextcolor(RGB(222,22,65));
     setbkmode(TRANSPARENT);
}
void init(){
   initgraph(1024, 640);
   setbkcolor(BLACK);
   cleardevice();
//    init();
    
}
void move(Snake &s,double x,double y){
   for (vector<node>::iterator it=s.body.end()-1; it != s.body.begin(); it--)
   {
        //  cout << it->x << "," << it->y << "||";
        it->x = (it-1)->x;
        it->y = (it-1)->y; 
        // cout << it->x << "," << it->y << endl;
   }
   s.body.begin()->x = s.head.x;
   s.body.begin()->y = s.head.y;
   s.head.x += x;
   s.head.y += y;
   
}
int speed_x = 3;
int speed_y = 0;
void keyControl(){
    bool flag = true;
    // while (flag)
    // {
    move(snake,speed_x,speed_y);
    Sleep(30);
    if(GetAsyncKeyState(VK_LEFT)){
      move(snake,-3,0);
      speed_x = -3;
      speed_y = 0;
   }else if (GetAsyncKeyState(VK_RIGHT))
   {
       move(snake,3,0);
        speed_x = 3;
      speed_y = 0;
   }else if (GetAsyncKeyState(VK_UP))   
   {
       move(snake,0,-3); 
        speed_x = 0;
      speed_y = -3;   
   }else if (GetAsyncKeyState(VK_DOWN))
   {
       move(snake,0,3);
        speed_x = 0;
        speed_y = 3;
   }
      drawSnake();
      flag = false;
 
}

node food;
void food_create(){
     if (food.isDie)
     {
        srand((unsigned int) time(NULL));
        food.x = rand()%1024;
        food.y = rand()%640;
        cout <<"head:" << snake.head.x << "," << snake.head.y << endl;
        cout << "food:" << food.x << "," << food.y <<endl;
        food.isDie = false;
     }
    solidcircle(food.x,food.y,3);

}
double getDis(node &n1,node &n2){
   return sqrt(pow(n1.x-n2.x,2)+pow(n1.y-n2.y,2));
}
void eat(){
    //  cout <<"head:" << snake.head.x << "," << snake.head.y << endl;
    double distance = getDis(food,snake.head);
    if (!food.isDie && distance <= 4)
    {
        cout << "ENTER" << endl;
        snake.len++;
        node tail;
        snake.body.push_back(tail);
        for (vector<node>::iterator it = snake.body.end()-1; it != snake.body.begin(); it--)
        {
            it->x = (it-1)->x;
            it->y = (it-1)->y;
        }
        snake.body.begin()->x = snake.head.x;
        snake.body.begin()->y = snake.head.y;
        snake.head.x = food.x;
        snake.head.y = food.y;
        // cout << "大小：" << snake.body.size() << endl;
        food.isDie = true;      
        // drawSnake();  
    }

    
}

void crash(){
    for (vector<node>::iterator it = snake.body.begin(); it != snake.body.end(); it++)
    {
        if (snake.head.x == it->x && snake.head.y == it->y)
        {
            cout << "game over" << endl;
            snake.head.isDie = true;
            break;
        }
        
    }
    
}
int main(){
   init();
   // !player.getIsDie()
   while (!snake.head.isDie)

   {
      //双缓冲绘图
      BeginBatchDraw();
      //绘制前清空
      cleardevice();
      food_create();
      keyControl();
      eat();
      crash();
      // playerEat();
      EndBatchDraw();
   }
   
   getch();
	return 0;
}

