#include<iostream>
#include<list>

using namespace std;

struct node
{
    int fileID;
    bool allocated = false;
};

int main()
{
    list<node> ls;
    int ch,FID,FSize;
    while(true)
    {
        cout<<"\nEnter choice: ";
        cout<<"\n1.Allocate";
        cout<<"\n2.Deallocate";
        cout<<"\n3.Display Memory";
        cout<<"\n4.Exit\n";
        cin>>ch;
        switch(ch)
        {
            case 1:
                cout<<"\nEnter file ID :";
                cin>>FID;
                cout<<"\nEnter File size: ";
                cin>>FSize;
                for(list<node>::iterator it = ls.begin() ; it!=ls.end() && FSize > 0; it++)
                {
                    if(!it->allocated)
                    {
                        it->fileID = FID;
                        it->allocated = true;
                        FSize--;
                    }
                }
                while(FSize != 0)
                {
                    node temp;
                    temp.fileID = FID;
                    temp.allocated = true;
                    ls.push_back(temp);
                    FSize--;
                }
                cout<<"\nFile Inserted into memory\n";
                break;
            case 2:
                cout<<"\nEnter fileID to deallocate: ";
                cin>>FID;
                for(list<node>::iterator it = ls.begin() ; it!=ls.end(); it++)
                {
                        if(it->fileID == FID)
                            it->allocated = false;
                }
                break;
            case 3:
                cout<<"\nMemory: ";
                for(list<node>::iterator it = ls.begin() ; it!=ls.end(); it++)
                {
                        if(it->allocated)
                            cout<<it->fileID<<"|";
                        else
                            cout<<"  |";
                }
                break;
            case 4:
                return 0;
                break;
            default:
                cout<<"\nWrong choice";
                break;
        }
    }

}
