#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
//返回类型是bool，称为谓词

class GreaterFive{
    public:
    bool operator()(int val){
        return val > 5;
    }
};
int main()
{
    vector<int> v;
   for (int i = 0; i < 10; i++)
   {
    v.push_back(i);
   }
   vector<int>::iterator it = find_if(v.begin(),v.end(),GreaterFive());
   if (it==v.end())
   {
        cout << "未找到"<<endl;
   }else{
    cout << "该数字为" << *it << endl;
   }
   

   return 0;
}
