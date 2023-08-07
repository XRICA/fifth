#include <iostream>
#include"Person.hpp"
#include<vector>
#include <ctime>
using namespace std;
int main()
{
    srand(time(0));
   vector<Person> v;
   string names[] = {"A","B","C","D","E"};
    for (size_t i = 0; i < sizeof(names)/sizeof(names[0]); i++)
    {
        Person p(names[i]);
        v.push_back(p);
    }
    cout << sizeof(names)/sizeof(names[0])  << endl;
    
    for (vector<Person>::iterator i = v.begin(); i != v.end(); i++)
    {
        int sum = 0;
        float avg = 0;
        cout<< "Scores if this round:" ; 
        for(int j=0;j<10;j++){
            int score = rand()%40+60;
            (*i).mark(score);
            cout << score << " ";
        }
         cout << endl;
         (*i).remove();
         sum += (*i).total();
    cout << "sum:"  <<  sum << endl;
    cout << "avg:"  <<  sum/8 << endl;

    }

        // cout << rand()%11 << endl;


   return 0;
}
