#include<iostream>
using namespace std;

struct page
{
    int frameID = -1;
};

int main()
{
    int numberOfFrames,sizeOfPage,numberOfPages,pageNumber,offset;
    cout<<"Enter the number of frames: ";
    cin>>numberOfFrames;
    cout<<"Enter number of pages: ";
    cin>>numberOfPages;
    cout<<"Enter the size of a page";
    cin>>sizeOfPage;
    page p[numberOfPages];
    cout<<"Enter the page table: (-1 if page is not in a frame)\n";
    cout<<"\nPageNumber\tFrameNumber\n";
    for(int i = 0; i<numberOfPages; i++)
    {
        cout<<"\t"<<i+1<<"\t\t";
        cin>>p[i].frameID;
    }
    cout<<"\nEnter the page number of the required page: ";
    cin>>pageNumber;
    pageNumber--;
    cout<<"\nEnter the offset: ";
    cin>>offset;
    if(offset > sizeOfPage)
        cout<<"\n\nOut of bound";
    else if(p[pageNumber].frameID == -1)
        cout<<"\n\nPage not in memory";
    else
        cout<<"\nLogical Address = "<<pageNumber+1<<":"<<offset<<"\nPhysical Address = "<<p[pageNumber].frameID*sizeOfPage + offset;
    return 0;



}
