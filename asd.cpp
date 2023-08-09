#include <iostream>
#include<vector>
#include<deque>
#include<map>
#include<ctime>
#include<algorithm>
using namespace std;
#define knockout 1,final 2;

//12人，共两轮，对应编号10001-10012，分组，每组6人
//每轮抽签后演讲
//去除最高和最低分，获取平均成绩
//前三名晋级，每轮比赛后显示晋级选手信息

class contestant{
public:
    string id;
    int score;
    contestant(string id,int score){
        this->id = id;
        this->score = score;
    }


};
bool compare(contestant &c1,contestant &c2){
    return c1.score>c2.score;
}
vector<contestant> mark(vector<string> &v){
    vector<contestant> res;
    srand((unsigned int)time(NULL));

    for (string id:v)
    {
        deque<int> scores;
        for (int i = 0; i < 10; i++)
        {
            int score = rand()%60+40;
            scores.push_back(score);
        }
        sort(scores.begin(),scores.end());
        scores.pop_back();
        scores.pop_front();
        int sum = 0;
        for (int s: scores)
        {
            sum+=s;
        }
        int fi = sum/scores.size();
        contestant con(id,fi);
        cout << "选手:" << id << " 本轮得分:" << fi << endl;
        res.push_back(con);

    }
    return res;
}
void  printFinal(vector<contestant> &v){
    for (vector<contestant>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "编号：" << (*it).id << " 得分：" << (*it).score << " ";
    }
    cout << endl;
}
int main()
{
    srand((unsigned int)time(NULL));
    string ids[12];
    int first = 10001;
    for (int i = 0; i < 12; i++)
    {
        ids[i] = to_string(first+i);
        cout << ids[i]<<endl;
    }

    vector<string> v1;
    vector<string> v2;
    for (int i = 0; i < 12; i++)
    {
        if (i<6)
        {
            v1.push_back(ids[i]);
        }else{
            v2.push_back(ids[i]);
        }
    }

    random_shuffle(v1.begin(),v1.end());
    random_shuffle(v2.begin(),v2.end());
    cout << "淘汰赛:" << endl;
    vector<contestant> v3 = mark(v1);
    sort(v3.begin(),v3.end(),compare);
    cout << "A组晋级名单:" << endl;
//    v3.resize(3);
    printFinal(v3);
    vector<contestant> v4 = mark(v2);
    sort(v4.begin(),v4.end(),compare);
    cout << "B组晋级名单:" << endl;
    printFinal(v4);
    return 0;
}
