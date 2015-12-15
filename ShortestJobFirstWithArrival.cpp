#include<iostream>
using namespace std;

struct process
{
    int arrival,burst;
    int wait,execution,time,ID;
    bool arrived = false;
};
int elapsedTime = 0;

void updateArrived(process arrived[], process p[], int &numberOfProcesses, int &numberArrived)
{
    for(int i = 0; i < numberOfProcesses; i++)  {
        if(!p[i].arrived && p[i].arrival <= elapsedTime)
        {
            p[i].arrived = true;
            arrived[numberArrived++] = p[i];
        }
    }
}

void findShortestJob(process arrived[],int numberArrived, int processPointer)
{
    int shortest = processPointer;
    process temp;
    for(int j = processPointer + 1; j < numberArrived; j++)
        if(arrived[j].burst < arrived[shortest].burst)
            shortest = j;
    if(shortest!=processPointer)
    {
        temp=arrived[processPointer];
        arrived[processPointer]=arrived[shortest];
        arrived[shortest]=temp;
    }
}

int main()
{
    cout<<"Enter Number of processes: ";
    int numberOfProcesses,i,mini,j,numberArrived = 0, processPointer = 0;
    cin>>numberOfProcesses;
    process p[numberOfProcesses],temp, arrived[numberOfProcesses];
    cout<<"Enter the Burst Time and Arrival time:-\n";
    for(i=0;i<numberOfProcesses;i++)
    {
        p[i].ID=i;
        cout<<"\nProcess:"<<i;
        cout<<"\nBurst Time:";
        cin>>p[i].burst;
        cout<<"Arrival Time: ";
        cin>>p[i].arrival;
    }
    while((numberOfProcesses - processPointer) != 0)
    {
        updateArrived(arrived,p,numberOfProcesses,numberArrived);
        if(processPointer != numberArrived)
        {
            findShortestJob(arrived,numberArrived,processPointer);
            arrived[processPointer].wait = elapsedTime - arrived[processPointer].arrival;
            elapsedTime += arrived[processPointer].burst;
            arrived[processPointer].execution = elapsedTime;
            arrived[processPointer].time = arrived[processPointer].burst + arrived[processPointer].wait;
            processPointer++;
        }
        else
            elapsedTime++;
    }

    float avgtime=0.0,avgwait=0.0;
    for(i=0;i<numberOfProcesses;i++)
    {
        avgtime+=arrived[i].time;
        avgwait+=arrived[i].wait;
    }
    avgtime/=numberOfProcesses;
    avgwait/=numberOfProcesses;
    cout<<"\n\nProc\t|Burst\t|Wait\t|Exec\t|Time\n";
    for(i=0;i<numberOfProcesses;i++)
    {
        cout<<arrived[i].ID<<"\t|"<<arrived[i].burst<<"\t|"<<arrived[i].wait<<"\t|"<<arrived[i].execution<<"\t|"<<arrived[i].time;
        cout<<endl;
    }
    cout<<"\n\nAvg Total Time: "<<avgtime;
    cout<<"\nAvg Wait Time: "<<avgwait;
    return 0;
}
