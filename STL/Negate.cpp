#include <iostream>
#include<functional>
using namespace std;

void test01(){
    negate<int> n;
   cout <<  n(50);

}

int main()
{
   test01();
   return 0;
}
