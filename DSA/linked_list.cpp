//Circular linked list
#include<iostream>
using namespace std;

struct node
{
  int data;
  struct node *next;
  node(int val)
  {
    data = val;
    next = nullptr;
  }
};

void insert_beg(node* &head, int data)
{
  node* newNode = new node(data);
  if(head == nullptr)
  {
    newNode->next = newNode;
    head = newNode;
    return;
  }
  node* temp = head;

  while(temp->next != head)
    temp = temp->next;

  newNode->next = head;
  temp->next = newNode;
  head = newNode;
}

void insert_end(node* &head, int data)
{
  
  node* newNode = new node(data);
  if(head == nullptr)
  {
    newNode->next = newNode;
    head = newNode;
    return;
  }
  node* temp = head;
  while(temp->next != head)
  {
    temp = temp->next;
  }
  temp->next = newNode;
  newNode->next = head;
}

void insert_lo(node* &head, int data)
{
  int pos;
  cout<<"\nEnter the position : ";
  cin>>pos;

  if(pos < 0)
  {
    cout<<"Out of Range.\n";
    return;
  }
  else if(head == NULL && pos == 1)
  {
    insert_beg(head, data);
  }
  else if(pos == 1)
  {
    insert_end(head, data);
  }
  else
  {
    node* newNode = new node(data);
    node* q = head;
    while( pos-1 > 1)
    {
      q = q->next;
      pos--;
    }
    newNode->next = q->next;
    q->next = newNode;
  }
}

void delete_beg(node* &head)
{
  struct node *q = head, *p;
  if(head == NULL)
  {
    cout<<"Empty List\n";
    return;
  }
  while(q->next != head)
    q = q->next;
  q->next = head->next;
  p = head;
  head = head->next;
  p->next = nullptr;
  free(p);
}

void delete_end(node* &head)
{
  struct node *q = head, *p = head;
  if(head == nullptr)
  {
    cout<<"Empty List\n";
    return;
  }
  while(p->next->next != head)
    p = p->next;
  q = p->next;
  p->next = head;
  q->next = nullptr;
  free(q);
}

int getlength(node* &head)
{
  struct node *q = head;
  int count = 1;
  while(q->next != head)
  {
    count++;
    q = q->next;
  }
  return count;
}

void delete_lo(node* &head)
{
  struct node *q = head, *p = head;
  int pos, l;
  l = getlength(head);
  cout<<"Enter a position : ";
  cin>>pos;
  if(head == nullptr)
  {
    cout<<"Empty List\n\n";
    return;
  }
   else if(pos == 1)
    {
      delete_beg(head);
    }
    else if(pos == l)
    {
      delete_end(head);
    }
    else if(pos > l)
    {
      cout<<"Out of Range!!!\n";
      cout<<"Total length of the list : "<<l<<endl;
      return;
    }
    else
    {
      while( pos-1 > 1)
      {
        q = q->next;
        pos--;
      }
      p = q->next;
      q->next = p->next;
      free(p);
     }
  }

void reverse(node* &head)
{
  struct node *q = head, *p = nullptr, *n = head;

  if(!head || head->next == head)
  {
    cout<<"Empty List\n\n";
    return;
  }
  else
  {
    do{
      n = q->next;
      q->next = p;
      p = q;
      q = n;
    }while(q != head);

    n->next = p;
    head = p;
  }
}

void display(node* &head)
{
    if (head == nullptr)   // case 1: empty list
    {
        cout << "List is empty.\n";
        return;
    }

    node* q = head;
    while(q->next != head)
    {
      cout<<q->data<<"\t->\t";
      q = q->next;
    }
    cout<<q->data<<"\n\n";  // makes it clear it’s circular
}


int main()
{
  int choice;
  struct node* head = nullptr;
  while(1)
  {
    
    int data;
    cout<<"Enter your choice : ";
    cin>>choice;
    switch(choice)
    {
      case 1: cout<<"\nInsertion at the beginning :- \n\n";
              cout<<"Enter a data : ";
              cin>>data;
              insert_beg(head, data);
              break;
           
      case 2: cout<<"\nInsertion at the end :- \n\n";
              cout<<"Enter a data : ";
              cin>>data;
              insert_end(head, data);
              break;
      
      case 3: cout<<"\nInsertion at a particular location :- \n\n";
              cout<<"Enter a data : ";
              cin>>data;
              insert_lo(head, data);
              break;
      
      case 4: cout<<"\nDeletion at the beginning :- \n\n";
              delete_beg(head);
              break;
          
      case 5: cout<<"\nDeletion at the end :- \n\n";
              delete_end(head);
              break;
              
      case 6: cout<<"\nDeletion at a particular location :- \n\n";
              delete_lo(head);
              break;
             
      case 7: display(head);
              break;
              
      case 8: cout<<"\nReverse :- \n";
              reverse(head);
              display(head);
              break;

      case 9: exit(1);
      default: cout<<"\nINVALID!!!";
    }
  }
  return 0;
}
