#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <cmath>

using namespace std;
/*custom macros*/
#define distance(x1,y1,x2,y2) sqrt(((x2)-(x1))*((x2)-(x1)) + ((y2)-(y1))*((y2)-(y1)))

/*configuration parameters*/
#define COLOR 2				//ranges from 2 to 7
#define LENGTH 6			//initial length of the snake
#define BOARD_ROWS 30		//number of rows in board
#define BOARD_COLS 30		//number of columns in board
#define MAX_SNAKES 6		//maximum number of snakes allowed max=6

enum direction{east,north,west,south};


struct body{
	int posx,posy,identity;
	body *next;
};

class board{
	int food_x,food_y,nutrition;				//position of food and its value(2 TO 7)
	public:
	char mat[BOARD_ROWS][BOARD_COLS];			//the board matrix
	board();
	~board();
	
	void print_board();
	void request_food();
	
	friend class snake;
}bd;
class snake{
	int length;						//length of the snake
	int dir,identity;										//direction of the movement of the snake E W N S,identity of snake
	body *head,*tail,*ptr;
public:
	snake(int);
	~snake();
	bool turn();
	bool move_snake(char);
	int next_direction();
};
int main(){
	snake *snakes[MAX_SNAKES];
	int num_snakes;
	srand(time(NULL));
	
	do{cout<<"how many snakes?(minimum of 1 maximum of "<<MAX_SNAKES<<"): ";
	cin>>num_snakes;
	}while(num_snakes<1||num_snakes>MAX_SNAKES);
	
	for(int i=0;i<num_snakes;i++){
		snakes[i]=new snake(i);
	}
	while(true){
		bd.print_board();
		
		for(int i=0;i<num_snakes;i++){
			/*if(!snakes[i]->turn()){
			//	cout<<"one snake died";
				//system("sleep 3");
			}*/
			snakes[i]->turn();
		}
		system("sleep 0.05");	
	}
	return 0;
}
board::board(){
	food_x=rand()%BOARD_ROWS;
	food_y=rand()%BOARD_COLS;
	nutrition=2+rand()%6;
		
	for(int i=0;i<BOARD_ROWS;i++)
	for(int j=0;j<BOARD_COLS;j++){
		if(i==food_x&&j==food_y){
			mat[i][j]='X';
		}
		else{
			mat[i][j]='.';
		}
	}
		
		
}

board::~board(){
	cout<<"\033[44m GAME OVER\033[0m";
	cout<<"\nresults:\t all done\n";
}

void board::print_board(){
	system("clear");
	for(int i=0;i<BOARD_ROWS;i++){
		for(int j=0;j<BOARD_COLS;j++){
			switch(mat[i][j]){
				case 'A':cout<<"\033[04"<<COLOR<<"m  \033[0m";
						break;
				case 'B':cout<<"\033[04"<<COLOR+1<<"m  \033[0m";
						break;
				case 'C':cout<<"\033[04"<<COLOR+2<<"m  \033[0m";
						break;
				case 'D':cout<<"\033[04"<<COLOR+3<<"m  \033[0m";
						break;
				case 'E':cout<<"\033[04"<<COLOR+4<<"m  \033[0m";
						break;
				case 'F':cout<<"\033[04"<<COLOR+5<<"m  \033[0m";
						break;
				case 'X':cout<<"\033[04"<<nutrition<<"m  \033[0m";
						break;
				default:cout<<". ";
						break;
			}
		}
		cout<<"\n";
	}
}

void board::request_food(){
	do{
		food_x=rand()%(BOARD_ROWS-1);
		food_y=rand()%(BOARD_COLS-1);
	}while(mat[food_x][food_y]!='.');
	mat[food_x][food_y]='X';
}

snake::snake(int num){
	identity=num;
	
	head=new body;
	ptr=head;
	for(int i=0;i<LENGTH-1;i++){
		ptr->next=new body;
		ptr=ptr->next;
	}
	tail=ptr;
	tail->next=NULL;
	ptr=head;
	bool available=true;
	
	do{
		head->posx=2+rand()%(BOARD_ROWS - 2);
		head->posy=2+rand()%(BOARD_COLS - 2);
		dir=rand()%4;
		dir=0;//chose snake to moved in fixed direction:east
		if(bd.mat[head->posx][head->posy]!='.'){available=false;}
		else{
			switch(dir){
				case east:
					if(bd.mat[head->posx][head->posy-1]!='.'&&bd.mat[head->posx][head->posy-2]!='.'){
						available=false;
					}
					else{
						bd.mat[head->posx][head->posy]='A'+num;
						bd.mat[head->posx][head->posy-1]='A'+num;
						bd.mat[head->posx][head->posy-2]='A'+num;
					
						head->identity='A'+num;
						head->next->posx=head->posx;
						head->next->posy=head->posy-1;
						head->identity='A'+num;
						head->next->next->posx=head->posx;
						head->next->next->posy=head->posy-2;
						head->identity='A'+num;
					}
					break;
				case north:
					if(bd.mat[head->posx+1][head->posy]!='.'&&bd.mat[head->posx+2][head->posy]!='.'){
						available=false;
					}
					else{
						bd.mat[head->posx][head->posy]='A'+num;
						bd.mat[head->posx+1][head->posy]='A'+num;
						bd.mat[head->posx+2][head->posy]='A'+num;
						head->identity='A'+num;
						head->next->posx=head->posx+1;
						head->next->posy=head->posy;
						head->identity='A'+num;
						head->next->next->posx=head->posx+2;
						head->next->next->posy=head->posy;
						head->identity='A'+num;
					}
					break;
				case west:
					if(bd.mat[head->posx][head->posy+1]!='.'&&bd.mat[head->posx][head->posy+2]!='.'){
						available=false;
						}
					else{
						bd.mat[head->posx][head->posy]='A'+num;
						bd.mat[head->posx][head->posy+1]='A'+num;
						bd.mat[head->posx][head->posy+2]='A'+num;
						head->identity='A'+num;
						head->next->posx=head->posx;
						head->next->posy=head->posy+1;
						head->identity='A'+num;
						head->next->next->posx=head->posx;
						head->next->next->posy=head->posy+2;
						head->identity='A'+num;
					}
					break;
				case south:
					if(bd.mat[head->posx-1][head->posy]!='.'&&bd.mat[head->posx-2][head->posy]!='.'){
						available=false;
					}
					else{
						bd.mat[head->posx][head->posy]='A'+num;
						bd.mat[head->posx-1][head->posy]='A'+num;
						bd.mat[head->posx-2][head->posy]='A'+num;
						head->identity='A'+num;
						head->next->posx=head->posx-1;
						head->next->posy=head->posy;
						head->identity='A'+num;
						head->next->next->posx=head->posx-2;
						head->next->next->posy=head->posy;
						head->identity='A'+num;
					}
					break;
			}
		}
	}while(!available);
}
snake::~snake(){
	cout<<"\n a snake died\n";
}

bool snake::turn(){
bool moved=true;
	/*move snake,eat food,grow,die*/
	/*the direction of movement should be decided by AI*/
	int direction=rand()%3;
	direction=next_direction();
	//select fixed direction:
	//direction=0;	//forward;
	switch(direction){
		case 0:moved=move_snake('F');
			break;
		case 1:moved=move_snake('L');
			break;
		case 2:moved=move_snake('R');
			break;
	}
	return moved;
}

bool snake::move_snake(char direction){
	bool eat=false;
	int tempx,tempy;
	switch(dir){
		case east:switch(direction){
					case 'F':
						if(head->posy==BOARD_COLS-1){
								if(bd.mat[head->posx][0]!='X'&&bd.mat[head->posx][0]!='.'){return false;}
								if(bd.mat[head->posx][0]=='X'){
									eat=true;
									tail->next=new body;
									tail=tail->next;
									tail->next=NULL;
									length++;
									}
								else{
									eat=false;
									bd.mat[tail->posx][tail->posy]='.';
								}
								bd.mat[head->posx][0]='A'+identity;
								tempx=head->posx;
								tempy=head->posy;
								for(ptr=head;ptr!=tail;ptr=ptr->next){
									swap(ptr->next->posx,tempx);
									swap(ptr->next->posy,tempy);
									ptr->next->identity=ptr->identity;
								}
								head->posy=0;
							}
							else{
								if(bd.mat[head->posx][head->posy+1]!='X'&&bd.mat[head->posx][head->posy+1]!='.'){
									return false;
								}
								if(bd.mat[head->posx][head->posy+1]=='X'){
									eat=true;
									tail->next=new body;
									tail=tail->next;
									tail->next=NULL;
									length++;
									}
								else{
									eat=false;
									bd.mat[tail->posx][tail->posy]='.';
									
								}
								bd.mat[head->posx][head->posy+1]='A'+identity;
								tempx=head->posx;
								tempy=head->posy;
								for(ptr=head;ptr!=tail;ptr=ptr->next){
									swap(ptr->next->posx,tempx);
									swap(ptr->next->posy,tempy);
									ptr->next->identity=ptr->identity;
								}
								head->posy=head->posy+1;
							}
							if(eat){
								bd.request_food();
							}
							break; 
							
					case 'L': dir=north;
						if(head->posx==0){
								if(bd.mat[BOARD_ROWS-1][head->posy]!='X'&&bd.mat[BOARD_ROWS-1][head->posy]!='.'){return false;}
								if(bd.mat[BOARD_ROWS-1][head->posy]=='X'){
									eat=true;
									tail->next=new body;
									tail=tail->next;
									tail->next=NULL;
									length++;
									}
								else{
									eat=false;
									bd.mat[tail->posx][tail->posy]='.';
								}
								bd.mat[BOARD_ROWS-1][head->posy]='A'+identity;
								tempx=head->posx;
								tempy=head->posy;
								for(ptr=head;ptr!=tail;ptr=ptr->next){
									swap(ptr->next->posx,tempx);
									swap(ptr->next->posy,tempy);
									ptr->next->identity=ptr->identity;
								}
								head->posx=BOARD_ROWS-1;
							}
							else{
								if(bd.mat[head->posx-1][head->posy]!='X'&&bd.mat[head->posx-1][head->posy]!='.'){return false;}
								if(bd.mat[head->posx-1][head->posy]=='X'){
									eat=true;
									tail->next=new body;
									tail=tail->next;
									tail->next=NULL;
									length++;
									}
								else{
									eat=false;
									bd.mat[tail->posx][tail->posy]='.';
								}
								bd.mat[head->posx-1][head->posy]='A'+identity;
							tempx=head->posx;
								tempy=head->posy;
								for(ptr=head;ptr!=tail;ptr=ptr->next){
									swap(ptr->next->posx,tempx);
									swap(ptr->next->posy,tempy);
									ptr->next->identity=ptr->identity;
								}	head->posx=head->posx-1;
							}
							if(eat){
								bd.request_food();
							}
							break;
					case 'R':dir=south;
					if(head->posx==BOARD_ROWS-1){
								if(bd.mat[0][head->posy]!='X'&&bd.mat[0][head->posy]!='.'){return false;}
								if(bd.mat[0][head->posy]=='X'){
									eat=true;
									tail->next=new body;
									tail=tail->next;
									tail->next=NULL;
									length++;
									}
								else{
									eat=false;
									bd.mat[tail->posx][tail->posy]='.';
								}
								bd.mat[0][head->posy]='A'+identity;
								tempx=head->posx;
								tempy=head->posy;
								for(ptr=head;ptr!=tail;ptr=ptr->next){
									swap(ptr->next->posx,tempx);
									swap(ptr->next->posy,tempy);
									ptr->next->identity=ptr->identity;
								}head->posx=0;
							}
							else{
								if(bd.mat[head->posx+1][head->posy]!='X'&&bd.mat[head->posx+1][head->posy]!='.'){return false;}
								if(bd.mat[head->posx+1][head->posy]=='X'){
									eat=true;
									tail->next=new body;
									tail=tail->next;
									tail->next=NULL;
									length++;
									}
								else{
									eat=false;
									bd.mat[tail->posx][tail->posy]='.';
								}
								bd.mat[head->posx+1][head->posy]='A'+identity;
								tempx=head->posx;
								tempy=head->posy;
								for(ptr=head;ptr!=tail;ptr=ptr->next){
									swap(ptr->next->posx,tempx);
									swap(ptr->next->posy,tempy);
									ptr->next->identity=ptr->identity;
								}
								head->posx=head->posx+1;
							}
							if(eat){
								bd.request_food();
							}
						break;
		}
		break;
		case north:switch(direction){
					case 'F':if(head->posx==0){
								if(bd.mat[BOARD_ROWS-1][head->posy]!='X'&&bd.mat[BOARD_ROWS-1][head->posy]!='.'){return false;}
								if(bd.mat[BOARD_ROWS-1][head->posy]=='X'){
									eat=true;
									tail->next=new body;
									tail=tail->next;
									tail->next=NULL;
									length++;
									}
								else{
									eat=false;
									bd.mat[tail->posx][tail->posy]='.';
								}
								bd.mat[BOARD_ROWS-1][head->posy]='A'+identity;
								tempx=head->posx;
								tempy=head->posy;
								for(ptr=head;ptr!=tail;ptr=ptr->next){
									swap(ptr->next->posx,tempx);
									swap(ptr->next->posy,tempy);
									ptr->next->identity=ptr->identity;
								}
								head->posx=BOARD_ROWS-1;
							}
							else{
								if(bd.mat[head->posx-1][head->posy]!='X'&&bd.mat[head->posx-1][head->posy]!='.'){return false;}
								if(bd.mat[head->posx-1][head->posy]=='X'){
									eat=true;
									tail->next=new body;
									tail=tail->next;
									tail->next=NULL;
									length++;
									}
								else{
									eat=false;
									bd.mat[tail->posx][tail->posy]='.';
								}
								bd.mat[head->posx-1][head->posy]='A'+identity;
								tempx=head->posx;
								tempy=head->posy;
								for(ptr=head;ptr!=tail;ptr=ptr->next){
									swap(ptr->next->posx,tempx);
									swap(ptr->next->posy,tempy);
									ptr->next->identity=ptr->identity;
								}
								head->posx=head->posx-1;
							}
							if(eat){
								bd.request_food();
							}
							break; 
							
					case 'L':dir=east;
						if(head->posy==0){
								if(bd.mat[head->posx][BOARD_COLS-1]!='X'&&bd.mat[head->posx][BOARD_COLS-1]!='.'){return false;}
								if(bd.mat[head->posx][BOARD_COLS-1]=='X'){
									eat=true;
									tail->next=new body;
									tail=tail->next;
									tail->next=NULL;
									length++;
									}
								else{
									eat=false;
									bd.mat[tail->posx][tail->posy]='.';
								}
								bd.mat[head->posx][BOARD_COLS-1]='A'+identity;
								tempx=head->posx;
								tempy=head->posy;
								for(ptr=head;ptr!=tail;ptr=ptr->next){
									swap(ptr->next->posx,tempx);
									swap(ptr->next->posy,tempy);
									ptr->next->identity=ptr->identity;
								}
								head->posy=BOARD_COLS-1;
							}
							else{
								if(bd.mat[head->posx][head->posy-1]!='X'&&bd.mat[head->posx][head->posy-1]!='.'){return false;}
								if(bd.mat[head->posx][head->posy-1]=='X'){
									eat=true;
									tail->next=new body;
									tail=tail->next;
									tail->next=NULL;
									length++;
									}
								else{
									eat=false;
									bd.mat[tail->posx][tail->posy]='.';
								}
								bd.mat[head->posx][head->posy-1]='A'+identity;
							tempx=head->posx;
								tempy=head->posy;
								for(ptr=head;ptr!=tail;ptr=ptr->next){
									swap(ptr->next->posx,tempx);
									swap(ptr->next->posy,tempy);
									ptr->next->identity=ptr->identity;
								}
								head->posy=head->posy-1;
							}
							if(eat){
								bd.request_food();
							}
							break;
					case 'R':dir=west;
					if(head->posy==BOARD_COLS-1){
								if(bd.mat[head->posx][0]!='X'&&bd.mat[head->posx][0]!='.'){return false;}
								if(bd.mat[head->posx][0]=='X'){
									eat=true;
									tail->next=new body;
									tail=tail->next;
									tail->next=NULL;
									length++;
									}
								else{
									eat=false;
									bd.mat[tail->posx][tail->posy]='.';
								}
								bd.mat[head->posx][0]='A'+identity;
								tempx=head->posx;
								tempy=head->posy;
								for(ptr=head;ptr!=tail;ptr=ptr->next){
									swap(ptr->next->posx,tempx);
									swap(ptr->next->posy,tempy);
									ptr->next->identity=ptr->identity;
								}
								head->posx=0;
							}
							else{
								if(bd.mat[head->posx][head->posy+1]!='X'&&bd.mat[head->posx][head->posy+1]!='.'){return false;}
								if(bd.mat[head->posx][head->posy+1]=='X'){
									eat=true;
									tail->next=new body;
									tail=tail->next;
									tail->next=NULL;
									length++;
									}
								else{
									eat=false;
									bd.mat[tail->posx][tail->posy]='.';
								}
								bd.mat[head->posx][head->posy+1]='A'+identity;
								tempx=head->posx;
								tempy=head->posy;
								for(ptr=head;ptr!=tail;ptr=ptr->next){
									swap(ptr->next->posx,tempx);
									swap(ptr->next->posy,tempy);
									ptr->next->identity=ptr->identity;
								}
								head->posy=head->posy+1;
							}
							if(eat){
								bd.request_food();
							}
						break;
		}break;
		case west:switch(direction){
					case 'F':if(head->posy==0){
								if(bd.mat[head->posx][BOARD_COLS-1]!='X'&&bd.mat[head->posx][BOARD_COLS-1]!='.'){return false;}
								if(bd.mat[head->posx][BOARD_COLS-1]=='X'){
									eat=true;
									tail->next=new body;
									tail=tail->next;
									tail->next=NULL;
									length++;
									}
								else{
									eat=false;
									bd.mat[tail->posx][tail->posy]='.';
								}
								bd.mat[head->posx][BOARD_COLS-1]='A'+identity;
								tempx=head->posx;
								tempy=head->posy;
								for(ptr=head;ptr!=tail;ptr=ptr->next){
									swap(ptr->next->posx,tempx);
									swap(ptr->next->posy,tempy);
									ptr->next->identity=ptr->identity;
								}
								head->posy=BOARD_COLS-1;
							}
							else{
								if(bd.mat[head->posx][head->posy-1]!='X'&&bd.mat[head->posx][head->posy-1]!='.'){return false;}
								if(bd.mat[head->posx][head->posy-1]=='X'){
									eat=true;
									tail->next=new body;
									tail=tail->next;
									tail->next=NULL;
									length++;
									}
								else{
									eat=false;
									bd.mat[tail->posx][tail->posy]='.';
								}
								bd.mat[head->posx][head->posy-1]='A'+identity;
							tempx=head->posx;
								tempy=head->posy;
								for(ptr=head;ptr!=tail;ptr=ptr->next){
									swap(ptr->next->posx,tempx);
									swap(ptr->next->posy,tempy);
									ptr->next->identity=ptr->identity;
								}
								head->posy=head->posy-1;
							}
							if(eat){
								bd.request_food();
							}
							break; 
							
					case 'L':dir=south;
					if(head->posx==BOARD_ROWS-1){
								if(bd.mat[0][head->posy]!='X'&&bd.mat[0][head->posy]!='.'){return false;}
								if(bd.mat[0][head->posy]=='X'){
									eat=true;
									tail->next=new body;
									tail=tail->next;
									tail->next=NULL;
									length++;
									}
								else{
									eat=false;
									bd.mat[tail->posx][tail->posy]='.';
								}
								bd.mat[0][head->posy]='A'+identity;
								tempx=head->posx;
								tempy=head->posy;
								for(ptr=head;ptr!=tail;ptr=ptr->next){
									swap(ptr->next->posx,tempx);
									swap(ptr->next->posy,tempy);
									ptr->next->identity=ptr->identity;
								}
								head->posx=0;
							}
							else{
								if(bd.mat[head->posx+1][head->posy]!='X'&&bd.mat[head->posx+1][head->posy]!='.'){return false;}
								if(bd.mat[head->posx+1][head->posy]=='X'){
									eat=true;
									tail->next=new body;
									tail=tail->next;
									tail->next=NULL;
									length++;
									}
								else{
									eat=false;
									bd.mat[tail->posx][tail->posy]='.';
								}
								bd.mat[head->posx+1][head->posy]='A'+identity;
								tempx=head->posx;
								tempy=head->posy;
								for(ptr=head;ptr!=tail;ptr=ptr->next){
									swap(ptr->next->posx,tempx);
									swap(ptr->next->posy,tempy);
									ptr->next->identity=ptr->identity;
								}
								head->posx=head->posx+1;
							}
							if(eat){
								bd.request_food();
							}
							break;
					case 'R':dir=north;
					if(head->posx==0){
								if(bd.mat[BOARD_ROWS-1][head->posy]!='X'&&bd.mat[BOARD_ROWS-1][head->posy]!='.'){return false;}
								if(bd.mat[BOARD_ROWS-1][head->posy]=='X'){
									eat=true;
									tail->next=new body;
									tail=tail->next;
									tail->next=NULL;
									length++;
									}
								else{
									eat=false;
									bd.mat[tail->posx][tail->posy]='.';
								}
								bd.mat[BOARD_ROWS-1][head->posy]='A'+identity;
								tempx=head->posx;
								tempy=head->posy;
								for(ptr=head;ptr!=tail;ptr=ptr->next){
									swap(ptr->next->posx,tempx);
									swap(ptr->next->posy,tempy);
									ptr->next->identity=ptr->identity;
								}
								head->posx=BOARD_ROWS-1;
							}
							else{
								if(bd.mat[head->posx-1][head->posy]!='X'&&bd.mat[head->posx-1][head->posy]!='.'){return false;}
								if(bd.mat[head->posx-1][head->posy]=='X'){
									eat=true;
									tail->next=new body;
									tail=tail->next;
									tail->next=NULL;
									length++;
									}
								else{
									eat=false;
									bd.mat[tail->posx][tail->posy]='.';
								}
								bd.mat[head->posx-1][head->posy]='A'+identity;
								tempx=head->posx;
								tempy=head->posy;
								for(ptr=head;ptr!=tail;ptr=ptr->next){
									swap(ptr->next->posx,tempx);
									swap(ptr->next->posy,tempy);
									ptr->next->identity=ptr->identity;
								}
								head->posx=head->posx-1;
							}
							if(eat){
								bd.request_food();
							}
						break;
		}break;
		case south:switch(direction){
					case 'F':if(head->posx==BOARD_ROWS-1){
								if(bd.mat[0][head->posy]!='X'&&bd.mat[0][head->posy]!='.'){return false;}
								if(bd.mat[0][head->posy]=='X'){
									eat=true;
									tail->next=new body;
									tail=tail->next;
									tail->next=NULL;
									length++;
									}
								else{
									eat=false;
									bd.mat[tail->posx][tail->posy]='.';
								}
								bd.mat[0][head->posy]='A'+identity;
								tempx=head->posx;
								tempy=head->posy;
								for(ptr=head;ptr!=tail;ptr=ptr->next){
									swap(ptr->next->posx,tempx);
									swap(ptr->next->posy,tempy);
									ptr->next->identity=ptr->identity;
								}
								head->posx=0;
							}
							else{
								if(bd.mat[head->posx+1][head->posy]!='X'&&bd.mat[head->posx+1][head->posy]!='.'){return false;}
								if(bd.mat[head->posx+1][head->posy]=='X'){
									eat=true;
									tail->next=new body;
									tail=tail->next;
									tail->next=NULL;
									length++;
									}
								else{
									eat=false;
									bd.mat[tail->posx][tail->posy]='.';
								}
								bd.mat[head->posx+1][head->posy]='A'+identity;
								tempx=head->posx;
								tempy=head->posy;
								for(ptr=head;ptr!=tail;ptr=ptr->next){
									swap(ptr->next->posx,tempx);
									swap(ptr->next->posy,tempy);
									ptr->next->identity=ptr->identity;
								}
								head->posx=head->posx+1;
							}
							break;
					case 'L':dir=east;
					if(head->posy==BOARD_COLS-1){
								if(bd.mat[head->posx][0]!='X'&&bd.mat[head->posx][0]!='.'){return false;}
								if(bd.mat[head->posx][0]=='X'){
									eat=true;
									tail->next=new body;
									tail=tail->next;
									tail->next=NULL;
									length++;
									}
								else{
									eat=false;
									bd.mat[tail->posx][tail->posy]='.';
								}
								bd.mat[head->posx][0]='A'+identity;
								tempx=head->posx;
								tempy=head->posy;
								for(ptr=head;ptr!=tail;ptr=ptr->next){
									swap(ptr->next->posx,tempx);
									swap(ptr->next->posy,tempy);
									ptr->next->identity=ptr->identity;
								}
								head->posx=0;
							}
							else{
								if(bd.mat[head->posx][head->posy+1]!='X'&&bd.mat[head->posx][head->posy+1]!='.'){return false;}
								if(bd.mat[head->posx][head->posy+1]=='X'){
									eat=true;
									tail->next=new body;
									tail=tail->next;
									tail->next=NULL;
									length++;
									}
								else{
									eat=false;
									bd.mat[tail->posx][tail->posy]='.';
								}
								bd.mat[head->posx][head->posy+1]='A'+identity;
								tempx=head->posx;
								tempy=head->posy;
								for(ptr=head;ptr!=tail;ptr=ptr->next){
									swap(ptr->next->posx,tempx);
									swap(ptr->next->posy,tempy);
									ptr->next->identity=ptr->identity;
								}
								head->posy=head->posy+1;
							}
							if(eat){
								bd.request_food();
							}
						break;
					case 'R':dir=west;
					if(head->posy==0){
								if(bd.mat[head->posx][BOARD_COLS-1]!='X'&&bd.mat[head->posx][BOARD_COLS-1]!='.'){return false;}
								if(bd.mat[head->posx][BOARD_COLS-1]=='X'){
									eat=true;
									tail->next=new body;
									tail=tail->next;
									tail->next=NULL;
									length++;
									}
								else{
									eat=false;
									bd.mat[tail->posx][tail->posy]='.';
								}
								bd.mat[head->posx][BOARD_COLS-1]='A'+identity;
								tempx=head->posx;
								tempy=head->posy;
								for(ptr=head;ptr!=tail;ptr=ptr->next){
									swap(ptr->next->posx,tempx);
									swap(ptr->next->posy,tempy);
									ptr->next->identity=ptr->identity;
								}
								head->posy=BOARD_COLS-1;
							}
							else{
								if(bd.mat[head->posx][head->posy-1]!='X'&&bd.mat[head->posx][head->posy-1]!='.'){return false;}
								if(bd.mat[head->posx][head->posy-1]=='X'){
									eat=true;
									tail->next=new body;
									tail=tail->next;
									tail->next=NULL;
									length++;
									}
								else{
									eat=false;
									bd.mat[tail->posx][tail->posy]='.';
								}
								bd.mat[head->posx][head->posy-1]='A'+identity;
								tempx=head->posx;
								tempy=head->posy;
								for(ptr=head;ptr!=tail;ptr=ptr->next){
									swap(ptr->next->posx,tempx);
									swap(ptr->next->posy,tempy);
									ptr->next->identity=ptr->identity;
								}
								head->posy=head->posy-1;
							}
							if(eat){
								bd.request_food();
							}
							break;
		}break;
	}
	return true;
	
}
int snake::next_direction(){
	int nxt_x,nxt_y,best_x,best_y,move;
	best_x=head->posx;
	best_y=head->posy;
	move=0;
	for(int move_direction=0;move_direction<3;move_direction++){
		switch(dir){
			case east:switch(move_direction){
						case 0:if(head->posy==BOARD_COLS-1){nxt_y=0;}
								else{nxt_y=head->posy+1;}
								nxt_x=head->posx;
								break;
						case 1:if(head->posx==0){nxt_x=BOARD_ROWS-1;}
								else{nxt_x=head->posx-1;}
								nxt_y=head->posy;
								break;
						case 2:if(head->posx==BOARD_ROWS-1){nxt_x=0;}
								else{nxt_x=head->posx+1;}
								nxt_y=head->posy;
								break;
					}
					break;
			case north:switch(move_direction){
						case 0:if(head->posx==0){nxt_x=BOARD_ROWS-1;}
								else{nxt_x=head->posx-1;}
								nxt_y=head->posy;
								break;
						case 1:if(head->posy==0){nxt_y=BOARD_COLS-1;}
								else{nxt_y=head->posy-1;}
								nxt_x=head->posx;
								break;
						case 2:if(head->posy==BOARD_COLS-1){nxt_y=0;}
								else{nxt_y=head->posy+1;}
								nxt_x=head->posx;
								break;
					}
					break;
			case west:switch(move_direction){
						case 0:if(head->posy==0){nxt_y=BOARD_COLS-1;}
								else{nxt_y=head->posy-1;}
								nxt_x=head->posx;
								break;
						case 1:if(head->posx==BOARD_ROWS-1){nxt_x=0;}
								else{nxt_x=head->posx+1;}
								nxt_y=head->posy;
								break;
						case 2:if(head->posx==0){nxt_x=BOARD_ROWS-1;}
								else{nxt_x=head->posx-1;}
								nxt_y=head->posy;
								break;
					}
					break;
			case south:switch(move_direction){
						case 0:if(head->posx==BOARD_ROWS-1){nxt_x=0;}
								else{nxt_x=head->posx+1;}
								nxt_y=head->posy;
								break;
						case 1:if(head->posy==BOARD_COLS-1){nxt_y=0;}
								else{nxt_y=head->posy+1;}
								nxt_x=head->posx;
								break;
						case 2:if(head->posy==0){nxt_y=BOARD_COLS-1;}
								else{nxt_y=head->posy-1;}
								nxt_x=head->posx;
								break;
					}
					break;
		}
	if(distance(bd.food_x,bd.food_y,best_x,best_y)>distance(bd.food_x,bd.food_y,nxt_x,nxt_y)){
	best_x=nxt_x;
	best_y=nxt_y;
	if(bd.mat[best_x][best_y]=='.'||bd.mat[best_x][best_y]=='X')
	move=move_direction;
	}
		
	}
	
	return move;
}