#include<iostream>
#include<string>
using namespace std;
void asc(int* a,int n)
{
   int i,j;
   for(i=0;i<n-1;i++)
   {
      for(j=i;j<n;j++)
      {
         if(a[j]>a[i])
         {
            int temp;
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
         }
      }
   }
}
int main()
{
   int i,n;
   cout<<"enter the size:";
   cin>>n;
   int *arr = new int[n];
   for(i=0;i<n;i++)
   {
      cout<<"enter the number:";
      cin>>arr[i];
   }
   asc(arr,n);
   for(i=0;i<n;i++)
   {
      cout<<arr[i]<<"\t";
   }
   return 0;
}
