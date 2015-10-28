#include <iostream>

using namespace std;
	
class board{

public:
	int state[3][3];
	
int posx,posy;
board(){}
       bool move_left();
       bool move_right();
       bool move_top();
       bool move_bottom();
       void initialize_state();
       void display();

};

struct linked_list{
	board *brd;
	linked_list *next;
	};
	
class search{
board temp_state,goal_state,initial_state;
char prev;
linked_list *open_start,*closed_start,*open_ptr,*closed_ptr;
board **path;
board *root,*ptr;
public:
	search();
	void display(board state);
	bool is_goal();
	bool bfs();
	bool push();
	bool pop();
	bool closed();
}s;

int main(){
s.bfs();
cout<<"found !";
system("pause");
return 0;
}
/*****************************************************************/
search::search(){ 
//////////initialize temp state//////////////
	cout<<"\n enter initial state :\n\n";
	temp_state.initialize_state();
/////////initialize goal state///////////////
	cout<<"\n enter goal state: \n\n";
	goal_state.initialize_state();

	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			initial_state.state[i][j]=temp_state.state[i][j];
		}
	}
	open_start = new linked_list;
	open_ptr= open_start;
	open_start->next=NULL;
	open_start->brd=&temp_state;
	
	closed_start=NULL;
	closed_ptr=NULL;
     cout<<"\n \n path :\n";
}
/*******************************************************************/

void board::initialize_state(){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cin>>state[i][j];
			if(state[i][j] ==0){
				posx=i;
				posy=j;
			}
		}
	}
}
/********************************************************************/

bool board::move_left(){
	int temp;
	if(posy==0){
		return false;
	}
	temp=state[posx][posy];
	state[posx][posy]=state[posx][posy-1];
	state[posx][posy-1]=temp;
	posy--;
	return true;
}
/*******************************************************************/
bool board::move_right(){
int temp;
	if(posy==2){
		return false;
	}
	temp=state[posx][posy];
	state[posx][posy]=state[posx][posy+1];
	state[posx][posy+1]=temp;
	posy++;
	return true;
}
/*******************************************************************/
bool board::move_top(){
int temp;
	if(posx==0){
		return false;
	}
	temp=state[posx][posy];
	state[posx][posy]=state[posx-1][posy];
	state[posx-1][posy]=temp;
	posx--;
	return true;
}
/*******************************************************************/
bool board::move_bottom(){
int temp;
	if(posx==2){
		return false;
	}
	temp=state[posx][posy];
	state[posx][posy]=state[posx+1][posy];
	state[posx+1][posy]=temp;
	posx++;
	return true;
}
/********************************************************************/
bool search::is_goal(){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(temp_state.state[i][j]!=goal_state.state[i][j]){
				return false;
			}
		}
	}
	return true;
}
/*******************************************************************/
bool search::bfs(){
	pop();
	temp_state.move_left();
	temp_state.display();
	if(is_goal()){
		return true;
	}
	push();
	temp_state.move_right();
	temp_state.display();
	if(is_goal()){
		return true;
	}
	push();
	
	temp_state.move_top();
	if(is_goal()){
		return true;
	}
	temp_state.display();
	push();
	
	temp_state.move_bottom();
	if(is_goal()){
		return true;
	}
	temp_state.display();
	push();

	bfs();

}
/*******************************************************************/
void board::display(){
	for(int i=0; i<3;i++){
		for(int j=0;j<3;j++){
			cout<<state[i][j]<<" ";		
		}
		cout<<endl;
	}
}
/********************************************************************/

bool search::push(){

	if(closed()){
	////reset initial state for next call///
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				temp_state.state[i][j]=initial_state.state[i][j];
				if(initial_state.state[i][j]==0){
					temp_state.posx=i;
					temp_state.posy=j;
				}
			}
		}
	//////////////////done///////////////////
		return false;
	}
	if(open_start ==NULL) {		///may be erronious
		open_start= new linked_list;
		open_ptr=open_start;
		open_ptr->next=NULL;
		
		open_ptr->brd=&temp_state;
	}
	else{
		open_ptr->next=new linked_list;
		open_ptr=open_ptr->next;
		open_ptr->next=NULL;
		
		open_ptr->brd=&temp_state;
	}
	////reset initial state for next call///
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				temp_state.state[i][j]=initial_state.state[i][j];
				if(initial_state.state[i][j]==0){
					temp_state.posx=i;
					temp_state.posy=j;
				}
			
			}
		}
	//////////////////done///////////////////
}
/********************************************************************/
bool search::pop(){
open_ptr=open_start->next;
////temp state = state of open//////
	for(int i=0;i<3;i++){
		for(int j=0; j<3;j++){
			temp_state.state[i][j]=open_start->brd->state[i][j];
		}	
	}
//////////////done//////////////////
//push the poped state into closed////
if(closed_start==NULL){
	closed_start=new linked_list;
	closed_ptr=closed_start;
	closed_ptr->next=NULL;
	closed_ptr->brd=open_start->brd;
}
else{
	closed_ptr->next =new linked_list;
	closed_ptr=closed_ptr->next;
	closed_ptr->brd=open_start->brd;
	closed_ptr->next=NULL;
}
//////////////done///////////////////

/////////delete the node from open/////////////
delete(open_start);
open_start=open_ptr;
///////////////////done//////////////////

//set intial state for recurrsion////
for(int i=0;i<3;i++){
	for(int j=0;j<3;j++){
		initial_state.state[i][j]=temp_state.state[i][j];
	}
}
/////////////done///////////////////
}
/*********************************************************************/
bool search::closed(){
bool found;
	for(closed_ptr=closed_start;closed_ptr!=NULL;closed_ptr=closed_ptr->next){
		found=true;
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				if(closed_ptr->brd->state[i][j]!=temp_state.state[i][j]){
					found=false;
				}
			}
		}
		if(found){
			return true;
		}
	
	}
return false;
}
