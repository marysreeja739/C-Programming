#include<iostream>
using namespace std;
class ATM
{
   private:
      static int count_time;
      static int max_times;
      float balance;
   public:
      ATM(float bal)
      {
         balance=bal;
      }
      void check_balance()
      {
         if(count_time<max_times)
         {
            count_time++;
            cout<<"Current balance: "<<balance<<endl;
            cout<<"You have checked your balance: "<<count_time<<endl;
         }
         else
         {
            cout<<"You have reached the maximum number of balance check in a month"<<endl;
         }
      }
};
int ATM::count_time=0;
int ATM::max_times=5;
int main()
{
   float balance;
   cout<<"Enter the balance:";
   cin>>balance;
   ATM account(balance);
   int choice;
   do
   {
      cout<<"1.Display balance"<<endl<<"2.Exit"<<endl;
      cout<<"Enter your choice:";
      cin>>choice;
      switch(choice)
      {
         case 1:
            account.check_balance();
            break;
         case 2:
            cout<<"Exiting the program";
            break;
         default:
            cout<<"Invalid entry";
            break;
      }
   }while(choice!=2);
   return(0);
}
