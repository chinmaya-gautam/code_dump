//IDEAL SLEEP: 2SECS
#include <iostream>
#include <cstdlib>
#include <ctime>

//looks good at 40 X 40
#define rows 80
#define columns 80
#define MONOTONE 0 		//set to 1 for on 0 for off

class board{
  char mat[rows][columns][2];
  char buffer[rows][columns][2];
public:
  board();
  void print_board();
  void play();
  int count_neighbours(int, int);
  ~board();
};

using namespace std;

int main(){
board bd;
bd.print_board();
bd.play();
return 0;
}

board::board(){
  cout<<"\nHI\n\n";
  int x,y;
  for(int i=0;i<rows;i++){
    for(int j=0;j<columns;j++){
      mat[i][j][0]='.';
      mat[i][j][1]='D';
    }
  }
  cout<<"\ninitialized board\n\n";
  //find random rows and columns
  srand(time(NULL));
      
  for(int i=0;i<rows/2;i++){
    for(int j=0;j<columns/2;j++){
      x = rand()%(rows - 1);
      y = rand()%(columns - 1);
      cout<<"\nx :"<<x<<" y: "<<y<<endl;
      mat[x][y][0] = 'A';
      mat[x][y][1] = 'A';
      
      }
  }
 //copy board to buffer
 for(int i=0;i<rows;i++){
   for(int j=0;j<columns;j++){
     buffer[i][j][0]=mat[i][j][0];
     buffer[i][j][1]=mat[i][j][1];
     
     
    }
 }
  
}
board::~board(){
  cout<<"\n\nall done bye\n\n";
  
}

void board::print_board(){
	int color=1;
  int c=0;
  for(int i=0;i<rows;i++){
    cout<<endl;
    c=0;
    for(int j=0;j<columns;j++){
		
      if(mat[i][j][1] == 'A')
      {if(MONOTONE==1)color=1+rand()%7;
			c=32;
	if(mat[i][j][0] == 'A')cout<<"\033[4"<<color<<"m  \033[0m";
	else cout<<". ";
	
      }
      else
      {c=34;
	if(MONOTONE==1)color=1+rand()%7;
			
	if(mat[i][j][0] == 'A')	cout<<"\033[3"<<color<<"m  \033[0m";
	else cout<<". ";
	
      }
     }
  }
}

void board::play(){
 
  int neighbours;
  while(1){
  system("clear");
  print_board();
  system("sleep 2");
  for(int i=0;i<rows;i++){
      for(int j=0;j<columns;j++){
	neighbours = count_neighbours(i,j);
	switch(neighbours){
	  case 0: buffer[i][j][0] = '.';
		  buffer[i][j][1] = 'D';
		  break;
	  case 1: buffer[i][j][0] = '.';
		  buffer[i][j][1] = 'D';
		  break;
	  case 2: buffer[i][j][0] = 'A';
		  buffer[i][j][1] = 'A';
		  break;
	  default: break;
	}
      }
    }
    for(int i=0;i<rows;i++){
      for(int j=0;j<columns;j++){
	mat[i][j][0]=buffer[i][j][0];
	mat[i][j][1]=buffer[i][j][1];
      }
    }
  }
  
}

int board::count_neighbours(int i, int j){
  int neighbours=0;

	for(int u = i-1;u<=i+1;u++){
		for(int v=j-1;v<=j+1;v++){
			if(u>=0&&u<rows&&v>=0&&v<columns){
				if(mat[u][v][0]=='A'){
					neighbours++;
				}
			}
			if(u==0){
				if(mat[rows-1][v][0]=='A'){
					neighbours++;
				}
			}
			if(v==0){
				if(mat[u][columns-1][0]=='A'){
					neighbours++;
				}
			}
			if(u==rows-1){
				if(mat[0][v][0]=='A'){
					neighbours++;
				}
			}
			if(v==columns-1){
				if(mat[u][0][0]=='A'){
					neighbours++;
				}
			}
			if(u==0&&v==0){
				if(mat[rows-1][columns-1][0]=='A'){
					neighbours++;
				}
			}
			if(v==columns-1&&u==rows-1){
				if(mat[0][0][0]=='A'){
					neighbours++;
				}
			}
			if(v==columns-1&&u==0){
				if(mat[rows-1][0][0]=='A'){
					neighbours++;
				}
			}
			if(v==0&&u==rows-1){
				if(mat[0][columns-1][0]=='A'){
					neighbours++;
				}
			}
		}
	}

  
  if(mat[i][j][0]=='.' && neighbours == 3){				//unoccupied
  return 2;
  }
  if(neighbours>3){
    return 1;
  }
  if(neighbours<2){
    return 0;
  }
}
