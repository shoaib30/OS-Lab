#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int initial,n,i,j,queues[50];
	int total=0;
	cout<<"Enter the initial position of disk head (cylinder at which head is): ";
	cin>>initial;
	cout<<"Enter the number of requests for disk access: ";
	cin>>n;
	cout<<"Enter the cylinder number to access \n";
	for(i=0; i<n; i++)
    {
    cout<<i+1<<":";
		cin>>queues[i];
	}
	total=abs(initial-queues[0]);
	for(i=0; i<n-1; i++)
	{
		total+=abs(queues[i+1]-queues[i]);
	}
	cout<<"Total head movements: "<<total;
  return 0;
}

