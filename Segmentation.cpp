#include<iostream>
#define MAX 50
using namespace std;
int main()
{
    int base[MAX],limit[MAX],i,j,ns,seg,off;
    cout<<"Enter the number of segment";
    cin>>ns;
    cout<<"Enter the base and limit value for \n";
    for (i=0;i<ns;i++)
    {
        cout<<"\n segment "<<i<<" : ";
        cin>>base[i]>>limit[i];
    }
    cout<<"Enter the segment number and offset :";
    cin>>seg>>off;
    if (off<limit[seg])
       cout<<"The segment "<<seg<<" with offset "<<off<<" maps to physical address "<<base[seg]+off;
    else
        cout<<"The offset given is higher than the limit of the segment";
}
