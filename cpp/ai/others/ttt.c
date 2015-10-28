#include <stdio.h>
#include <stdlib.h>

char matrix[3][3];

char check(void);
void init_matrix(void);
void get_player_move(void);
void get_computer_move(void);
void disp_matrix(void);
int heuristics(int*, int*);
int move_weight(int,int);

int main(void){
int allfilled,i,j;
  char done;
  printf("TIC TAC TOE\n\n");
  done=' ';

  init_matrix();
  do{
    disp_matrix();
    get_player_move();
    done=check();
    if(done != ' '){break;}
    get_computer_move();
    done=check();
    if(done != ' '){break;}

	allfilled=1;
    for(i=0;i<3;i++){
	for(j=0;j<3;j++){
		if(matrix[i][j]==' '){
			allfilled=0;		
		}	
	}
    }
	if(allfilled==1){disp_matrix();printf("Its a draw!\n");exit(0);}
  }while(done ==' ');

  if(done=='X'){
    printf("You won\n");
  }
  else {
    printf("you lose\n");
  }
  disp_matrix();
return 0;
}

void init_matrix(void){
  int i,j;

  for(i=0;i<3;i++){
    for(j=0;j<3;j++){
      matrix[i][j]=' ';
    }
  }
}

void get_player_move(void){
  int x,y;
  printf("Enter x y coordinates for your move: ");
  scanf("%d %d",&x, &y);
  x--;
  y--;

  if(matrix[x][y] !=' '){
    printf("invalid move, try again!\n");
    get_player_move();
  }
  else{
    matrix[x][y] = 'X';
  }
}

void get_computer_move(void){
  int i,j;
  if(i*j ==9){
    printf("draw\n");
    exit(0);
  }
  else
      heuristics(&i,&j);
      matrix[i][j]='O';
}

void disp_matrix(void){
  int t;
  for (t=0;t<3;t++){
    printf(" %c | %c | %c ",matrix[t][0],
	   matrix[t][1],matrix[t][2]);
    if(t!=2){
      printf("\n---|---|---\n");
      
    }
  }
    printf("\n");
  }
  
char check(void){
  
  int i;
  
  for (i=0;i<3;i++){
    if(matrix[i][0] == matrix[i][1] && matrix[i][0] == matrix[i][2]) return matrix[i][0];
    
  }
  
  for (i=0;i<3;i++){
    if(matrix[0][i] == matrix[1][i] && matrix[0][i] == matrix[2][i]) return matrix[0][i];
    
  }
  
  if(matrix[0][0] ==matrix[1][1] && matrix[0][0] == matrix[2][2]) return matrix[0][0];
  
  if(matrix[0][2] ==matrix[1][1] && matrix[0][2] == matrix[2][0]) return matrix[0][2];
  
  return ' ';
}

int heuristics(int *movei, int *movej){
  int i,j,wt=-1,temp=-1;
  for(i=0;i<3;i++){
    for(j=0;j<3;j++){
      if (matrix[i][j]==' '){
	temp=move_weight(i,j);
	if(temp>wt){
	  wt=temp;
	  *movei=i;
	  *movej=j;
	}
      }
    }
  }
}

int move_weight(int i,int j){
  char token;
  int weight=0;
  /*check if a move leads to absolute win or loss*/

      matrix[i][j] ='O';
      token=check();
      if(token == 'O'){
	matrix[i][j]=' ';
	return 10;
      }
      matrix[i][j] ='X';
      token=check();
      if(token == 'X'){
	matrix[i][j]=' ';
	return 9;
      }
      matrix[i][j]=' ';
      /*calculate weights for other valid moves*/
      /*for row*/
      if(matrix[i][0]=='X'|| matrix[i][1]=='X' || matrix[i][2]=='X'){
	    weight+=0;
	}
	if(matrix[i][0]==' '&& matrix[i][1]==' ' && matrix[i][2]==' '){
	  weight+=1;
	}
	if(matrix[i][0]=='0'&& matrix[i][1]==' ' && matrix[i][2]==' '){
	  weight+=2;
	}
	if(matrix[i][0]==' '&& matrix[i][1]=='0' && matrix[i][2]==' '){
	  weight+=2;
	}
	if(matrix[i][0]==' '&& matrix[i][1]==' ' && matrix[i][2]=='0'){
	  weight+=2;
	}
	/*for column*/
	if(matrix[0][j]=='X'|| matrix[1][j]=='X' || matrix[2][j]=='X'){
	    weight+=0;
	}
	if(matrix[0][j]==' '&& matrix[1][j]==' ' && matrix[0][j]==' '){
	  weight+=1;
	}
	if(matrix[0][j]=='0'&& matrix[1][j]==' ' && matrix[2][j]==' '){
	  weight+=2;
	}
	if(matrix[0][j]==' '&& matrix[1][j]=='0' && matrix[2][j]==' '){
	  weight+=2;
	}
	if(matrix[0][j]==' '&& matrix[1][j]==' ' && matrix[2][j]=='0'){
	  weight+=2;
	}
	/*if its the central element*/
	if(i==1 && j ==1){
	  if(matrix[0][0]==' '&& matrix[2][2]==' '){
	    weight+=1;
	  }
	  if(matrix[0][0]=='X'&& matrix[2][2]==' '){
	    weight+=2;
	  }
	  if(matrix[0][0]==' '&& matrix[2][2]=='X'){
	    weight+=2;
	  }
	  
	  if(matrix[0][2]==' '&& matrix[2][0]==' '){
	    weight+=1;
	  }
	  if(matrix[0][2]=='X'&& matrix[2][0]==' '){
	    weight+=2;
	  }
	  if(matrix[0][2]==' '&& matrix[2][0]=='X'){
	    weight+=2;
	  }
	}
  return weight;
}
