#include <iostream>
#include <cstdio>
#include <fstream>
#include <cstring>

using namespace std;

void process(char*, char*);
char exit_word[][80]={
	"bye",
	"goodbye",
	"quit",
	"leave",
	"exit",
	"done",
	"stop"
};

struct knowledge{
	char implicant[80];
	char implication[80];
}kn;

int main(){
	char input[80];
	char output[80];
	bool loop=true;
	
	while(loop){
		cout<<"\033[32m you:";
		gets(input);
		cout<<"\033[0m";
		process(input,output);
		cout<<"\033[36m cpu:";
		puts(output);
		cout<<"\033[0m";
		for(int i=0;i<7;i++){
			if(strcmp(input,exit_word[i])==0){loop=false;}
		}
	}
	cout<<"\033[0m\n";
	
return 0;
}

void process(char input[80],char output[80]){

	ifstream kb_in;
	ofstream kb_out;
	bool found=false;

kb_in.open("knowledge_base.db",ios::binary|ios::in);
if(!kb_in.good()){
	cout<<"could not open file";
}
while(kb_in.good()){
	kb_in.read((char*)&kn,sizeof(kn));
	if(strcmp(input,kn.implicant)==0){
		strcpy(output,kn.implication);
		found=true;
		break;
	}
}
if(!found){
	kb_in.close();
	kb_out.open("knowledge_base.db",ios::binary|ios::app);
	cout<<"\033[33mcpu: I don't know how to reply to this question!!! what would have been your reply?? : ";
	gets(output);
	strcpy(kn.implicant,input);
	strcpy(kn.implication,output);
	kb_out.write((char*)&kn,sizeof(kn));
	kb_out.close();
	return;
}
kb_in.close();
}