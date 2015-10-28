#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>

using namespace std;

#define MAX_ERROR			0.002
#define TRAINING_RECORDS	4
#define TRAINING_INPUTS		2
#define MAX_NODE_INPUTS		100
#define MAX_ITERATIONS		100
#define INODES				2
class neural_unit{
	
	double data[MAX_NODE_INPUTS];
public:
	int inputs;
	double in_data[MAX_NODE_INPUTS],out_data;
	double weights[MAX_NODE_INPUTS];
	void node_function();
	double bias;
	neural_unit();
};

class input_node:public neural_unit{
public:
	input_node();
};
class output_node:public neural_unit{
public:
	output_node();
};
class hidden_node:public neural_unit{
public:
	hidden_node();
};

class neural_network{
output_node onode;
input_node inode[2];
int training_set[TRAINING_RECORDS][TRAINING_INPUTS+1];
double weights[9];
double error;
double errors[TRAINING_RECORDS];
int outputs[TRAINING_RECORDS];
double bias[3];					//3 total nodes
double alpha;

public:
	bool is_error();
	neural_network();
	void iterate();
	void modify_weights(int i);
	void calculate_error(int i);
	void mean_error();
	void print(int i);
};

int main(){
	neural_network ANN;
	int cntr=0;
	do{
		cntr++;
		ANN.iterate();
		cout<<"\n";
	}while(ANN.is_error()&&cntr<MAX_ITERATIONS);
return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////
neural_unit::neural_unit(){}
input_node::input_node(){}
output_node::output_node(){}
neural_network::neural_network(){
	training_set[0][0]=0;
	training_set[0][1]=0;
	training_set[0][2]=0;
	
	training_set[1][0]=0;
	training_set[1][1]=1;
	training_set[1][2]=1;
	
	training_set[2][0]=1;
	training_set[2][1]=0;
	training_set[2][2]=1;
	
	training_set[3][0]=1;
	training_set[3][1]=1;
	training_set[3][2]=0;
	
	for(int i=0;i<3;bias[i++]=1);
	
	for(int i=0;i<9;i++){
		weights[i]=((float)rand()/RAND_MAX);
	}
	
	alpha=0.05;
	
	
}

void neural_network::iterate(){
	onode.inputs=TRAINING_INPUTS+1;
	inode[0].inputs=inode[1].inputs=TRAINING_INPUTS+1;
	int wt=0;
	
	for(int i=0;i<TRAINING_RECORDS;i++){
		for(int node=0;node<INODES;node++){			//for each input node
			for(int j=0;j<TRAINING_INPUTS;j++){
				inode[node].in_data[j]=training_set[i][j];
				inode[node].weights[j]=weights[wt++];
			}
			inode[node].in_data[TRAINING_INPUTS]=bias[node];
			inode[node].weights[TRAINING_INPUTS]=weights[wt++];
			inode[node].node_function();
		}
		//onode
		for(int j=0;j<INODES;j++){
			onode.in_data[j]=inode[j].out_data;
			onode.weights[j]=weights[wt++];
		}
		onode.in_data[TRAINING_INPUTS]=bias[2];
		onode.weights[TRAINING_INPUTS]=weights[TRAINING_INPUTS];
		
		onode.node_function();
		calculate_error(i);
		modify_weights(i);
		outputs[i]=onode.out_data;
		print(i);
	}
	mean_error();
}

bool neural_network::is_error(){
	if(error>MAX_ERROR){
		return true;
	}
	else{
		return false;
	}
}

void neural_unit::node_function(){
	double output=0;
	for(int i=0;i<inputs;i++){
		output+=in_data[i]*weights[i];
	}
	//hardlim
	if(output>0){
		out_data=1;
	}
	else{
		out_data=0;
	}
}

void neural_network::calculate_error(int i){
	errors[i]=training_set[i][TRAINING_INPUTS]-onode.out_data;
	errors[i]*=alpha;
	
}
void neural_network::mean_error(){
	error=0;
	for(int i=0;i<TRAINING_RECORDS;i++){
		error+=pow((errors[i]),2);
	}
	error=sqrt(error);
	error/=4;
}
void neural_network::modify_weights(int i){
	for(int u=0;u<3;u++){		//for each node
		for(int j=0;j<TRAINING_INPUTS;j++){
			weights[u*3+j]+=errors[i]*training_set[i][j];
		}
	weights[u*3+TRAINING_INPUTS]+=errors[i]*bias[u];
	}
	
}

void neural_network::print(int i){
	
	printf("|%2d\t%2d |\t%5.2f\t%5.2f\t%5.2f |\t%2d\t%2d\t%5.2f |\t%5.2f\t%5.2f\t%5.2f|\n",
		   training_set[i][0],training_set[i][1],bias[2]*weights[2],training_set[i][0]*weights[0],training_set[i][1]*weights[1],
		   training_set[i][2],outputs[i],errors[i],weights[0],weights[1],weights[2]
  		);
	
}