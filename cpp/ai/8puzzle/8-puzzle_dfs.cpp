#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class board{
	int mat[3][3],mat_goal[3][3];
	int posx,posy;
	int steps,temp_steps;
	char prev_move;
public :
	board(){}
	void init();
	bool mov_left();
	bool mov_right();
	bool mov_top();
	bool mov_bottom();	
	void print_board();
	bool check_config();
	bool start_check();
};

int main(){
board bd;
bool found;
bd.init();
if(bd.start_check()){
	cout<<"\n\nresult found\n\n";
}
return 0;
}

/**************************************************************************************************************/
void board::init(){
	cout<<"\nenter initial configuration (as a matrix):\n";	
	for(int i=0;i<3;i++){
		for(int j=0; j<3; j++){
			cin>>mat[i][j];
				if(mat[i][j]==0){posx = i; posy=j;}
			}
	}
	cout<<"\n\n\nenter final configuration (as a matrix): \n";
	for(int i=0;i<3;i++){
		for(int j=0; j<3; j++){
			cin>>mat_goal[i][j];
			}
	}
	cout<<"\n\n\nenter the number of steps : ";
	cin>>steps;
	temp_steps=0;
	prev_move='\0';
	
}
/***************************************************************************************************************/
void board::print_board(){
cout<<"\nboard configuration :\n";
	for(int i=0;i<3;i++){
		for(int j=0; j<3; j++){
			cout<<mat[i][j]<<" ";
		}
	cout<<endl;
	}
cout<<"\n\n";
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool board::mov_left(){

if(prev_move=='R'){
return false;
}

prev_move='L';
print_board();
temp_steps++;
int temp;
bool found;
	if(posy==0){
		return false;
	}

	temp=mat[posx][posy];
	mat[posx][posy]=mat[posx][posy-1];
	mat[posx][posy-1]=temp;
	posy--;
	 if(check_config()){
		return true;
	}
	else if (temp_steps>=steps){
		return false;
	}
	else{
		start_check();
	}
}
/*******************************************************************************************************************/
bool board::mov_right(){

if(prev_move=='L'){
return false;
}

prev_move='R';
print_board();
temp_steps++;
int temp;
if(posy==2){
		return false;
	}

	temp=mat[posx][posy];
	mat[posx][posy]=mat[posx][posy+1];
	mat[posx][posy+1]=temp;
	posy++;
	 if(check_config()){
		return true;
	}
	else if (temp_steps>=steps){
		return false;
	}
	else{
		start_check();
	}
}
/*******************************************************************************************************************/
bool board::mov_top(){

if(prev_move=='B'){
return false;
}

prev_move='T';
print_board();
temp_steps++;
int temp;
if(posx==0){
		return false;
	}

	temp=mat[posx][posy];
	mat[posx][posy]=mat[posx-1][posy];
	mat[posx-1][posy]=temp;
	posx--;
	 if(check_config()){
		return true;
	}
	else if (temp_steps>=steps){
		return false;
	}
	else{
		start_check();
	}
}
/*******************************************************************************************************************/
bool board::mov_bottom(){

if(prev_move=='T'){
return false;
}

prev_move='B';
print_board();
temp_steps++;
int temp;
if(posx==2){
		return false;
	}

	temp=mat[posx][posy];
	mat[posx][posy]=mat[posx+1][posy];
	mat[posx+1][posy]=temp;
	posx++;

	 if(check_config()){
		return true;
	}
	else if (temp_steps>=steps){
		return false;
	}
	else{
		start_check();
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////

bool board::check_config(){
	for(int i=0; i<3;i++){
		for(int j=0; j<3;j++){
			if (mat[i][j]!=mat_goal[i][j]){
				return false;			
			}	
		}
	}
return true;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////

bool board::start_check(){
bool found;
	
	return(mov_left() || mov_top() || mov_right()|| mov_bottom()); 

}
