//ACM - ALEXROD'S CULTURAL MODEL

#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

#define ROWS 40
#define COLS 40
#define FEATURE_LENGTH 4
#define FEATURE_RANGE_LOWER 0
#define FEATURE_RANGE_HIGHER 9
#define ITERATION_MAX	10000

class field{
	int mat[ROWS][COLS][FEATURE_LENGTH];
	int temp[ROWS][COLS][FEATURE_LENGTH];
	int initial[ROWS][COLS][FEATURE_LENGTH];
	int final[ROWS][COLS][FEATURE_LENGTH];
	public:
		field();
		void print_field();
		bool play();
		bool check_final();
};

int main(){
	srand(time(NULL));
	field fld;
	int i=0;
	while(true){
		i++;
		fld.print_field();
		fld.play();
		if(fld.check_final()||i>ITERATION_MAX){break;}
	}
	fld.print_field();
	cout<<"\n\ntotal number of iterations: "<<i<<endl;
	return 0;
}

field::field(){
	for(int i=0;i<ROWS;i++){
		for(int j=0;j<COLS;j++){
			for(int k=0;k<FEATURE_LENGTH;k++){
			mat[i][j][k]=FEATURE_RANGE_LOWER+rand()%(FEATURE_RANGE_HIGHER-FEATURE_RANGE_LOWER);
			temp[i][j][k]=mat[i][j][k];
			}
		}
	}
}

void field::print_field(){
	int color=0;
	int row_num;
	bool matched;
	int marked_number[ROWS*COLS][FEATURE_LENGTH + 1];//a list of marked numbers,last bit for color
	for(int i=0;i<ROWS;i++){
		for(int j=0;j<COLS;j++){
			row_num=COLS*i+j;
			for(int k=0;k<FEATURE_LENGTH;k++){
				marked_number[row_num][k]=mat[i][j][k];
			}
			color=color==8?0:color+1;
			marked_number[row_num][FEATURE_LENGTH]=color;
		}
	}
	for(int i=0;i<(FEATURE_LENGTH+1)*COLS;cout<<"=",i++);
	cout<<"\n";
	for(int i=0;i<ROWS;i++){
		for(int j=0;j<COLS;j++){
			
			for(int u=0;u<ROWS*COLS;u++){
				matched=true;
				for(int k=0;k<FEATURE_LENGTH;k++){
					if(mat[i][j][k]!=marked_number[u][k]){matched=false;}
				}
				if(matched){
					color=marked_number[u][FEATURE_LENGTH];
					break;
				}
			}
			for(int k=0;k<FEATURE_LENGTH;k++){
			cout<<"\033[03"<<color<<"m"<<mat[i][j][k]<<"\033[0m";
			}
			cout<<" ";
		}
		cout<<"\n";
	}
}

bool field::play(){
	int matching_bits;
	float probablity,random;
	int r,c;
	for(int i=0;i<ROWS;i++){
		for(int j=0;j<COLS;j++){
			//for each element
			for(int u=i-1;u<=i+1;u++){
				for(int v=j-1;v<=j+1;v++){
					if(u==i && v==j){continue;}
					matching_bits=0;
					r = u==-1?ROWS-1:(u==ROWS?0:u);
					c = v==-1?COLS-1:(v==COLS?0:v);
					//for all neighbours
					//calculate probablity of interaction
					for(int k=0;k<FEATURE_LENGTH;k++){
						if(mat[r][c][k]==mat[i][j][k]){
							matching_bits++;
						}
					}
					//iterate over all bits,changing them based on probablity
					for(int k=0;k<FEATURE_LENGTH;k++){
							mat[i][j][k]=mat[r][c][k];
					}
					/*//print features after iteraction
					for(int k=0;k<FEATURE_LENGTH;k++){
						cout<<mat[i][j][k];
					}
					cout<<endl;*/
				}
			}
			
		}
	}
	
}

bool field::check_final(){
	bool final=true;;
	for(int i=0;i<ROWS;i++){
		for(int j=0;j<COLS;j++){
			for(int k=0;k<FEATURE_LENGTH;k++){
				if(temp[i][j][k]!=mat[i][j][k]){
					final=false;
				}
			}
		}
	}
	if(final){return true;}
	for(int i=0;i<ROWS;i++){
		for(int j=0;j<COLS;j++){
			for(int k=0;k<FEATURE_LENGTH;k++){
				temp[i][j][k]=mat[i][j][k];
			}
		}
	}
	return false;
}