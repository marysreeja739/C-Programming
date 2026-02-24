#include<iostream>
#include<string>
using namespace std;
class Bird
{
   public:
      int years;
      Bird(int y)
      {
         years=y;
      }
};
class Mammal
{
   public:
      string place;
      Mammal(string p)
      {
         place=p;
      }
};
class Bat:public Bird,public Mammal
{
   public:
      string breed;
      Bat(int y,string p,string b):Bird(y),Mammal(p)
      {
        breed=b;
      }
      void display()
      {
         cout<<"Breed:"<<breed<<"\n"<<"Years:"<<years<<"\n"<<"Place:"<<place<<"\n";
      }
};
int main()
{
   Bat b(1,"land","bat");
   b.display();
   Bat b1(2,"Land","yoshi");
   b1.display();
   return 0;
}
