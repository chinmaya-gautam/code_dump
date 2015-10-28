#include <iostream>

using namespace std;

int main(){
 int input;
  while(true){
  
    std::cin>>input;
    if(input==42) return 0;
    std::cout<<input<<endl;
  }
return 0;
}