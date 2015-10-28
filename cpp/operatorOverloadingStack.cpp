#include <iostream>
#define MAX_ITEMS 100

using namespace std;

class Stack {

private:
  int data[MAX_ITEMS];
  int top;
public:
  Stack(){top=-1;}
  void display();
  void operator+(int);
  int operator--(int);
};

int main(){

  Stack newStack;
  newStack.display();
  newStack+1;
  newStack+2;
  newStack+3;
  newStack.display();
  newStack--;
  newStack--;
  newStack.display();
  return 0;
}

void Stack::display(){
  cout<<"\n Stack: ";
  int temp = top;
   while(temp >= 0){
        cout<<data[temp--]<<" ";
  }
}

void Stack::operator+(int i){
  data[++top]=i;
}

int Stack::operator--(int dummy){
  if(top==-1)
    return 0;
  return data[top--];
}
