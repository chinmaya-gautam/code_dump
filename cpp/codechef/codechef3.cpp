#include <iostream>

using namespace std;

long int Z(long int);

int main(){
  
  long int T,num;
  cin>>T;
  for(int i=0;i<T;i++){
      cin>>num;
      cout<<Z(num)<<"\n";
  }
return 0;
}

long int Z(long int num){
  long int div=0,n=5;
  
  while(n<=num){
    div+=num/n;
    n*=5;
  }

  return div;
}