#include<iostream>
using namespace std;

struct process
{
    int arrival,burst;
    int wait,execution,time,ID;
};

int main()
{
    cout<<"Enter Number of processes: ";
    int numberOfProcesses,i,mini,j,numberArrived = 0, processPointer = 0;
    cin>>numberOfProcesses;
    process p[numberOfProcesses],temp, arrived[numberOfProcesses];
    cout<<"Enter the Burst Time:-\n";
    for(i=0;i<numberOfProcesses;i++)
    {
        p[i].ID=i;
        cout<<"\nProcess:"<<i;
        cout<<"\nBurst Time:";
        cin>>p[i].burst;
    }
    for(i=0;i<numberOfProcesses;i++)
    {
        mini=i;
        for(j=i+1;j<numberOfProcesses;j++)
        {
            if(p[mini].burst>p[j].burst)
            {
                mini=j;
            }
        }
        if(mini!=i)
        {
            temp=p[i];
            p[i]=p[mini];
            p[mini]=temp;
        }
    }
    p[0].execution=p[0].burst;
    p[0].wait=0;
    p[0].time=p[0].wait+p[0].burst;
    for(i=1;i<numberOfProcesses;i++)
    {
        p[i].execution=p[i].burst+p[i-1].execution;
        p[i].wait=p[i-1].execution;
        p[i].time=p[i].wait+p[i].burst;
    }
    float avgtime=0.0,avgwait=0.0;
    for(i=0;i<numberOfProcesses;i++)
    {
        avgtime+=p[i].time;
        avgwait+=p[i].wait;
    }
    avgtime/=numberOfProcesses;
    avgwait/=numberOfProcesses;
    cout<<"\n\nProc\t|Burst\t|Wait\t|Exec\t|Time\n";
    for(i=0;i<numberOfProcesses;i++)
    {
        cout<<p[i].ID<<"\t|"<<p[i].burst<<"\t|"<<p[i].wait<<"\t|"<<p[i].execution<<"\t|"<<p[i].time;
        cout<<endl;
    }
    cout<<"\n\nAvg Total Time: "<<avgtime;
    cout<<"\nAvg Wait Time: "<<avgwait;
    return 0;
}
