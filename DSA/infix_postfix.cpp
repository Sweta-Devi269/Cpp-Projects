//Convert infix to postfix using stack
#include<iostream>
#include<string.h>
#define MAX 50
using namespace std;

char stack[MAX], infix[MAX], postfix[MAX];
int top = -1;

void push(char);
char pop();
int IsEmpty();
void inToPost();
int space(char);
void print();
int precedence(char);

int main(){
  cout<<"Enter an infix expression : ";
  cin.getline(infix, MAX);

  inToPost();
  print();
  return 0;
}

int precedence(char symbol){
  switch(symbol){
    case '^': return 3;
    case '/': 
    case '*': 
      return 2;
    case '+': 
    case '-': 
      return 1;

    default: return 0;
  }
}

int space(char c){
  //if symbol is a blank space or tab space
  if(c == ' ' || c == '\t')
    return 1;
  else
    return 0;
}


void print(){
  int i = 0;
  cout<<"The postfix expression is : ";
  while(postfix[i])
    cout<<postfix[i++];
  cout<<endl;
}

void push(char c){
  if(top == MAX-1){
      cout<<"Stack Overflow!!!!";
      return;
  }
  stack[++top] = c;
}

char pop(){
  if(top == -1){
    cout<<"Stack Underflow!!!!";
    exit(1);
  }
  return stack[top--];
}

int IsEmpty(){
  if(top == -1)  // ← This checks for FULL stack!
    return 1;
  else  
    return 0;
}

void inToPost(){
  int i = 0, j = 0;
  for(i = 0; infix[i] != '\0'; i++){  // safer than strlen(infix) each time
    char symbol = infix[i];
    
    if(space(symbol)) continue;  // skip spaces

    switch(symbol){
      case '(': 
        push(symbol);
        break;

      case ')': {
        char item;
        while((item = pop()) != '('){
          postfix[j++] = item;
        }
        break;
      }

      case '^': 
      case '/': 
      case '*': 
      case '+': 
      case '-':
        while(!IsEmpty() && precedence(stack[top]) >= precedence(symbol)){
          postfix[j++] = pop();
        }
        push(symbol);
        break;

      default: 
        postfix[j++] = symbol;  // operands (A, B, etc.)
        break;
    }
  }

  while(!IsEmpty()){
    postfix[j++] = pop();
  }
  postfix[j] = '\0';
}
