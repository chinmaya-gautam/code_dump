#include <stdio.h>

int main(){
int i,j,z,NUM=0;
char word[80];
  for(i=0;i<N;i++){
    for(j=0;j<80;j++){
      z=0;
      //start of word
      if(j==0||LINE[i][j-1]==' '){
	while(j<80 && LINE[i][j] != ' '){  //end of word
	  word[z++]=LINE[i][j++];
	}
      }
      word[z]='\0';
      NUM++;
    }
  }
  printf("\nthe number of words in the story: %d\n",NUM);

return 0;
}