#include <stdio.h>

long long int fact(int num){if(num==1) return 1;
return(num*fact(num-1));}

int main(){
int n,num;
  scanf("%d",&n);
  while(n--){
    scanf("%d",&num);
    printf("%lld\n",fact(num));
  }
return 0;
}