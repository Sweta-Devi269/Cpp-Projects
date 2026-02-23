/*Doubly Linked List */
#include<iostream>
using namespace std;

struct node
{
  int data;
  struct node *prev, *next;
  node(int val)
  {
    data = val;
    prev = nullptr;
    next = nullptr;
  }
};

void insert_beg(node* &head, int data)
{
  struct node *temp = new node(data);
  struct node *q = head;
  if(head == nullptr)
  {
    head = temp;
    temp->next = temp;
    return;
  }
  while(q->next != head)
    q = q->next;
  
  temp->next = head;
  q->next = temp;
  head->prev = temp;
  head = temp;

}

void insert_end(node* &head, int data)
{
  struct node *temp = new node(data), *q = head;
  
  if(head == nullptr)
  {
    insert_beg(head, data);
  }
  else
  {
    while(q->next != head)
      q = q->next;
    temp->prev = q;
    temp->next = head;
    q->next = temp;
    
  }
}

int getlength(node* &head)
{
  struct node *q = head;
  int count = 1;
  do
  {
    count++;
    q = q->next;
  }while(q != head);

  return count;
  
}

void insert_lo(node* &head, int data)
{
  struct node *q = head;
  int pos, l;
  cout<<"\nEnter the position : ";
  cin>>pos;

  if(pos == 1)
  {
    insert_beg(head, data);
    return;
  }

  l = getlength(head);
  if(pos > l)
  {
    cout<<"\nOut of Range!!!!";
    return;
  }
  else if(pos == l)
  {
    insert_end(head, data);
  }
  else
  {
    struct node *temp = new node(data);
    while( pos-1 > 1)
    {
      q = q->next;
      pos--;
    }
    temp->next = q->next;
    temp->prev = q;
    (q->next)->prev = temp;
    q->next = temp;
  }
}

void delete_beg(node* &head)
{
  struct node *q = head, *p = head;
  if(head == nullptr)
  {
    cout<<"\nEmpty List\n\n";
    return;
  }
  else
  {
    while(q->next != head)
      q = q->next;
    
    q->next = p->next;
    (p->next)->prev = nullptr;
    head = p->next;
    p->next = nullptr;
    free(p);
  }
}

void delete_end(node* &head)
{
  struct node *q = head, *p;
  if(head == nullptr)
  {
    cout<<"\nEmpty List\n\n";
    return;
  }
  else
  {
    while(q->next != head)
      q = q->next;
    
      p = q->prev;
      p->next = head;
      q->next = nullptr;
      q->prev = nullptr;
      free(q);
  }

}

void delete_lo(node* &head)
{
  struct node *q = head, *n;
  int pos, l;
  cout<<"\nEnter a position : ";
  cin>>pos;

  if(pos == 1)
  {
    delete_beg(head);
    return;
  }
  l = getlength(head);

  if(pos > l)
  {
    cout<<"Out of Range!!!!\n";
    return;
  }
  else if(pos == l)
  {
    delete_end(head);
    return;
  }
  else
  {
    while(pos-1 > 0)
    {
      q = q->next;
      pos--;
    }
    n = q->next;
    (q->prev)->next = n;
    n->prev = q->prev;
    q->next = nullptr;
    q->prev = nullptr;
    free(q);
  }
}

void reverse(node* &head)
{
  struct node *q = head, *p = nullptr;
  if(head == nullptr)
  {
    cout<<"Empty list!!!\n";
    return;
  }
  else
  {
    do
    {
      p = q->prev;
      q->prev = q->next;
      q->next = p;
      q = q->prev;
    } while (q != head);
    
    if(p != head)
      head = p->prev;
  }

}

void display(node* &head)
{
  struct node *q = head;
  while(q->next != head)
  {
    cout<<q->data<<"\t->\t";
    q = q->next;
  }
  cout<<q->data<<"\t->\tEND\n"<<endl;
}

main()
{
  int choice, data;
  struct node *head = nullptr;
  while(1)
  {
    cout<<"Enter your choice : ";
    cin>>choice;
    switch(choice)
    {
      case 1: cout<<"\nInsertion at the beginning :- \n\n";
              cout<<"\nEnter a data : ";
              cin>>data;
              insert_beg(head, data);
              break;
            
      case 2: cout<<"\nInsertion at the end :- \n\n";
              cout<<"\nEnter a data : ";
              cin>>data;
              insert_end(head, data);
              break;
      
      case 3: cout<<"\nInsertion at a particular location :- \n\n";
              cout<<"\nEnter a data : ";
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
           
      case 7: cout<<"\nReverse :- \n";
              reverse(head);
              display(head);
              break;        
              
      case 8: display(head);
              break;
              
      case 9: exit(1);
      default: cout<<"\nINVALID!!!";
    }
  }
  return 0;
}
