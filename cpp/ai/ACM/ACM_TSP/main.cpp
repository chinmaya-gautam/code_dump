//ACM - ALEXROD'S CULTURAL MODEL

#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

#define ROWS 20
#define COLS 20
#define FEATURE_LENGTH 8
#define FEATURE_RANGE_LOWER 0
#define FEATURE_RANGE_HIGHER 8
#define ITERATION_MAX	20
#define PENALTY 20

int distance_chart[8][8]={0,1,4,2,5,6,8,9,
						  1,0,1,5,6,7,8,3,
						  4,1,0,1,8,5,3,9,
						  2,4,1,0,1,3,8,3,
						  5,6,8,1,0,1,3,8,
						  6,7,5,3,1,0,1,3,
						  8,8,3,8,3,1,0,1,
						  9,3,9,3,8,3,1,0
};

class field{
	char mat[ROWS][COLS][FEATURE_LENGTH];
	char temp[ROWS][COLS][FEATURE_LENGTH];
	public:
		field();
		void print_field();
		bool play();
		bool check_final();
		int fitness(int ,int);
};

int main(){
	srand(time(NULL));
	field fld;
	int i=0;
	while(true){
		i++;
		fld.print_field();
		fld.play();
		if(i>ITERATION_MAX||fld.check_final()){break;}
	}
	fld.print_field();
	cout<<"\n\ntotal number of iterations: "<<i<<endl;
	return 0;
}

field::field(){
	char random;
	bool again;

	for(int i=0;i<ROWS;i++){
		for(int j=0;j<COLS;j++){
			for(int k=0;k<FEATURE_LENGTH;k++){
				again=false;
				do{
					random=(char)(FEATURE_RANGE_LOWER+rand()%(FEATURE_RANGE_HIGHER-FEATURE_RANGE_LOWER) + 65);
					for(int l=0;l<k;l++){
						if(random==mat[i][j][k]){
							again=true;
						}
					}
					mat[i][j][k]=random;
				}while(again);
			}
		}
	}
}

void field::print_field(){
	int color=0;
	int row_num;
	bool matched;
	char marked_number[ROWS*COLS][FEATURE_LENGTH + 1];//a list of marked numbers,last bit for color
	for(int i=0;i<ROWS;i++){
		for(int j=0;j<COLS;j++){
			row_num=COLS*i+j;
			for(int k=0;k<FEATURE_LENGTH;k++){
				marked_number[row_num][k]=mat[i][j][k];
			}
			color=color==8?0:color+1;
			marked_number[row_num][FEATURE_LENGTH]=(char)color;
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
					color=(int)marked_number[u][FEATURE_LENGTH];
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
	int diff1,diff2;
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
					//iterate over all bits,changing them based on probablity
					if(fitness(r,c)<fitness(i,j)){
						for(int k=0;k<FEATURE_LENGTH;k++){
							mat[i][j][k]=mat[r][c][k];
						}
					}
				
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

int field::fitness(int row,int column){
	int sum=0;
	for(int k=1;k<FEATURE_LENGTH;k++){
		sum+=distance_chart[((int)mat[row][column][k-1] - 65)][((int)mat[row][column][k] - 65)];
		for(int i=0;i<k;i++){
			if(mat[row][column][k]==mat[row][column][i]){
				sum+=PENALTY;
			}
		}
	}
	return sum;
}