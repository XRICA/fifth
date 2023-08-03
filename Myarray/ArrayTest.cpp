#include<iostream>
#include "Array.hpp"
#include "Person.hpp"
using namespace std;

void test01(){
    Array<int> a(2);
    a.push_back(1);
    a.push_back(2);
    a[2] = 3; 
    a[3] = 4;
    // cout << a[1] << endl;
    a.printf();
    cout << "此时大小 " << a.sizeOf() << endl;
    cout << "容量为 " << a.capacityOf() << endl;
}

void test02(){
    Array<Person> a(1);
    Person p("张三",19);
    Person p2("李四",18);
    a[0] = p;
    a[1] = p2;
    a[2] = p2;
    a[3] = p;
    // a.push_back(p);
    // a.push_back(p2);
    // a[3] = p2;
    // cout << p << endl;
    a.printf();
}
int main(){
   test02();



}