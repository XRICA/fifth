#pragma once
#include<iostream>
using namespace std;
template<class T>
class Array{
    private:
    T *addr;
    int capactity;
    int  size;
    public:
    Array(int capacity){
        this->capactity = capacity;
        this->size = 0;
        this->addr = new T[this->capactity];
    }
    //拷贝构造
    Array(const Array<int>& array)
    {
        this->size = array.size;
        this->capactity = array.capactity;
        if (this->addr!=NULL)
        {
            delete[] this->addr;
            this->addr = NULL;
        }
        
        this->addr = new T[this->capactity];
        for(int i=0;i<this->size;i++){
            this->addr[i] = array.addr[i];
        }
    }

    T& operator[](int index){
        if (index>=this->size)
        {
            this->size++;
            expand();
        }
        
        return this->addr[index];
    }
    //同样是深拷贝
    Array& operator=(const Array<T> &array){
        this->size = array.size;
        this->capactity = array.capactity;
        if (this->addr!=NULL)
        {
            delete[] this->addr;
            this->addr = NULL;
            /* code */
        }
        this->addr = new T[this->capactity];
        for(int i = 0;i<this->size;i++){
            this->addr[i] = array[i];
        }
        return *this;
    }

    //尾删法
    void pop_back(){
        if (this->size==0)
        {
           cout << "数组中没有元素" << endl;
           return;
        }
        //逻辑删除，让用户无法访问即可
        this->size--;
        
    }

    void push_back(T val){
        this->addr[size] = val;
        this->size++;
        expand();
    }

    void expand(){
        if (this->size==this->capactity)
        {
            int bc = 2*this->capactity+1;
            T temp[bc];
            for(int i = 0;i < this->size ; i++){
                temp[i] = this->addr[i];
            }

            delete []this->addr;
            this->addr = NULL;
            this->capactity = bc;
            this->addr = new T[bc];
               for(int i = 0;i < this->size ; i++){
                this->addr[i] = temp[i];
            }
        }
        
    }

    void printf(){
        for(int i = 0;i < this->size ; i++){
                cout << this->addr[i] << " ";
            }
    }

    int sizeOf(){
        return this->size;
    }

    int capacityOf(){
        return this->capactity;
    }

    ~Array(){
        cout << "析构函数调用" <<endl;
        if(this->addr!=NULL){
            delete[] this->addr;
            this->addr = NULL;
        }
    }






};