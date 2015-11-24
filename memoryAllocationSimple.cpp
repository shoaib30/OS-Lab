#include<iostream>

using namespace std;

struct block{
    int blockSize,ID;
};
void sortBlocks(block b[],int n,int sorted[],int ch)
{
    for(int i = 0; i < n; i++)
        sorted[i] = b[i].ID;
    int temp;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n-1-i; j++)
        {
            if(b[sorted[j]].blockSize > b[sorted[j+1]].blockSize && ch == 1)
            {
                temp = sorted[j];
                sorted[j] = sorted[j+1];
                sorted[j+1] = temp;
            }
            else if(b[sorted[j]].blockSize < b[sorted[j+1]].blockSize && ch == 2)
            {
                temp = sorted[j];
                sorted[j] = sorted[j+1];
                sorted[j+1] = temp;
            }
        }
    }
}
int main()
{
    int numberOfBlocks,i,numberOfProcesses,ch;
    cout<<"Enter Number of blocks: ";
    cin>>numberOfBlocks;
    block blocks[numberOfBlocks],b[numberOfBlocks];
    cout<<"Enter the Sizes of each block : \n";
    for(i = 0; i < numberOfBlocks; i++)  {
        cout<<"block : "<<i+1<<" : ";
        cin>>blocks[i].blockSize;
        blocks[i].ID = i;
    }
    cout<<"Enter the number of processes: ";
    cin>>numberOfProcesses;
    int processes[numberOfProcesses];
    cout<<"Enter the Size of each process: \n";
    for(i = 0; i < numberOfProcesses; i++)  {
        cout<<"Process: "<<i+1<<" : ";
        cin>>processes[i];
    }
    while(true)
    {
        cout<<"\n\nChoice:\n1.First fit\n2.Best Fit\n3.Worst Fit\n4.EXIT\n";
        cin>>ch;
        bool flag = false;
        int j,sorted[numberOfBlocks];
        for(i = 0;i < numberOfBlocks; i++)
        {
            b[i].blockSize = blocks[i].blockSize;
            b[i].ID = blocks[i].ID;
        }
        switch(ch)
        {
            case 1:
                for(i = 0;i < numberOfProcesses; i++){
                    flag = false;
                    for(j = 0; j < numberOfBlocks; j++){
                        if(processes[i] <= b[j].blockSize)  {
                            cout<<"\nProcess "<< i+1<<" of size "<<processes[i]<<" allocated block "<<b[j].ID<<" of size: "<<b[j].blockSize;
                            b[j].blockSize = 0;
                            flag = true;
                            break;
                        }
                    }
                    if(!flag)
                        cout<<"\nProcess "<<i+1<<" of size "<<processes[i]<<" not allocated";
                }
                break;
            case 2:
                sortBlocks(b,numberOfBlocks,sorted,1);
                for(i = 0;i < numberOfProcesses; i++){
                    flag = false;
                    for(j = 0; j < numberOfBlocks; j++){
                        if(processes[i] <= b[sorted[j]].blockSize)  {
                            cout<<"\nProcess "<< i+1<<" of size "<<processes[i]<<" allocated block "<<b[sorted[j]].ID<<" of size: "<<b[sorted[j]].blockSize;
                            b[sorted[j]].blockSize = 0;
                            flag = true;
                            break;
                        }
                    }
                    if(!flag)
                        cout<<"\nProcess "<<i+1<<" of size "<<processes[i]<<" not allocated";
                }
                break;
            case 3:
                sortBlocks(b,numberOfBlocks,sorted,2);
                for(i = 0;i < numberOfProcesses; i++){
                    flag = false;
                    for(j = 0; j < numberOfBlocks; j++){
                        if(processes[i] <= b[sorted[j]].blockSize)  {
                            cout<<"\nProcess "<< i+1<<" of size "<<processes[i]<<" allocated block "<<b[sorted[j]].ID<<" of size: "<<b[sorted[j]].blockSize;
                            b[sorted[j]].blockSize = 0;
                            flag = true;
                            break;
                        }
                    }
                    if(!flag)
                        cout<<"\nProcess "<<i+1<<" of size "<<processes[i]<<" not allocated";
                }
                break;
            case 4:
                return 0;
                break;
            default:
                cout<<"\nEnter correct value\n";
                break;
        }
    }
    return 0;
}
