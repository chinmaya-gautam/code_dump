// add rules to knowledge base
#include<fstream>
#include<cstdio>
#include<cstring>

using namespace std;
void show_database();

struct knowledge{
	char implicant[80];
	char implication[80];
}kn;

int main(){

	ofstream kb;
	kb.open("knowledge_base.db",ios::app|ios::binary|ios::in);
	while(true){
		printf("\033[032m LHS: ");
		gets(kn.implicant);
		if(strcmp(kn.implicant,"0")==0){break;}
		printf("\033[036m RHS: ");
		gets(kn.implication);
		
		kb.write((char*)&kn,sizeof(kn));
	}
	kb.close();
	show_database();
	printf("\033[0m\n");
return 0;
}

void show_database(){
	ifstream kb;
	kb.open("knowledge_base.db",ios::binary|ios::in);
	while(kb.good()){
		kb.read((char*) &kn,sizeof(kn));
		printf("\n\033[32m LHS: %s\n",kn.implicant);
		printf("\033[35m RHS: %s\n",kn.implication);
		
	}
	kb.close();
}