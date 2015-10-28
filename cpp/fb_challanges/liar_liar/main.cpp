#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

using namespace std;

struct list{
  list *left,*down;
  int group;
  char name[80];
} *start,*ptr_down,*ptr_left;

int to_digit(char*);
void get_name_number(char*,char*,int*);
void flush(char*);
void categorize();
bool not_checked(char*);

int main(int argc, char** argv){
  
  int NUM=0,num=0;
  char line[80],name[80];
  ifstream infile;
  
  start=ptr_down=ptr_left=NULL;
  infile.open(*(argv+1));
  infile.getline(line,80);
  NUM=to_digit(line);
  
  for(int i=0;i<NUM;i++){
    ptr_left=NULL;
  flush(line);
  infile.getline(line,80);
  flush(name);
  get_name_number(line,name,&num);

    if(start==NULL){
      start = new list;
      ptr_down=start;  
    }
    else{
      ptr_down->down=new list;
      ptr_down=ptr_down->down;
    }
    
    ptr_down->down=NULL;
    strcpy(ptr_down->name,name);
  ptr_down->group=0;
  //////////////////////////////////////////////////
    for(int j=0;j<num;j++){
      
      infile.getline(line,80);
     if(ptr_left==NULL){
       ptr_down->left=new list;
       ptr_left=ptr_down->left;  
      }
      else{
	ptr_left->left=new list;
	ptr_left=ptr_left->left;
      }
      ptr_left->left=NULL;
      strcpy(ptr_left->name,line);
    }
  }
  infile.close();
  cout<<endl;
  //traverse all nodes:
  for(ptr_down=start;ptr_down!=NULL;ptr_down=ptr_down->down){
    cout<<"\n\n\t\033[033m "<<ptr_down->name<<"\033[0m    ->    ";
    for(ptr_left=ptr_down->left;ptr_left!=NULL;ptr_left=ptr_left->left){
      cout<<"\033[034m "<<ptr_left->name<<"\033[0m, ";
    } 
  }
  categorize();
  cout<<endl;
  return 0;
}

int to_digit(char line[80]){
  int num=0;
  for(int i=0;i<80&&line[i]!='\0';i++){
    num=num*10 + (int)line[i] - 48;
  }
  return num;
}

void get_name_number(char* line,char* name,int* num){
  int i=0;
  //get the name from the line
    while((line[i]>='a'&&line[i]<='z')||(line[i]>='A'&&line[i]<='Z')){
      name[i]=line[i];
      i++;
    }
    //go to the number section
    while(line[i]<'0' || line[i]>'9'){
      i++;
    }
    *num=0;
    while(line[i]>='0' && line[i]<='9'){
      *num=(*num)*10 + (int)line[i] - 48;
      i++;
    }
}

void flush(char buffer[80]){
  for(int i=0;i<80;i++){
    buffer[i]='\0';
  }
}

void categorize(){
  
  cout<<"\nin categorize\n";
    list *ptr=start;
    int cntr=0;
    //for the first record
    ptr->group = -1;
    for(ptr=start->left;ptr!=NULL;ptr=ptr->left){
      ptr->group=1;
    }
    cout<<"\nmarked the first record:\n";
    for(ptr=start;ptr!=NULL;ptr=ptr->left){
      cout<<ptr->name<<"("<<ptr->group<<") ";
    }
    cout<<endl;
    //for the rest
    //find a marked person
   for(int i=0;i<5;i++){		//replace 5 by NUM
     cntr=0;
     for(ptr_down=start;ptr_down!=NULL;ptr_down=ptr_down->down,cntr++){
      if(not_checked(ptr_down->name)&&ptr_down->group!=0){
	ptr=ptr_down;
	break;
      }
     }
      cout<<"\nfound a marked person: "<<ptr->name<<endl;
      //mark the remaining associated people
      for(ptr_down=start;ptr_down!=NULL;ptr_down=ptr_down->down){

	for(ptr_left=ptr_down->left;ptr_left!=NULL;ptr_left=ptr_left->left){
	  cout<<"\ncomparing "<<ptr_left->name<<" with "<<ptr->name<<"\n";
	  if(strcmp(ptr_left->name,ptr->name) == 0){
	      
      cout<<"\nthe marked person found in some group\n";
	      for(ptr_left=ptr_down->left;ptr_left!=NULL;ptr_left=ptr_left->left){
		ptr_left->group=ptr->group;
	      }
	      ptr_down->group=ptr->group*(-1);
	   cout<<"\nthe associated record is now :\n";
	      for(ptr_left=ptr_down;ptr_left!=NULL;ptr_left=ptr_left->left)
	      {cout<<ptr_left->name<<"("<<ptr_left->group<<") ";}
	      break;
	  }
	}
         
      }
cout<<"\nreaches here, now the second phase\n";
      for(ptr_down=start;ptr_down!=NULL;ptr_down=ptr_down->down){
	cout<<"\nptr_down: "<<ptr_down->name<<"\n";
      for(ptr_left=ptr_down->left;ptr_left!=NULL;ptr_left=ptr_left->left){
	  cout<<"\nfinding "<<ptr_left->name<<"\n";
	 if(not_checked(ptr_left->name)&&ptr_left->group!=0){
	    ptr=ptr_left;
	    cout<<"to analyze:"<<ptr_left->name<<endl;
	    break;
	}
      }
    /*
      cout<<"\nfound a marked person: "<<ptr->name<<endl;
      //mark the remaining associated people
      for(ptr_down=start;ptr_down!=NULL;ptr_down=ptr_down->down){
	cout<<"\ncomparing "<<ptr_down->name<<" with "<<ptr->name<<endl; 
	if(strcmp(ptr_down->name,ptr->name) == 0){
	      cout<<"\nthe marked person found in some group\n";
	      for(ptr_left=ptr_down->left;ptr_left!=NULL;ptr_left=ptr_left->left){
		ptr_left->group=ptr->group*(-1);
	      }
	      ptr_down->group=ptr->group;
	      cout<<"\nthe associated record is now :\n";
	      for(ptr_left=ptr_down;ptr_left!=NULL;ptr_left=ptr_left->left)
	      {cout<<ptr_left->name<<"("<<ptr_left->group<<") ";}
	      break;
	  }
	
      }*/
   }
     
  }
}

bool not_checked(char name[80]){
  static char checked[80][80];
  static int end=0;
  cout<<"\n\n\t\t\tchecking analized people\n";
  for(int i=0;i<end;i++){
  cout<<"\n\t\t\t\tanalyzed: "<<checked[i]<<"\n";
    
  }
  for(int i=0;i<end;i++){
    if(strcmp(checked[i],name) == 0){
      return false;
    }
  }
  strcpy(checked[end++],name);
  return true;
}