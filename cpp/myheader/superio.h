#include <iostream>

using namespace std;

void gotoxy(int x,int y){
	if(x<0)x=0;
	if(y<0)y=0;
	cout<<"\033["<<x<<";"<<y<<"H";
}