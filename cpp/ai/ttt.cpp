#include <iostream>
#include <cstdlib>

using namespace std;

class board{
  char mat[3][3];
  int win_cases[3][8];
  public:
    board();
    bool move(char,int);
    bool print_board();
    bool cpu_move(char);
    bool check_win(char);
};

int main(){
char player,cpu;
int input;
bool turn;
board bd;
 // bd.print_board();
  cout<<"play as X player of O player?: ";
  cin>>player;
  if(player == 'X'){
    cpu = 'O';
    turn =true;
  }
  else if(player == 'O'){
    cpu = 'X';
    turn=false;
  }
  else{
    cerr<<"incorrect choice exiting...\n";
    exit(0);
  }
  while(1){
    if(turn){
      cout<<"your move: ";
      cin>>input;
      bd.move(player,input);
      bd.print_board();
      if(bd.check_win(player)){
	cout<<"you win!";
	exit(0);
      }
      turn=false;
    }
    else{
      bd.cpu_move(cpu);
      bd.print_board();
      turn=true;
      if(bd.check_win(cpu)){
	cout<<"you lose!";
	exit(0);
      }
    }
  }
  
}

bool board::print_board(){
  system("clear");
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      cout<<mat[i][j]<<"\t";
      }
      cout <<"\v\n";
  }
cout<<"\n";
}

bool board::move(char token,int place){
  switch(place){
    case 1: if(mat[2][0]==' '){mat[2][0] = token;}
	    break;
    case 2: if(mat[2][1]==' '){mat[2][1] = token;}
	    break;
    case 3: if(mat[2][2]==' '){mat[2][2] = token;}
	    break;
    case 4: if(mat[1][0]==' '){mat[1][0] = token;}
	    break;
    case 5: if(mat[1][1]==' '){mat[1][1] = token;}
	    break;
    case 6: if(mat[1][2]==' '){mat[1][2] = token;}
	    break;
    case 7: if(mat[0][0]==' '){mat[0][0] = token;}
	    break;
    case 8: if(mat[0][1]==' '){mat[0][1] = token;}
	    break;
    case 9: if(mat[0][2]==' '){mat[0][2] = token;}
	    break;
    default:break;
  }
  
}

bool board::cpu_move(char token){
   for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      if(mat[i][j]==' '){
	mat[i][j]=token;
	  return true;
	
      }
     }
  } 
}

bool board::check_win(char token){
  
  
}

board::board(){
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      mat[i][j]=' ';    
    }
  }

 win_cases[][8]={
   1,2,3,
   4,5,6,
   7,8,9,
   1,4,7,
   2,5,8,
   3,6,9,
   1,5,9,
   3,5,7
};
}
    