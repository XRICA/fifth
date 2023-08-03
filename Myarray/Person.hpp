#pragma once
#include<iostream>
using namespace std;

class Person{
    public:
    friend ostream& operator<<(ostream &os,Person &person);
    private:
    string name;
    int age;
    public:
    Person(){
        cout << "无参构造" << endl;
    }
    Person(string name,int age){
        cout << "有参构造" << endl;
        this->name = name;
        this->age = age;
    }

    ~Person(){
        cout << "Person析构函数调用" << endl;
    }

};
//只能用全局函数重载左移运算符
ostream& operator<<(ostream &os,Person &person){
    cout << "姓名:" << person.name
    << " 年龄:" << person.age << endl;
    return os;
}