#include <iostream>

using namespace std;

int main(){
long int n,k,num,ans=0;
cin>>n>>k;
for (long int i=0;i<n;i++){
cin>>num;
if(num%k==0) {ans++;}
}
cout<<ans;

return 0;
}