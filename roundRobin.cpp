#include<iostream>

using namespace std;

struct process
{
    int arrival,burst;
    int wait,turnAroundTime,sTime,ID;
};

int main()  {
    cout<<"Enter Number of processes: ";
    int n,i,counts,timeQ,temp,totalServiceTime=0;
    cin>>n;
    process p[n];
    cout<<"Enter the Burst Time:-\n";
    for(i = 0 ; i < n ; i++)    {
        p[i].ID=i;
        cout<<"\nProcess:"<<i;
        cout<<"\nBurst Time:";
        cin>>p[i].burst;
        p[i].sTime=p[i].burst;
        p[i].wait = 0;
    }
    cout<<"\n Enter the time quantum : ";
    cin>>timeQ;
    while(true) {
        for(i = 0 ,counts = 0 ; i < n; i++)    {
            temp = timeQ;
            if( p[i].sTime == 0 )   {
                counts++;
                continue;
            }
            if(p[i].sTime >= timeQ) {
                p[i].sTime -= timeQ;
            }
            else    {
                temp = p[i].sTime;
                p[i].sTime = 0;
            }
            totalServiceTime += temp;
            p[i].turnAroundTime = totalServiceTime;
        }
        if(counts == n)
            break;
    }
    for(i = 0; i < n; i++)  {
        p[i].wait = p[i].turnAroundTime - p[i].burst;
    }
    float avgtime=0.0,avgwait=0.0;
    for(i=0;i<n;i++)
    {
        avgtime+=p[i].turnAroundTime;
        avgwait+=p[i].wait;
    }
    avgtime/=n;
    avgwait/=n;
    cout<<"\n\nProc\t|Burst\t|Wait\t|tTime\t|sTime\n";
    for(i=0;i<n;i++)
    {
        cout<<p[i].ID<<"\t|"<<p[i].burst<<"\t|"<<p[i].wait<<"\t|"<<p[i].turnAroundTime<<"\t|"<<p[i].sTime;
        cout<<endl;
    }
    cout<<"\n\nAvg Total Time: "<<avgtime;
    cout<<"\nAvg Wait Time: "<<avgwait;
    cout<<"\nTotal Time: "<<totalServiceTime;
    return 0;
}
