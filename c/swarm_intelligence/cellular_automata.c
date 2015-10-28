#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 160
#define ON_CHAR '@'
#define OFF_CHAR '.'
char row[ROWS];

void init();
char next_val(int);
void print_row();
void play();

int main(){

  init();
  play();
  return 0;
}

void init(){
  system("clear");
  srand(time(NULL));
  for (int i=0;i<ROWS;i++){
    row[i] = rand()%2 == 0?OFF_CHAR:ON_CHAR;
  }
}

void play(){
  while(1){
    print_row();
    for (int i=0;i<ROWS;i++){
      row[i] = next_val(i);
    }
}
}
void print_row(){
  for(int i=0;i<ROWS;i++){
    printf("%c",row[i]);
  }
  printf("\n");
}

char next_val(int i){
  int prev, next;
  char next_char = '#';

  if (i==0){
    prev = ROWS - 1;
    next = 1;
  }else if (i == ROWS - 1){
    prev = i-1;
    next = 0;
  }else{
    prev = i-1;
    next = i + 1;
  }

  if (row[prev] == ON_CHAR){
    if(row[i] == ON_CHAR && row[next] == ON_CHAR){
      next_char = OFF_CHAR;
    }else if (row[i] == ON_CHAR && row[next] == OFF_CHAR){
      next_char = ON_CHAR;
    }else if (row[i] == OFF_CHAR && row[next] == ON_CHAR){
      next_char= OFF_CHAR;
    }else if (row[i] == OFF_CHAR && row[next] == OFF_CHAR){
      next_char = ON_CHAR;
    }
  }else if (row[prev] == OFF_CHAR){
    if(row[i] == ON_CHAR && row[next] == ON_CHAR){
      next_char = ON_CHAR;
    }else if (row[i] == ON_CHAR && row[next] == OFF_CHAR){
      next_char = OFF_CHAR;
    }else if (row[i] == OFF_CHAR && row[next] == ON_CHAR){
      next_char= ON_CHAR;
    }else if (row[i] == OFF_CHAR && row[next] == OFF_CHAR){
      next_char = OFF_CHAR;
    }
  }
  return next_char;
}
