#include<stdio.h>
#include<stdlib.h>
int mutex=1,full=5,e=0,x=0;
int main()
{
   int n;
   void producer();
   void consumer();
   int wait(int);
   int signal(int);
   printf("\n 1.Producer  \n 2.Consumer \n 3.Exit");
   while(1)
   {
      printf("\n Enter your choice:");
      scanf("%d",&n);
      switch(n)
      {
         case 1:
                 if((mutex==1)&&(full!=0))
                    producer();
                 else
                    printf("Buffer is full");
     break;
         case 2:
             if((mutex==1)&&(e!=0))
    consumer();
    else
        printf("Buffer is empty");
       break;
         case 3:
    exit(0);
    break;
      }
   }
}
int wait(int s)
{
   return (--s);
}
int signal(int s)
{
   return(++s);
}
void producer()
{
   mutex=wait(mutex);
   e=signal(e);
   full=wait(full);
   x++;
   printf("\n Producer produces the item %d",x);
   mutex=signal(mutex);
}
void consumer()
{
   mutex=wait(mutex);
   e=wait(e);
   full=signal(full);
   printf("\n Consumer consumes item %d",x);
   x--;
   mutex=signal(mutex);

 }
