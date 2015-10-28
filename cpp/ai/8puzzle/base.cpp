/*8 puzzle game - the base*/

#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

class board{
  int goal[3][3];
  int mat[3][3];
  int posx,posy;
public:
  board();
  ~board();
  void print_configuration();
  bool move(char);
  bool compare();
  void play();
  
};
int main(){
  board bd;
  bd.print_configuration();
  bd.play();
return 0;
}

board::board(){
  cout<<"Enter initial configuration of matrix:\n";
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      cin>>mat[i][j];
      if(mat[i][j]==0){posx=i;posy=j;}
      
    }
   } 
  cout<<"\n\nEnter final configuration of matrix:\n";
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      cin>>goal[i][j];
    }
  }
}

board::~board(){
  cout<<"\n\nDONE\n\n";
}

void board::print_configuration(){
  cout<<"\n\n";
  cout<<"matrix\t\t\tgoal";
  cout<<"\n------\t\t\t----\n";
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      cout<<mat[i][j]<<" ";
    }
    cout<<"\t\t\t";
    for(int j=0;j<3;j++){
      cout<<goal[i][j]<<" ";
    }
    cout<<"\n";
  }
  cout<<"\n\n";
  
}

bool board::compare(){
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      if(mat[i][j]!=goal[i][j]){
	return false;
      }
    }
  }
  return true;
}

bool board::move(char direction){
  int temp;
  switch(direction){
    case 'L': if(posy!=0){
		temp=mat[posx][posy];
		mat[posx][posy]=mat[posx][posy-1];
		mat[posx][posy-1]=temp;
		posy=posy-1;
		return true;
	      }break;
    case 'R': if(posy!=2){
		temp=mat[posx][posy];
		mat[posx][posy]=mat[posx][posy+1];
		mat[posx][posy+1]=temp;
		posy=posy+1;
		return true;
	      }break;
    case 'T': if(posx!=0){
		temp=mat[posx][posy];
		mat[posx][posy]=mat[posx-1][posy];
		mat[posx-1][posy]=temp;
		posx=posx-1;
		return true;
	      }break;
    case 'B': if(posx!=2){
		temp=mat[posx][posy];
		mat[posx][posy]=mat[posx+1][posy];
		mat[posx+1][posy]=temp;
		posx=posx+1;
		return true;
	      }break;
    
  }
  
  return false;
}

void board::play(){
  char c;
  system("clear");
    cout<<"\n\n\t\t\tINSTRUCTIONS\n\n";
    cout<<"\nuse keys A D W S to move the blank space left right top or bottom";
    cout<<"\nthe goal is to reach goal configuration";
  while(1){
    system("clear");
      print_configuration();
    if(compare()) return;
      cout<<"your move: ";
      c=getchar();
      fflush(stdin);
      switch(c){
	case 'A':move('L');break;
	case 'W':move('T');break;
	case 'S':move('B');break;
	case 'D':move('R');break;
	default: cout<<"enter a correct move";
      }
    }
  }
  
