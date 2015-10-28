/*/////////////////////////////////////////////////////////////////////////////////////////////
basic layout of neural network:

	input---->O-----_>0
	           \   /|  \
                \/      O---->output
               / \     /
             /   _\| /
  input--->O------>O

//////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>

#define INPUT_NODES		2
#define OUTPUT_NODES	1
#define HIDDEN_NODES	2
#define HIDDEN_LAYERS	1
#define CONNECTIONS		6	//2**2 + 2
#define ITERATIONS		100

using namespace std;

class NN_node{
protected:
	float in_data,out_data;
	float bias;
	float weight;
	
public:
	NN_node();
	void node_function();
	float get_data(float);
	float send_data();
};

class input:public NN_node{
	int in_data;
public:
	input();
	void node_function();
};

class output:public NN_node{
	int out_data;
	float weight[2];
	float in_data[2];
	int inputs;
public:
	output();
	void get_data(float);
};

class hidden:public NN_node{
float weight[2];
float in_data[2];
int inputs;
public:
	hidden();
	void get_data(float);
	void node_function();
	
};

struct network{
	int in_data[2];
	int out_data;
	input input_nodes[INPUT_NODES];
	hidden hidden_nodes[HIDDEN_LAYERS][HIDDEN_NODES];
	output output_nodes[OUTPUT_NODES];
	float connections[6];//6 connections as depicted above
	int weights[6];	//weights corresponding to each connection

};
int training_data[4][3]={
	1,1,0,
	1,0,1,
	0,1,0,
	0,0,0
};

int main(){
	network neural_net;
	int cntr=0;
	
	//initially, manually set weights:
	neural_net.weights[0]=-1;
	neural_net.weights[1]=-1;
	neural_net.weights[2]=-1;
	neural_net.weights[3]=-1;
	neural_net.weights[4]=1;
	neural_net.weights[5]=1;
	
	cout<<"\nenter initial input";
	for(int i=0;i<INPUT_NODES;i++){
		cin>>neural_net.in_data[i];
		if(neural_net.in_data[i]==0){neural_net.in_data[i]=-1;}
	
	}
	neural_net.input_nodes[0].get_data(neural_net.in_data[0]);
	neural_net.input_nodes[1].get_data(neural_net.in_data[1]);
	
	while(cntr<ITERATIONS){
		cout<<"\niteration: "<<cntr;
	//first from input node to hidden layer:
	if(HIDDEN_LAYERS!=0){
			//for input node
			for(int k=0;k<INPUT_NODES;k++){
				neural_net.input_nodes[k].node_function();
				neural_net.connections[k*2]=neural_net.connections[k*2+1]=neural_net.input_nodes[k].send_data();
			}
			//for hidden nodes
			for(int i=0;i<HIDDEN_LAYERS;i++){
				for(int j=0;j<HIDDEN_NODES;j++){
					neural_net.hidden_nodes[i][j].get_data(neural_net.connections[j*2]);
					neural_net.hidden_nodes[i][j].get_data(neural_net.connections[j*2+1]);
					neural_net.hidden_nodes[i][j].node_function();
					neural_net.connections[j+4]=neural_net.hidden_nodes[i][j].send_data();
				}
			}
			//for output nodes
			for(int i=0;i<OUTPUT_NODES;i++){
				neural_net.output_nodes[i].get_data(neural_net.connections[i+4]);
				neural_net.output_nodes[i].get_data(neural_net.connections[i+5]);
				neural_net.output_nodes[i].node_function();
			}
			neural_net.out_data=neural_net.output_nodes[0].send_data();
		
	}
		cntr++;
		if(cntr>ITERATIONS){break;}
	}
	cout<<"\n\noutput: "<<neural_net.out_data;
	cout<<endl;
return 0;
}

NN_node::NN_node(){
	in_data=0;
	out_data=0;
	bias=0;
}
input::input(){
}
hidden::hidden(){
	inputs=0;
}
output::output(){
	inputs=0;
	
}

float NN_node::get_data(float data){
	in_data=data;	
}

void NN_node::node_function(){
	out_data+=in_data*weight;
}

void input::node_function(){
	out_data=in_data;
}

float NN_node::send_data(){
	return out_data;
}

void hidden::node_function(){
	int result;
	result=in_data[0]*weight[0]+in_data[1]*weight[1];
	
/*	if()
		out_data=1*/
}


void output::get_data(float data){
	in_data[inputs++]=data;
}
void hidden::get_data(float data){
	in_data[inputs++]=data;
}