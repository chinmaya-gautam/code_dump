#include<stdio.h>
#include<string.h>
void strrev(char str[],int len)
{
int i,point;
char temp;
point=(len-1)>>1;
for(i=0;i<=point;++i)
{
temp=str[i];
str[i]=str[len-i-1];
str[len-i-1]=temp;
}
}
int long_mult(char str1[],int len1,char str2[],int len2,char ans[])
{
int i,j,carry=0,sum,k=-1,len1minus1,len2minuslen1;
char temp[170];
len1minus1=len1-1;
for(i=0;i<len1minus1;temp[i]='0',++i);
strcpy(temp+len1minus1,str2);
len2+=len1minus1;
for(i=0;i<len1minus1;temp[len2+i]='0',i++);
temp[len2+i]='\0';
len2+=len1minus1;
len2minuslen1=len2-len1;
for(j=0;j<=len2minuslen1;j++)
{
for(sum=carry,i=len1minus1;i>=0;i--)
sum+=((str1[i]-'0')*(temp[j+len1minus1-i]-'0'));
ans[++k]=sum%10+'0';
carry=sum/10;
}
while(carry)
{
ans[++k]=carry%10+'0';
carry/=10;
}
ans[++k]='\0';
return k;
}
int main()
{
char fact[101][170]={"1","1","2","6","42","021"},mult[6];
int temp,i,factlen[101]={1,1,1,1,2,3},k,test;
for(i=6;i<=100;++i)
{
temp=i;
k=-1;
while(temp)
{
mult[++k]=temp%10+'0';
temp/=10;
}
mult[++k]='\0';
factlen[i]=long_mult(mult,k,fact[i-1],factlen[i-1],fact[i]);
}
for(i=4;i<=100;strrev(fact[i],factlen[i]),++i);
scanf("%d",&test);
while(test--)
{
scanf("%d",&i);
printf("%s\n",fact[i]);
}
return 0;
}