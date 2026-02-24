#include<iostream>
using namespace std;
class posinteger
{
   private:
      int value;
   public:
      posinteger(int v=1)
      {
         if(v>0)
         {
            value=v;
         }
         else
         {
            cout<<"Invalid entry, the number is negative\n";
            value=1;
         }
      }
      operator int()
      {
         return value;
      }
      void print()
      {
         cout<<"Positive integer value:"<<value<<"\n";
      }
};
int main()
{
   posinteger pos(10);
   pos.print();
   posinteger posi(-5);
   int primitive=(int)posi;
   int primitive2=(int)pos;
   cout<<"Primitive integer for -5:"<<primitive<<endl;
   cout<<"Primitive integer for 10:"<<primitive2<<endl;
   return 0;
}
