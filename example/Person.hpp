#pragma once
#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;

class Person{
    private:
    string name;
    deque<int> scores;
    public:
    Person(string name){
        this->name = name;
    }

    void mark(int score){
        this->scores.push_back(score);
    }

    void remove(){
        sort(this->scores.begin(),this->scores.end());
        this->scores.pop_front();
        this->scores.pop_back();
    }

    int total(){
        int sum = 0;
        for (deque<int>::iterator i = this->scores.begin(); i != this->scores.end(); i++)
        {
            // cout << *i << endl;
            sum += *i;
        }
        return sum;
    }



};