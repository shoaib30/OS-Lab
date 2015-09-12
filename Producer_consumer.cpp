#include <iostream>

using namespace std;

void disp(int n, int stacks[])
{
    if(n==0)
    {
        cout<<"Stack Empty";
    }
    for(int i=1;i<=n;i++)
    {
        cout<<stacks[i]<<",";
    }
    cout<<endl;
}

int main()
{
    int n,ch,c1=0,c2=0,prod[25],cons[25],x;
    cout<<"Enter size of stack :";
    cin>>n;
    while(true)
    {
        cout<<"\nProducer stack (size: "<<c1<<") : ";
        disp(c1,prod);
        cout<<"Consumer stack (size: "<<c2<<") : ";
        disp(c2,cons);
        cout<<"\nChoice:";
        cout<<"\n1.Producer\n2.Consumer\n3.Exit\n";
        cin>>ch;
        switch(ch)
        {
            case 1:
                if(c1==n)
                {
                    cout<<"\nProducer Full. (Sleeping)";
                }
                else
                {
                    cout<<"\nEnter the process ID";
                    cin>>prod[++c1];
                }
            break;
            case 2:
                if(c2==n)
                {
                    cout<<"\nAll process consumed (Sleeping)";
                    c2=0;
                }
                else if(c1==0)
                {
                    cout<<"\nProducer Stack Empty";
                }
                else
                {
                    cons[++c2]=prod[c1--];
                    cout<<"\nOne Process Consumed";
                }
            break;
            case 3:
                return 0;
            break;
            default:
                cout<<"\nWrong Choice";
            break;
        }
    }
}
