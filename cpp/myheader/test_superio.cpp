#include "superio.h"
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main(){
	srand(time(NULL));
int x,y;
system("clear");

while(1){
	x=rand()%80;
	y=rand()%24;
	gotoxy(x,y);
	cout<<"\033[042m"<<(char)(rand()%128)<<"\033[0m";
	system("sleep 0.25");
}
cout<<endl;
return 0;
}