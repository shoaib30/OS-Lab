#include<iostream>
using namespace std;

struct process  {
    int allocation[5], maximum[5], need[5],available[5];
    int flag = 0,ID;
};

int main()  {
    int n,r,i,j,k,res_count = 0,pros_count = 0;
    cout<<"Enter the number of processes running: ";
    cin>>n;
    cout<<"Enter the number of resources (<5): ";
    cin>>r;
    process p[n];
    int avail[r],sequence[n];
    cout<<"Enter the Allocation & Maximum matrix :\n";
    for(i = 0; i < n; i++)  {
        p[i].ID = i+1;
        cout<<"\nProcess :"<<p[i].ID;
        cout<<"\nAllocation :-\n";
        for(j = 0; j < r; j++)  {
            cout<<"Resource: "<<j+1<<" : ";
            cin>>p[i].allocation[j];
        }
        cout<<"Maximum :-\n";
        for(j = 0; j < r; j++)  {
            cout<<"Resource: "<<j+1<<" : ";
            cin>>p[i].maximum[j];
        }
    }
    cout<<"\nEnter the number of available instances of each resource: \n";
    for(j = 0; j < r; j++)  {
        cout<<"Resource: "<<j+1<<" : ";
        cin>>avail[j];
    }
    //calculating need matrix
    for(i = 0; i < n; i++) {
        for(j = 0; j < r; j++)
            p[i].need[j] = p[i].maximum[j] - p[i].allocation[j];
    }
    //printing matrices
    cout<<"\nALLOC\tMAX\tNEED\n";
    for(i = 0; i < n; i++) {
        for(j = 0; j < r; j++)
            cout<<p[i].allocation[j]<<",";
        cout<<"\t";
        for(j = 0; j < r; j++)
            cout<<p[i].maximum[j]<<",";
        cout<<"\t";
        for(j = 0; j < r; j++)
            cout<<p[i].need[j]<<",";
        cout<<endl;
    }
    for(k = 0; k < n; k++)  {
        for(i = 0; i < n; i++) {
            if(p[i].flag == 0)  {
                res_count = 0;
                for(j = 0; j < r; j++)  {
                    if(avail[j] >= p[i].need[j])
                        res_count++;
                }
                if(res_count == r)  {
                    sequence[pros_count++] = p[i].ID;
                    p[i].flag = 1;
                    for(j = 0; j < r; j++)  {
                        avail[j] = avail[j] + p[i].allocation[j];
                        p[i].available[j] = avail[j];
                    }
                    break;
                }
            }
        }
    }
    if(pros_count != n) {
        cout<<"\nUNSAFE STATE!";
        return 0;
    }
    if(pros_count == n) {
        cout<<"\nSAFE STATE";
        cout<<"\nSequence: ";
        for( i = 0; i < n; i++)
            cout<<sequence[i]<<",";
        cout<<"\nAvailable Matrix: ";
        for( i = 0; i < r; i++)
            cout<<avail[i]<<",";
        cout<<endl;
        cout<<"\nALLOC\tMAX\tNEED\tAVAIL\n";
         for(i = 0; i < n; i++) {
            for(j = 0; j < r; j++)
                cout<<p[i].allocation[j]<<",";
            cout<<"\t";
            for(j = 0; j < r; j++)
                cout<<p[i].maximum[j]<<",";
            cout<<"\t";
            for(j = 0; j < r; j++)
                cout<<p[i].need[j]<<",";
            cout<<"\t";
            for(j = 0; j < r; j++)
                cout<<p[i].available[j]<<",";
            cout<<endl;
        }
    }
    return 0;
}
