#include<iostream>
#include<stdio.h>
using namespace std;

struct process
{
    int burst,arrival,priority,remaining,ID;
    int execution,wait,tTime;
};
int main()
{

    int i,numberOfProcesses,remainingProcesses, highestPriorityProcess;
    cout<<"Enter number of processes: ";
    cin>>numberOfProcesses;
    process p[numberOfProcesses + 1];
    cout<<"Enter Arrival time, Burst time and priority of each process: \n";
    for(i=0; i<numberOfProcesses; i++)
    {
        p[i].ID = i;
        cout<<"\nProcess:"<<i;
        cout<<"\nBurst Time:";
        cin>>p[i].burst;
        cout<<"Arrival Time: ";
        cin>>p[i].arrival;
        cout<<"Priority: ";
        cin>>p[i].priority;
        p[i].remaining = p[i].burst;
    }
    p[numberOfProcesses].priority = 100;
    for(int elapsedTime = 0,remainingProcesses = numberOfProcesses; remainingProcesses != 0; elapsedTime++)
    {
        highestPriorityProcess = numberOfProcesses; //assuming last process has highest priority(100)
        for(i = 0; i < numberOfProcesses; i++)
        {
            if(p[i].arrival <= elapsedTime && p[i].remaining > 0 && p[highestPriorityProcess].priority > p[i].priority)
            {
                highestPriorityProcess = i;
            }
        }
        if(highestPriorityProcess != numberOfProcesses)
        {
            p[highestPriorityProcess].remaining -= 1;
            if(p[highestPriorityProcess].remaining == 0)
            {
                p[highestPriorityProcess].execution = elapsedTime + 1;
                p[highestPriorityProcess].wait = p[highestPriorityProcess].execution - p[highestPriorityProcess].arrival - p[highestPriorityProcess].burst;
                p[highestPriorityProcess].tTime = p[highestPriorityProcess].execution - p[highestPriorityProcess].arrival;
                remainingProcesses--;
            }
        }
    }
    float avgtime=0.0,avgwait=0.0;
    for(i=0;i<numberOfProcesses;i++)
    {
        avgtime+=p[i].tTime;
        avgwait+=p[i].wait;
    }
    avgtime/=numberOfProcesses;
    avgwait/=numberOfProcesses;
    cout<<"\n\nProc\t|Prior\t|Arri\t|Burst\t|Wait\t|Time\n";
    for(i=0;i<numberOfProcesses;i++)
    {
        cout<<p[i].ID<<"\t|"<<p[i].priority<<"\t|"<<p[i].arrival<<"\t|"<<p[i].burst<<"\t|"<<p[i].wait<<"\t|"<<p[i].tTime;
        cout<<endl;
    }
    cout<<"\n\nAvg Total Time: "<<avgtime;
    cout<<"\nAvg Wait Time: "<<avgwait;
    return 0;
}
