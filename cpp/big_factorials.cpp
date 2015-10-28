#include <iostream>

using namespace std;

void multiply(int num,int ans[200],int *n){


 int temp,arr[200],carry;
 //clear all buffers:
  for(int i=0;i<200;arr[i]=ans[i++]);
  temp=num;
  //step4:
  carry=0;
  for(int i=0;i<199;i++){
    ans[i]=(arr[i]*(temp%10) + carry)%10;
    carry=(arr[i]*(temp%10) + carry)/10;
  }
  
  //step5:
  temp=temp/10;
  carry=0;
  for(int i=0;i<199;i++){
   ans[i+1]+=(arr[i]*(temp%10) + carry)%10;
    carry=(arr[i]*(temp%10) + carry)/10;
  }
  
  
  //step6:
  for(int i=199;i>=0;i--){
    if(ans[i]!=0){
      *n=i;
    break;
      
    }
   
  }
  
} 

void fact(int num, int ans[200], int *n){
 int temp=num;
  ans[0]=temp%10;temp/=10;
  ans[1]=temp%10;temp/=10;
  ans[2]=temp%10;
 
 for(int i=num-1;i>0;multiply(i--,ans,n));
}
int main(){
  
  int num,n,ans[200],t;
 //clear all buffers:
  for(int i=0;i<200;ans[i++]=0);
  n=0;
 cin>>t;
 while(t--){
   //clear all buffers:
  for(int i=0;i<200;ans[i++]=0);
  n=0;
   //find factorial
  cin>>num;
  fact(num,ans,&n);
  //output:
  for(int i=n;i>=0;cout<<ans[i--]);
  
  cout<<endl;
 }
  return 0;
}