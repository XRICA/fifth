#include<iostream>
#include <graphics.h>
#include <conio.h>
#include<ctime>
#include<math.h>
#include<vector>
using namespace std;
class Node{
    public:
    double x;
    double y;
};
class Bomb{
    public:
    int range;
    int damage;
    int time;
    Node node;
    bool status;
    Bomb(){
        this->range = 1;
        this->damage = 1;
        this->time = 10;
        this->status = false;
    }


    void drop_bomb(double x,double y);
    void draw();
    void boom();
};

void init(){
   initgraph(10104, 640);
   setbkcolor(BLACK);
   cleardevice();
    
}

void Bomb::drop_bomb(double x,double y){
    this->node.x = x;
    this->node.y = y;
    
}

void Bomb::draw(){
    setfillcolor(BROWN);
    solidcircle(this->node.x,this->node.y,10);
    Sleep(10);
}
void Bomb::boom(){
    
    if (!this->status)
    {
        // setfillcolor(WHITE);
        Sleep(1000);
        // clearcircle(this->node.x,this->node.y,10);
        // Sleep(100);
    solidcircle(this->node.x-15,this->node.y,10);
    solidcircle(this->node.x+15,this->node.y,10);
    solidcircle(this->node.x,this->node.y-15,10);
    solidcircle(this->node.x,this->node.y+15,10);
    this->status = true;
    }else{
  
    
    //   Sleep(100);
     clearcircle(this->node.x,this->node.y,10);
    clearcircle(this->node.x-15,this->node.y,10);
    clearcircle(this->node.x+15,this->node.y,10);
    clearcircle(this->node.x,this->node.y-15,10);
    clearcircle(this->node.x,this->node.y+15,10);
    this->status = false;
    }
    
   
  
}
int main()
{
   init();
   Bomb b;
    b.drop_bomb(500,350);
   while (true)
   { Sleep(2000);
    b.draw();
     b.boom();
   }
   
   return 0;
}