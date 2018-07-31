#include<iostream>

using namespace std;

class block
{
    private:
        int blockSize,ID;
        bool used;
        int fileID,fileSize;

    public:
        block() {
            used = false;
            fileID = 0;
            fileSize = 0;
            blockSize = 0;
        }
        void setSize(int x) {
            blockSize = x;
        }
        void setID(int x)  {
            ID = x;
        }
        int getSize(){
            return this->blockSize;
        }
        void insertFile(int ID,int Size)    {
            this->fileID = ID;
            this->fileSize = Size;
            this->used = true;
        }
        bool isUsed()
        {return used;}
        void disp() {
            for (int i = 0; i<blockSize; i++)   {
                cout<<"|";
                if(i<fileSize)
                    cout<<fileID;
                else
                    cout<<" ";
                cout<<"|  ";
            }
        }
        void clearBlock()   {
            used = false;
            fileID = 0;
            fileSize = 0;
        }
};
class memory
{
    private:
        block *mem;
        int numberOfBlocks;
    public:
        memory(int n)   {
            mem = new block[n];
            numberOfBlocks = n;
        }
        void setBlockSizes()    {
            cout<<"\nEnter block sizes:-\n";
            int x;
            for(int i = 0; i < numberOfBlocks; i++)  {
                cout<<"Block "<<i+1<<" : ";
                cin>>x;
                mem[i].setSize(x);
                mem[i].setID(i);
            }
        }
    private:
        int findEmptyBlocks(int remaining[],int Size)    {
            int j=0;
            for(int i = 0; i < numberOfBlocks; i++)   {
                if(!mem[i].isUsed() && mem[i].getSize() >= Size)
                    remaining[j++] = i;
            }
            return j;
        }
        int insertPos(int ch, int Size)   {
            int remaining[numberOfBlocks],rem;
            rem = findEmptyBlocks(remaining,Size);
            if(rem != 0)    {
                if(ch == 0)
                    return remaining[0];
                int temp = 0;
                for(int i = 1; i < rem; i++)    {
                    if(mem[remaining[i]].getSize() < mem[remaining[temp]].getSize() && ch == 1)    {
                        temp = i;
                    }
                    else if(mem[remaining[i]].getSize() > mem[remaining[temp]].getSize() && ch == 2)    {
                        temp = i;
                    }
                }
                return remaining[temp];
            }
            else
                return -1;
        }
    public:
        void fit(int ch,int ID, int fileSize)    {
            int pos = insertPos(ch,fileSize);
            if(pos == -1)   {
                cout<<"\nSpace Not Available\n";
                return;
            }
            mem[pos].insertFile(ID,fileSize);
            cout<<"\nFile inserted at block : "<<pos+1<<endl;
        }
        void dispMemory()   {
            cout<<"\nMemory: \n";
            for(int i = 0; i< numberOfBlocks; i++)  {
                cout<<"\nBlock: "<<i+1<<" : ";
                mem[i].disp();
            }
            cout<<endl;
        }
        void clearMemory()  {
            for(int i = 0; i< numberOfBlocks; i++)  {
                mem[i].clearBlock();
            }
            cout<<"\nCleared Memory: \n";
        }
};

int main()
{
    int n,ch,ID,fileSize;
    cout<<"Enter the numbe of blocks in memory: ";
    cin>>n;
    memory m(n);
    m.setBlockSizes();
    while(true)
    {
        cout<<"Choice: \n1.Insert using First Fit\n2.Insert using Best Fit\n3.Insert using Worst Fit\n4.Display Memory\n5.Flush Memory\n6.EXIT\n";
        cin>>ch;
        cout<<endl;
        if(ch == 1 || ch == 2 || ch == 3){
            cout<<"Enter file ID: ";
            cin>>ID;
            cout<<"Enter file Size: ";
            cin>>fileSize;
        }
        switch(ch)  {
            case 1:
                m.fit(0,ID,fileSize);
                break;
            case 2:
                m.fit(1,ID,fileSize);
                break;
            case 3:
                m.fit(2,ID,fileSize);
                break;
            case 4:
                m.dispMemory();
                break;
            case 5:
                m.clearMemory();
                break;
            case 6:
                return 0;
                break;
            default:
                cout<<"Enter correct choice";
                break;
        }
    }
    return 0;
}
