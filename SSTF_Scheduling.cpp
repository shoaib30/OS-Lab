#include<iostream>
#include<cmath>

using namespace std;

struct mem
{
    int ID,loc,time,flag;
}memQueue[100];

int sizes=0;

void setSeekTime(int head)  {
    for(int i = 0; i < sizes; i++)  {
        if(memQueue[i].flag == false)   {
            memQueue[i].time = abs(head-memQueue[i].loc);
        }
    }
}

int findShortestSeek()  {
    int remaining[sizes],j=0;
    for(int i = 0; i < sizes; i++)  {
        if(!memQueue[i].flag)   {
            remaining[j++] = i;
        }
    }
    int mini = remaining[0];
    for(int i = 1; i < j; i++)  {
        if(memQueue[remaining[i]].time < memQueue[mini].time)
            mini = remaining[i];
    }
    return mini;
}

int main()
{
    int i,pos,head,seekTime=0;
    cout<<"Enter the size of Queue : ";
    cin>>sizes;
    cout<<"Enter the Queue: ";
    for(i = 0; i < sizes ; i++) {
        memQueue[i].flag = false;
        memQueue[i].ID = i;
        cin>>memQueue[i].loc;
    }
    cout<<"Enter the Head initial position: ";
    cin>>head;
    int order[sizes];
    for(i = 0 ; i < sizes; i ++)    {
        setSeekTime(head);
        pos = findShortestSeek();
        seekTime  += memQueue[pos].time;
        memQueue[pos].flag = true;
        order[i]=pos;
        head = memQueue[pos].loc;
    }
    cout<<"Order of head movement: ";
    for(i = 0; i < sizes; i++)  {
        cout<<memQueue[order[i]].loc<<"("<<memQueue[order[i]].ID<<")->";
    }
    cout<<"\b\b..\nTotal Seek Time: "<<seekTime;
    return 0;
}
