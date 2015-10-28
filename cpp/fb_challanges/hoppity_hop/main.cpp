//HOPPITY HOP

#include <iostream>
#include <fstream>

using namespace std;

int to_digit(char*);

int main(int argc, char** argv){

    char input[80];
    int NUM;
    ifstream infile;
    infile.open(*(argv + 1));
  
    if(!infile){
      return 1;
    }
    
      infile.getline(input,80);
      NUM=to_digit(input);
infile.close();

for(int i=1;i<=NUM;i++){
  if(i%15 == 0){
    cout<<"\nHop";
  }
  else if(i%3 == 0){
    cout<<"\nHoppity";
  }
  else if(i%5 == 0){
    cout<<"\nHophop";
  }
}
cout<<"\n";
return 0;
}

int to_digit(char* input){
  int i=0;
  int num=0;
  while(input[i]!='\0'){
    num=num*10 + (int)input[i++] - 48;
  }
  return num;
}