#include <stdio.h>
#include "story.h"

int main(){
int i,j,z,u,NUM=0,not_found;
char word[80];
char find[]="the";
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
    
    printf("\nthe word: %s\n",word);
    not_found=0;
    for(u=0;u<3;u++){
      if(find[u]!=word[u])
	not_found=1;
    }
    if(not_found==0&&word[u]=='\0'){printf("found here\n");NUM++;}      
    }

    
  }

  printf("\nthe number of '%s' in story is %d\n",find,NUM);
return 0;
}