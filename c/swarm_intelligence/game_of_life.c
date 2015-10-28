#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define ROWS 60
#define COLS 60
#define SLEEP_DURATION 1

#define P_GGG 1          //gosper-glider-gun
#define P_ACR 2          //acorn
#define P_RND 3          //random
#define P_STL 4          //still life

#define NUM_G 5          //number of gliders

char grid[ROWS][COLS], temp_grid[ROWS][COLS];
int population_density = ROWS * COLS / 4;
char player_character = 'o';

void init();
void create_random_population();
void create_still_population();
void create_ggg_population();
void create_acorn_population();

void print_grid();
void play();
int num_neighbors(int, int);
void pattern_setter(int);

int main(){

  init();
  print_grid();
  play();
  return 0;
}

void init(){
  srand(time(NULL));

  for (int i=0;i<ROWS;i++){
    for (int j=0;j<COLS;j++){
      grid[i][j] = '.';
      temp_grid[i][j] = '.';
    }
  }
  //create_random_population();
  pattern_setter(P_RND);
}

void create_random_population(){
  int population_size = rand() % population_density;
  printf("DEBUG: population_size >> %d", population_size);
  for (int i=0;i<population_size;i++){
    int x = rand() % ROWS;
    int y = rand() % COLS;
    grid[x][y] = temp_grid[x][y] = player_character;
  }
}
void create_still_population(){

}

void create_gliders(int x_i, int y_i){
  grid[x_i + 1][y_i + 3] = player_character;
  grid[x_i + 2][y_i + 1] = player_character;
  grid[x_i + 2][y_i + 3] = player_character;
  grid[x_i + 3][y_i + 2] = player_character;
  grid[x_i + 3][y_i + 3] = player_character;

}
void create_ggg_population(){
  int i=0;
  for (i; i<NUM_G;i++){
    int x_i = rand()%ROWS - 1;
    int y_i = rand()%COLS - 1;
    create_gliders(x_i, y_i);
  }
}

void create_acorn_population(){

}

void pattern_setter(int pattern){
  /*P_GGG = gospel-glider-gun
    P_ACR = acorn
    P_RND = random
    P_STL = still life
  */
  switch(pattern){
  case P_RND: create_random_population();
    break;
  case P_STL: create_still_population();
    break;
  case P_GGG: create_ggg_population();
    break;
  case P_ACR: create_acorn_population();
    break;
  }
}

void print_grid(){
  system("clear");
  for (int i=0;i<ROWS;i++){
    for (int j=0;j<COLS;j++){
      printf("%c ", grid[i][j]);
    }
    printf("\n");
  }
}

void play(){
  while(1){
    for (int i=0;i<ROWS;i++){
      for (int j=0;j<COLS;j++){
	if (grid[i][j] == player_character){
	  int num = num_neighbors(i, j);
	  //	  printf("\ndebug, i:%d, j:%d, num_neighbors:%d", i, j, num);
	  if (num < 2){
	    temp_grid[i][j]='.';
	  }else if (num > 3){
	    temp_grid[i][j]='.';
	  }else{
	    temp_grid[i][j]=player_character;
	  }
	}else{
	  int num = num_neighbors(i, j);
	  if (num == 3){
	    temp_grid[i][j]=player_character;
	  }
	}
      }//end innter for
    }//end outer for

    for (int i=0;i<ROWS;i++){
      for (int j=0;j<ROWS;j++){
	grid[i][j] = temp_grid[i][j];
      }
    }

    print_grid();
    system("sleep 0.05");
  }//end while
}//end play


int num_neighbors(int x, int y){
  int total = 0;
  // 9 cases:

  //case 1: top left corner
  if(x == 0 && y == 0){
    if (grid[1][0] == player_character){
      total ++;
    }
    if (grid[0][1] == player_character){
      total ++;
    }
    if (grid[1][1] == player_character){
      total ++;
    }
    if (grid[ROWS-1][COLS-1] == player_character){
      total ++;
    }
    if (grid[ROWS - 1][0] == player_character){
      total ++;
    }
    if (grid[ROWS - 1][1] == player_character){
      total ++;
    }
    if (grid[0][COLS-1] == player_character){
      total ++;
    }
    if (grid[1][COLS - 1] == player_character){
      total ++;
    }
  }else if(x == 0 && y == COLS - 1){
    if (grid[0][COLS - 2] == player_character){
      total ++;
    }
    if (grid[1][COLS - 2] == player_character){
      total ++;
    }
    if (grid[1][COLS - 1] == player_character){
      total ++;
    }
    if (grid[0][0] == player_character){
      total ++;
    }
    if (grid[1][0] == player_character){
      total ++;
    }
    if (grid[ROWS - 1][0] == player_character){
      total ++;
    }
    if (grid[ROWS - 1][COLS-1] == player_character){
      total ++;
    }
    if (grid[ROWS - 1][COLS - 2] == player_character){
      total ++;
    }
  } else if(x == ROWS - 1 && y == 0){
    if (grid[ROWS - 1][1] == player_character){
      total ++;
    }
    if (grid[ROWS - 2][0] == player_character){
      total ++;
    }
    if (grid[ROWS - 2][1] == player_character){
      total ++;
    }
    if (grid[0][0] == player_character){
      total ++;
    }
    if (grid[0][1] == player_character){
      total ++;
    }
    if (grid[0][COLS - 1] == player_character){
      total ++;
    }
    if (grid[ROWS - 1][COLS-1] == player_character){
      total ++;
    }
    if (grid[ROWS - 2][COLS - 1] == player_character){
      total ++;
    }
  } else if(x == ROWS - 1 && y == COLS - 1){
    if (grid[0][0] == player_character){
      total ++;
    }
    if (grid[0][COLS -1] == player_character){
      total ++;
    }
    if (grid[0][COLS -2] == player_character){
      total ++;
    }
    if (grid[ROWS - 1][0] == player_character){
      total ++;
    }
    if (grid[ROWS - 2][0] == player_character){
      total ++;
    }
    if (grid[ROWS - 1][COLS - 2] == player_character){
      total ++;
    }
    if (grid[ROWS - 2][COLS-1] == player_character){
      total ++;
    }
    if (grid[ROWS - 2][COLS - 2] == player_character){
      total ++;
    }
  }else if(x == 0){
    if (grid[x][y + 1] == player_character){
      total ++;
    }
    if (grid[x][y - 1] == player_character){
      total ++;
    }
    if (grid[x+1][y - 1] == player_character){
      total ++;
    }
    if (grid[x + 1][y] == player_character){
      total ++;
    }
    if (grid[x + 1][y + 1] == player_character){
      total ++;
    }
    if (grid[ROWS - 1][y - 1] == player_character){
      total ++;
    }
    if (grid[ROWS - 1][y] == player_character){
      total ++;
    }
    if (grid[ROWS - 1][y + 1] == player_character){
      total ++;
    }
  }else if(x == ROWS - 1){
    if (grid[x][y + 1] == player_character){
      total ++;
    }
    if (grid[x][y - 1] == player_character){
      total ++;
    }
    if (grid[x-1][y-1] == player_character){
      total ++;
    }
    if (grid[x-1][y] == player_character){
      total ++;
    }
    if (grid[x-1][y+1] == player_character){
      total ++;
    }
    if (grid[0][y-1] == player_character){
      total ++;
    }
    if (grid[0][y] == player_character){
      total ++;
    }
    if (grid[0][y+1] == player_character){
      total ++;
    }
  }else if(y == 0){
    if (grid[x - 1][y] == player_character){
      total ++;
    }
    if (grid[x + 1][y] == player_character){
      total ++;
    }
    if (grid[x -1][y+1] == player_character){
      total ++;
    }
    if (grid[x][y+1] == player_character){
      total ++;
    }
    if (grid[x+1][y+1] == player_character){
      total ++;
    }
    if (grid[x - 1][COLS - 1] == player_character){
      total ++;
    }
    if (grid[x][COLS - 1] == player_character){
      total ++;
    }
    if (grid[x + 1][COLS - 1] == player_character){
      total ++;
    }
  }else if(y == COLS - 1){
    if (grid[x-1][y] == player_character){
      total ++;
    }
    if (grid[x+1][y] == player_character){
      total ++;
    }
    if (grid[x-1][y-1] == player_character){
      total ++;
    }
    if (grid[x][y-1] == player_character){
      total ++;
    }
    if (grid[x+1][y-1] == player_character){
      total ++;
    }
    if (grid[x-1][0] == player_character){
      total ++;
    }
    if (grid[x][0] == player_character){
      total ++;
    }
    if (grid[x + 1][0] == player_character){
      total ++;
    }
 }else{
    if (grid[x-1][y-1] == player_character){
      total ++;
    }
    if (grid[x-1][y] == player_character){
      total ++;
    }
    if (grid[x-1][y+1] == player_character){
      total ++;
    }
    if (grid[x][y-1] == player_character){
      total ++;
    }
    if (grid[x][y+1] == player_character){
      total ++;
    }
    if (grid[x+1][y-1] == player_character){
      total ++;
    }
    if (grid[x+1][y] == player_character){
      total ++;
    }
    if (grid[x+1][y+1] == player_character){
      total ++;
    }
  }
  
return total;
}
