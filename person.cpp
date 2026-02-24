#include<iostream>
#include<string>
using namespace std;
class Person
{
   private:
      string name;
   public:
      string gender;
      int age;
      Person(string n,string g,int a)
      {
         name=n;
         gender=g;
         age=a;
      }
      void details()
      {
         cout<<"Name:"<<name<<"\n";
         cout<<"Gender:"<<gender<<"\n";
         cout<<"Age:"<<age<<"\n";
      }
      string getname()
      {
         return name;
      }
};
class Student:public Person
{
   private:
      int year;
   public:
      string course;
      Student(string n,string g,int a,int y,string c):Person(n,g,a)
      {
         year=y;
         course=c;
      }
      void studentdetail()
      {
         cout<<"Name:"<<getname()<<"\n";
         cout<<"Gender:"<<gender<<"\n";
         cout<<"Age:"<<age<<"\n";
         cout<<"Year:"<<year<<"\n";
         cout<<"Course:"<<course<<"\n";
      }
};
int main()
{
   Student s("Naina","F",24,2,"Java");
   cout<<"Derived class Student\n";
   s.studentdetail();
   Person p("Kavya","F",25);
   cout<<"Base class Person\n";
   p.details();
   return 0;
}
