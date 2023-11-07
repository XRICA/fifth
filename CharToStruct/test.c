#include <stdio.h>
#include<string.h>
struct  T
{
    int now;
};
// 定义结构体类型
typedef struct
{
    struct T tt;
    int value1;
    int value2;
} MyStruct;
int main()
{
    // 定义字符数组
    char charArray[1];
    // 定义结构体变量并赋值
    MyStruct myStruct;
    myStruct.value1 = 10;
    myStruct.value2 = 20;
    myStruct.tt.now = 30;
    MyStruct tar;
    // 将结构体数据复制到字符数组
    (void)memcpy(&charArray[0], &myStruct, sizeof(MyStruct));
    memset(&tar,0,sizeof(tar));

    (void)memcpy(&tar,&charArray[0],sizeof(tar));
    printf("Tar: tt.now=%d value1=%d , value2=%d\n",
    tar.tt.now,
    tar.value1,tar.value2);
}   