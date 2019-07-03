#include <iostream>
#include<fstream>
#include <algorithm>
#include<string>
#define statistics 6//改变学生人数
using namespace std;
struct student{
    string number;//学号
    string name;//姓名
    string sex;//性别
    int age;//年龄
    double score[7];//成绩
    double ave;//平均分
}a[statistics];
struct people{
    string referee;//裁判
    string people;
    double score[7];
};
bool cmp(student s1,student s2)
{
    return s1.ave>s2.ave;
}
int main() {
    student t[statistics];
    people k[statistics];
    int i,j;
    ofstream inf("/Users/s20181106278/Desktop/myinf.txt");
    ifstream onf("/Users/s20181106278/Desktop/onf.txt");
    ifstream enf("/Users/s20181106278/Desktop/enf.txt");
    if(onf.is_open())
    {
        for(i=0;i<statistics;++i)//向文件中输入学生信息
        {
            onf>>a[i].number>>a[i].name>>a[i].sex>>a[i].age;
        }
        onf.close();
    }
    if(enf.is_open())
    {
        for(j=0;j<7;j++)
        {
            enf>>k[j].referee;
        }
        for(j=0;j<statistics;++j)//输入裁判打的分数n
        {
            for(i=0;i<7;++i)
            {
                enf>>k[j].score[i];
            }
            enf>>k[j].people;
        }
        enf.close();
    }
    for(i=0;i<statistics;i++)//将裁判分数换成学生成绩
    {
        for(j=0;j<7;j++)
        {
            t[i].score[j]=k[i].score[j];
        }
    }
    for(i=0;i<statistics;i++)//冒泡排序
        sort(t[i].score,t[i].score+7);
    for(j=0;j<statistics;++j)//求平均分
    {
        for(i=1;i<6;++i)
        {
            t[j].ave+=t[j].score[i];
        }
        t[j].ave/=5;
    }
    for(i=0;i<statistics;i++)//将平均分转到数组里
    {
        a[i].ave=t[i].ave;
    }
    sort(a,a+statistics,cmp);//将平均分从大到小排序
    
    if(inf.is_open())
    {
        for(int i=0;i<statistics;i++)
        {
            inf<<a[i].number<<" "<<a[i].name<<" "<<a[i].sex<<" "<<a[i].age<<" "<<a[i].ave<<" "<<endl;
        }
        inf.close();
    }
    return 0;
}

