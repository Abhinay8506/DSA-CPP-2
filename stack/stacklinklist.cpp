#include <bits/stdc++.h>
using namespace std;
struct node
{
  int data;
  node *next;
};

class stacks
{
public:
  struct node *first, *en;
  int count = 0;
  int size;
  stacks(int n)
  {
    size = n;
    first = NULL;
    en = NULL;
  }
  struct node *create()
  {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    return temp;
  }
  void push(int num)
  {
    struct node *temp = create();
    if (count < size)
    {
      if (first == NULL)
      {
        first = en = temp;
        temp->data = num;
        temp->next = NULL;
      }
      else
      {
        temp->next = en->next;
        en->next = temp;
        temp->data = num;
        en = temp;
      }
      count++;
    }
    else{
      cout<<"Overflow"<<endl;
    }
  }
  void pop()
  {
    if (en != NULL)
    {
      cout << "popped elemnt:" << en->data << endl;
      if (en == first)
      {
        first = NULL;
        en = NULL;
      }
      else
      {
        struct node *t = first;
        while (t->next != en && t->next != NULL)
        {
          t = t->next;
        }
        t->next = NULL;
        en = t;
      }
      count--;
    }
    else
    {
      cout << "Underflow" << endl;
    }
  }
  void peak()
  {
    if(en!=NULL){
      cout << "peak:" << en->data << endl;
    }
    else{
      cout<<"Underflow"<<endl;
    }
  }
  bool isempty()
  {
    if (first == NULL)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  bool isfull()
  {
    if(count==size){
      return true;
    }
    return false;
  }
};
int main()
{
  int n;
  cin >> n;
  stacks s(n);
  char ch = 'Y';
  do
  {
    int m;
    cout << "1.To push" << endl
         << "2.To pop" << endl
         << "3.For peak element" << endl
         << "4.For checking empty or not" << endl
         << "5.For checking full" << endl;
    cout << "Enter your choice:";
    cin >> m;
    switch (m)
    {
    case 1:
      int item;
      cout << "enter item to push:";
      cin >> item;
      s.push(item);
      break;

    case 2:
      s.pop();
      break;
    case 3:
      s.peak();
      break;
    case 4:
      cout << s.isempty() << endl;
      break;
    case 5:
      cout << s.isfull() << endl;
      break;
    }
    cout << "do you want to continue(Y/N):";
    cin >> ch;
  } while (ch == 'Y');
  return 0;
}
