#include <iostream>
using namespace std;

int main(){
for(int i=0;i<255;i++){
  cout<<i<<" "<<char(i)<<endl;
}
cout<<"\u25fc"<<endl<<"\u25a0";
return 0;
}