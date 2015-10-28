//NOTICE: INCREASE THE SLEEP TIME TO 0.5 & REDUCE LENGTH TO 140 
#include <iostream>
#include <cstdlib>
#include <ctime>

#define LENGTH 500
#define MONOTONE 0		//set 0 for off, 1 for on
#define MUTATE 1		//set 0 for off, 1 for on
#define FREQUENCY 50	//the mutation frequency

using namespace std;
/* !!!THE ORIGINAL SET OF RULE BASE DO NOT DELETE!!!!
int rule_base[8][4]={
	1,1,1,0,
	1,1,0,1,
	1,0,1,0,
	1,0,0,1,
	0,1,1,1,
	0,1,0,0,
	0,0,1,1,
	0,0,0,0
};
*/
//experimental set of test rules
int rule_base[8][4]={
		1,1,1,0,
	1,1,0,1,
	1,0,1,0,
	1,0,0,1,
	0,1,1,1,
	0,1,0,0,
	0,0,1,1,
	0,0,0,0
	
};

int bit_string[LENGTH];

void mutate(){
	int irand,jrand;
	irand=rand()%8;
	jrand=rand()%4;
	if(rule_base[irand][jrand]==0){rule_base[irand][jrand]=1;}
	else{rule_base[irand][jrand]=0;}
}

void evolve(){
	int buffer[LENGTH];
	
	//copy bit_string to buffer
	for(int i=0;i<LENGTH;buffer[i]=bit_string[i++]);
	
	for(int i=0;i<LENGTH;i++){
		for(int j=0;j<8;j++){
			if(i==0){
				if(buffer[79]==rule_base[j][0] && buffer[i]==rule_base[j][1] && buffer[i+1]==rule_base[j][2]){
					bit_string[i]=rule_base[j][3];
				}	
			}
			else if(i==LENGTH-1){
				if(buffer[i-1]==rule_base[j][0] && buffer[i]==rule_base[j][1] && buffer[0]==rule_base[j][2]){
					bit_string[i]=rule_base[j][3];
				}
			}
			
			if(buffer[i-1]==rule_base[j][0] && buffer[i]==rule_base[j][1] && buffer[i+1]==rule_base[j][2]){
				bit_string[i]=rule_base[j][3];
			}
		}
	}
	
}
int main(){
int color=1;
int cntr=0;

srand(time(NULL));
	for(int i=0;i<LENGTH;bit_string[i++]=rand()%2);
	for(int i=0;i<LENGTH;cout<<bit_string[i++]);
	cout<<endl;
	while(true){
			if(MUTATE==1){
				if(cntr==FREQUENCY){
					cntr=0;
					mutate();
				}
			else{cntr++;}
			}
		
		//evolve
		evolve();
		for(int i=0;i<LENGTH;i++){
			if(MONOTONE==1)color=1+rand()%7;
			if(bit_string[i]==1){
				cout<<"\033[04"<<color<<"m \033[0m";
			}
			else{
				cout<<" ";
			}
		}
		cout<<endl;
		system("sleep 0.05");
		
	}cout<<endl;
return 0;
}