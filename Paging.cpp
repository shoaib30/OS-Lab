#include<iostream>
#define MAX 50
using namespace std;

int main()
{
    int page[MAX],i,n,f,ps,off,pno;
    cout<<"\nEnter the no of pages in memory";
    cin>>n;
    cout<<"\nEnter page size";
    cin>>ps;
    cout<<"\nEnter no of frames";
    cin>>f;
    for(i=0;i<n;i++)
        page[i]=-1;
    cout<<"\nEnter the page table\n";
    cout<<"(Enter frame no as -1 if that page is not present in any frame)\n";
    cout<<"\npageno\tframeno\n-------\t-------";
    for(i=0;i<n;i++)
    {
        cout<<"\n"<<i<<"\t\t";
        cin>>page[i];
    }
    cout<<"\n\nEnter the logical address(i.e,page no & offset):";
    cin>>pno>>off;
    if(page[pno]==-1)
        cout<<"\n\nThe required page is not available in any of frames";
    else
    {
        cout<<"\n\nPhysical address(i.e,frame no & offset): "<<page[pno]<<" , "<<off<<"\n";
        cout<<"it maps to "<<page[pno]*ps+off<<" \n";
    }
    return 1;
}
