#include<iostream>
using namespace std;
struct time
{
    int hour;
    int min;
    int sec;
};
int main()
{
    struct time T1={10,54,115};
    struct time T2={12,90,310};
    struct time T3;
    T3.sec=T1.sec+T2.sec;
    T3.min=T1.min+T2.min+T3.sec/60;
    T3.hour=T1.hour+T2.hour+T3.min/60;
    T3.min=(T3.min)%60;
    T3.sec=(T3.sec)%60;
    cout<<T3.hour<<", "<<T3.min<<", "<<T3.sec;
    return 0;

}