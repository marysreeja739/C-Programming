#include<iostream>
#include<string>
using namespace std;
class pendrive
{
   private:
      int id;
      int memory;
      string company;
      int price;
      string data;
   public:
      pendrive(int i,int m,string c,int p)
      {
         id=i;
         memory=m;
         company=c;
         price=p;
      }
      void upload_data(string newdata);
      void print()
      {
         cout<<"ID:"<<id<<endl;
         cout<<"Memory Capacity:"<<memory<<endl;
         cout<<"Company:"<<company<<endl;
         cout<<"Price:"<<price<<endl;
         cout<<"Data:"<<data<<endl;
      }
};
void pendrive::upload_data(string newdata)
{
   data+=newdata;
}
int main()
{
   pendrive pd(102,32,"HP",300);
   pd.upload_data("document,");
   pd.upload_data("movies");
   pd.print();
   return (0);
}
