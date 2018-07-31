#include<iostream>

using namespace std;

struct process
{
    int arrival,burst,priority;
    int wait,execution,time,ID;
};

int main()
{
    cout<<"Enter Number of processes: ";
    int n,i,mini,j;
    cin>>n;
    process p[n],temp;
    cout<<"Enter the Burst Time & Arrival:-\n";
    for(i=0;i<n;i++)
    {
        p[i].ID=i;
        cout<<"\nProcess:"<<i;
        cout<<"\nBurst Time:";
        cin>>p[i].burst;
        cout<<"Arrival:";
        cin>>p[i].arrival;

    }
    for(i=0;i<n;i++)
    {
        mini=i;
        for(j=i+1;j<n;j++)
        {
            if(p[mini].arrival>p[j].arrival)
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
    for(i=1;i<n;i++)
    {
        p[i].execution = p[i].burst+p[i-1].execution;
        p[i].wait = p[i-1].execution - p[i].arrival;
        p[i].time = p[i].wait+p[i].burst;
    }
    float avgtime=0.0,avgwait=0.0;
    for(i=0;i<n;i++)
    {
        avgtime+=p[i].time;
        avgwait+=p[i].wait;
    }
    avgtime /= n;
    avgwait /= n;

    cout<<"\n\nProc\t|Arr\t|Burst\t|Wait\t|Exec\t|Time\n";
    for(i=0;i<n;i++)
    {
        cout<<p[i].ID<<"\t|"<<p[i].arrival<<"\t|"<<p[i].burst<<"\t|"<<p[i].wait<<"\t|"<<p[i].execution<<"\t|"<<p[i].time;
        cout<<endl;
    }
    cout<<"\n\nAvg Total Time: "<<avgtime;
    cout<<"\nAvg Wait Time: "<<avgwait;
    return 0;
}
