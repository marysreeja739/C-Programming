#include<iostream>
#include<exception>
#include<string>
#include<cstdlib>
using namespace std;
class Myexception
{
   private:
      int err;
      string errmsg;
   public:
      void show()
      {
         cout << "Error " << err << ": " << errmsg << endl;
      }
      Myexception(int x, string s)
      {
         err = x;
         errmsg = s;
      }
};

struct node
{
   int data;
   struct node* next;
};

class linkedlist
{
   private:
      struct node* head;
   public:
      linkedlist()
      {
         head = NULL;
      }

      void insert(int elt) throw(int,Myexception)
      {
         try
         {
            if (elt < 0)
            {
               throw 10;
            }

            struct node* current = head;
            while (current != NULL)
            {
               if (current->data == elt)
               {
                  Myexception m(1, "duplicate");
                  throw(m);
               }
               current = current->next;
            }
            struct node* newnode = new node;
            newnode->data = elt;
            newnode->next = NULL;

            if (!head)
            {
               head = newnode;
            }
            else
            {
               current = head;
               while (current->next != NULL)
               {
                  current = current->next;
               }
               current->next = newnode;
            }
         }
         catch (Myexception& e)
         {
            e.show();
            throw;
         }
      }

      void deleteing(int elt) throw(char)
      {
         try
         {
            if (head == NULL)
            {
               throw('E');
            }

            struct node* current = head;
            struct node* prev = NULL;
            bool found = false;
            int count = 0;

            while (current != NULL)
            {
               if (current->data == elt)
               {
                  found = true;
                  count++;
                  if (prev != NULL)
                  {
                     prev->next = current->next;
                  }
                  else
                  {
                     head = current->next;
                  }

                  struct node* temp = current;
                  current = current->next;
                  delete temp;
               }
               else
               {
                  prev = current;
                  current = current->next;
               }
            }

            if (!found)
            {
               throw('A');
            }

            if (count > 1)
            {
               Myexception m2(2, "Occurrence is high");
               throw(m2);
            }
         }
         catch (Myexception& e)
         {
            e.show();
         }
      }

      void display() throw(float)
      {
         try
         {
            if (head == NULL)
            {
               cout << "Empty list" << endl;
               throw(0.01f);
            }

            struct node* current = head;
            cout << "Linked list: ";
            while (current != NULL)
            {
               cout << current->data << " -> ";
               current = current->next;
            }
            cout << "NULL" << endl;
         }
         catch (float f)
         {
            cout << f << " empty list display error" << endl;
         }
      }

      ~linkedlist()
      {
         struct node* current = head;
         while (current != NULL)
         {
            struct node* temp = current;
            current = current->next;
            delete temp;
         }
      }
};

int main()
{
   linkedlist list;
   int choice, element;

   do
   {
      cout << "1. Insert\n2. Delete\n3. Display\n4. Exit" << endl;
      cout << "Enter your choice: ";
      cin >> choice;

      try
      {
         switch (choice)
         {
            case 1:
               cout << "Enter the element: ";
               cin >> element;
               list.insert(element);
               break;

            case 2:
               cout << "Enter the element to delete: ";
               cin >> element;
               list.deleteing(element);
               break;

            case 3:
               list.display();
               break;

            case 4:
               cout << "Exiting the program" << endl;
               break;

            default:
               cout << "Invalid choice" << endl;
               break;
         }
      }
      catch (int a)
      {
         cout << a << " negative error" << endl;
      }
      catch (float a)
      {
         cout << a << " empty list display error" << endl;
      }
      catch (Myexception& e)
      {
         cout << "One level higher" << endl;
         exit(1);
      }
      catch (char c)
      {
         cout << c << " empty list for deleting" << endl;
      }
      catch (...)
      {
         cout << "Catch all block" << endl;
      }
   } while (choice != 4);

   return 0;
}
