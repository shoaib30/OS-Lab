#include<iostream>

using namespace std;
class memory
{
    private:
        int *frames,numberOfFrames;
        int head,pageFaults;
    public:
        memory(int Size)
        {
            frames = new int[Size];
            numberOfFrames = Size;
            head = 0;
            pageFaults = 0;
            for(int i = 0;i < Size; i++)
                frames[i] = 0;
        }
    private:
        bool pageExists(int x)
        {
            for(int i = 0; i < numberOfFrames; i++)
                if(frames[i] == x)
                    return true;
            return false;
        }
        void dispMemory()
        {
            for(int i = 0; i < numberOfFrames; i++)
                cout<<frames[i]<<"|";
            cout<<endl;
        }
    public:
        void insertPage(int x)
        {
            if(!pageExists(x))
            {
                frames[head] = x;
                ++head %= numberOfFrames;
                pageFaults++;
            }
            dispMemory();
        }
        int getPageFaults()
        {
            return pageFaults;
        }
};
int main()
{
    int n,x;
    cout<<"Enter the number of frames in memory: ";
    cin>>n;
    memory m(n);
    cout<<"Enter the number of pages to be inserted: ";
    cin>>n;
    int pages[n],i;
    cout<<"Enter the page numbers in the required order: ";
    for(i = 0;i < n; i++)
    {
        cin>>pages[i];
    }
    for(i = 0;i < n;i++)
    {
        cout<<pages[i]<<" - ";
        m.insertPage(pages[i]);
    }
    cout<<"\n\nNumber of page faults : "<<m.getPageFaults();
    return 0;
}
