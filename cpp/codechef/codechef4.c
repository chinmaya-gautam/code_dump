#include <stdio.h>

int main(){
long int n,k,num,ans=0;
scanf("%l %l",&n,&k);;
for (long int i=0;i<n;i++){
scanf("%l",&num);
if(num%k==0) {ans++;}
}
cout<<ans;

return 0;
}