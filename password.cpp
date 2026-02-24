#include<iostream>
#include<string>
#include<exception>
using namespace std;
void check(string pass)
{
   int count;
   count=pass.size();
   cout<<"the length is: "<<count;
   try
   {
      if(count<6)
      {
         throw(10);
      }
      else
      {
         cout<<"successful";
      }
   }
   catch(int a)
   {
      cout<<a<<"error";
      string pas;
      cout<<"enter the new password:";
      cin>>pas;
      check(pas);
   }
}
int main()
{
   string password;
   cout<<"enter the password:";
   cin>>password;
   check(password);
   return 0;
}
