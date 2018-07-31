#include<iostream>

using namespace std;
#define memSize 20
#define numberOfFiles 20
struct file
{
    int fileID, len, location;
    bool used = false;
}files[numberOfFiles];

int bVector[memSize];
int fileHead = -1;

void allocate()
{
    int ID,len,availSize,startLoc,j;
    cout<<"Enter the fileID: ";
    cin>>ID;
    cout<<"Enter file size: ";
    cin>>len;
    for(int i=0; i < memSize; i++ )
    {
        availSize = 0;
        if(bVector[i] == 0)
        {
            startLoc = i;
            for( j = i; !bVector[j] && j<memSize; j++)
                availSize++;
            if(availSize >= len)
                    break;
            i += availSize;
            continue;
        }
    }
    if(availSize < len)
    {
        cout<<len<< " contigious spaces not available";
        return;
    }
    files[++fileHead].fileID = ID;
    files[fileHead].len = len;
    files[fileHead].location = startLoc;
    files[fileHead].used = true;
    for(int i = startLoc; i <startLoc+len; i++)
        bVector[i] = 1;
}

void deallocate()
{
    int ID,loc = 0,len= 0;
    cout<<"Enter File ID to deallocate: ";
    cin>>ID;
    for(int i = 0; i <= fileHead; i++)
    {
        if(files[i].fileID == ID)
        {
            loc = files[i].location;
            len = files[i].len;
            files[i].used = false;
            break;
        }
    }
    for(int i = loc; i < loc+len; i++)
        bVector[i]=0;
}

void disp()
{
    cout<<"FileID|\tLoc|\tLength\n";
    for(int i = 0; i <= fileHead; i++)
    {
        if(files[i].used)
            cout<<files[i].fileID<<"|\t"<<files[i].location<<"|\t"<<files[i].len<<"\n";
    }

}


int main()
{
    int ch;
    while (true)
    {
        cout<<"BitVector: ";
        for(int i=0;i<memSize; i++)
            cout<<bVector[i]<<" ";
        cout<<"\nChoice:\n1.Allocate\n2.Deallocate\n3.Display\n4.Exit\n";
        cin>>ch;
        switch(ch)
        {
            case 1:
                allocate();
                break;
            case 2:
                deallocate();
                break;
            case 3:
                disp();
                break;
            case 4:
                return 0;
                break;
            default:
                cout<<"\nWrong Input";
                break;
        }
    }
}
