#include <iostream>
using namespace std;

class board{
  
  
};
int main(){
for(int i=0;i<8;i++){
  cout<<"\n\t\t\t";
  for(int j=0;j<8;j++){
    if((i+j)%2 == 0)cout<<"\033[047m    \033[0m";
    else
      cout<<"\033[040m    \033[0m";
  }
  cout<<"\n\t\t\t";
  for(int j=0;j<8;j++){
    if((i+j)%2 == 0)cout<<"\033[047m    \033[0m";
    else
      cout<<"\033[040m    \033[0m";
  }
}
cout<<endl;
return 0;
}