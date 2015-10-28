#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

#define ITERATIONS	100
#define	MIN_ERROR	0.02
#define INPUTS		2		//inputs to the node
class NN_node{
	float data[INPUTS];
	float weight[INPUTS];
public:
	int in_data[INPUTS], out_data;
	NN_node();
	void node_function();
	friend class NN;
};

class NN{
	int training_set[4][3];
	NN_node node;
public:
	NN();
	void modify_weight();
	void solve();
};
int main(){
NN neural_net;

return 0;
}

NN::NN(){
	srand(time(NULL));
	training_set[0][0]=-1;
	training_set[0][1]=-1;
	training_set[0][2]=-1;
	
	training_set[1][0]=-1;
	training_set[1][1]=1;
	training_set[1][2]=-1;
	
	training_set[2][0]=1;
	training_set[2][1]=-1;
	training_set[2][2]=-1;
	
	training_set[3][0]=1;
	training_set[3][1]=1;
	training_set[3][2]=1;
}

void NN::solve(){
	int cntr=0;
	float error=0;
	do{
		error=0;
		for(int i=0;i<4;i++){		//for each of the training data
			for(int j=0;j<2;j++){	//for each input
				node.in_data[j]=training_set[i][j];
			}
			node.node_function();
			error+=pow(node.out_data-training_set[i][2],2);
		}
		error=sqrt(error);			//mean square error
		modify_weight();
		cntr++;
	}while(cntr<ITERATIONS&&error>MIN_ERROR);
	display();
}

NN_node::NN_node(){
	for(int i=0;i<INPUTS;i++){
		in_data[i]=out_data=data[i]=0;
		weight[i]=(float)(rand()%10000)/10000;
	}
	
}