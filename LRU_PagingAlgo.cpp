#include<iostream>

using namespace std;
class frame
{
    private:
        int age,page;
        bool status;
    public:
        frame()
        {
            page = -1;
            age = 999;
            status = false;
        }
        bool isUsed()   {
            return status;
        }
        void oneCycle() {
            age++;
        }
        void resetAge() {
            age = 0;
        }
        int getAge()    {
            return age;
        }
        void setFrame(int x)    {
            page = x;
            resetAge();
            status = true;
        }
        int getFrame()  {
            return page;
        }
};
class memory
{
    private:
        int numberOfFrames;
        int head,pageFaults;
        frame *frames;
    public:
        memory(int Size)
        {
            frames = new frame[Size];
            numberOfFrames = Size;
            head = 0;
            pageFaults = 0;
        }
    private:
        bool pageExists(int x)
        {
            for(int i = 0; i < numberOfFrames; i++) {
                if(frames[i].getFrame() == x){
                    frames[i].resetAge();
                    return true;
                }
            }
        }
        void dispMemory()
        {
            for(int i = 0; i < numberOfFrames; i++)
                cout<<frames[i].getFrame()<<"|";
            cout<<endl;
        }
        void oneCycle()
        {
            for(int i = 0; i < numberOfFrames; i++)
                frames[i].oneCycle();
        }
        int findLeastRecentlyUsed()
        {
            int i,oldest = 0;
            for(i = 0; i < numberOfFrames; i++) {
                if(!frames[i].isUsed())
                    return i;
                if(frames[oldest].getAge() < frames[i].getAge())
                    oldest = i;
            }
            return oldest;
        }
    public:
        void insertPage(int x)
        {
            if(!pageExists(x))
            {
                head = findLeastRecentlyUsed();
                frames[head].setFrame(x);
                pageFaults++;
            }
            oneCycle();
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

