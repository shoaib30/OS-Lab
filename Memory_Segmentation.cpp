#include<iostream>
using namespace std;

struct segments
{
    int base,maxLimit;
};

int main()
{
    int numberOfSegments;
    cout<<"Enter the number of segments: ";
    cin>>numberOfSegments;
    segments s[numberOfSegments];
    cout<<"Enter the base and max limit of each segment:";
    for(int i = 0; i<numberOfSegments; i++)
    {
        cout<<"\nSegment "<<i+1<<":\n";
        cout<<"Base: ";
        cin>>s[i].base;
        cout<<"Max limit: ";
        cin>>s[i].maxLimit;
        cout<<endl;
    }
    int segment,offset;
    cout<<"\nEnter the Segment number of the required segment: ";
    cin>>segment;
    segment--;
    cout<<"Enter the required offset: ";
    cin>>offset;
    if(s[segment].maxLimit >= offset)
        cout<<"\nLogical address = "<<s[segment].base<<":"<<offset<<"\nPhysical address = "<<s[segment].base+offset;
    else
        cout<<"\nOffset is out of bound";
    return 0;
}
