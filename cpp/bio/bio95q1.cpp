#include <iostream>

using namespace std;

class primes{
int M,NUM;
public:
primes();
void print_primes();

};

int main(){
  primes p;
  p.print_primes();
  return 0;
}

primes::primes(){
  M=0;
  NUM=0;
  while(M==0){
    cout<<"\nMaximum number ot test? ";
    cin>>M;
    if(M>2000) M=0;
  }
}

void primes::print_primes(){
  bool prime;
  cout<<"The following number between 2 and "<<M<<" are prime:\n";
  for(int j=2;j<=M;j++){
    prime=true;
    for(int i=2;i<j;i++){
      if(j%i==0){
	prime=false;
      }  
    }
    if(prime){cout<<j<<" ";NUM++;}
  }
  cout<<"\nA total of "<<NUM<<" prime numbers were found in this range\n\n";
}