#include <iostream>

using namespace std;
class MyAdd{
    public:
    int operator()(int a,int b){
        return a+b;
    }
};

class MyPrint{
    
    public:
    int count;
    MyPrint(){
        this->count = 0;
    }
    void operator()(string test){
        cout << test << endl;
        this->count++;
    }
};
void doPrint(MyPrint &mp,string test){
    mp(test);
}
//函数对象可以作为参数传递
void test03(){
    MyPrint myPrint;
    doPrint(myPrint,"sx");
}
int main()
{
   MyAdd add;
   //可以有参数可以有返回值
   cout << add(10,20) << endl;;
    MyPrint pr;
    pr("Hello");
    test03();
   return 0;
}
