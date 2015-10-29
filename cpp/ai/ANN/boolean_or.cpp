 /*******************************************************************************
 * 			ARTIFICIAL NEURAL NETWORK				*
 * 				BOOLEAN OR					*
 * *****************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>

#define NUM_LAYERS 	1
#define NUM_NEURONS 	1

using namespace std;

  void update_weights(double,double*);
  double weight[2];
  
//$$$$$$$$$$$$$$$$$$$$$$$$$ THE NEURON OBJECT DEFINITION $$$$$$$$$$$$$$$$$$$$$$$$$
class neuron{
  int result;
public:
  double inputs[2];
  neuron();
  ~neuron();
  void input(double *);
  void node_function();
  double output();
};

//######################### THE MAIN FUNCTION #####################################
int main(){
neuron layer[NUM_LAYERS][NUM_NEURONS];
bool trained;
int cntr,result,error=0;
/*----------------------input set------------------------*/
double input_set[4][2] ={
  0,0,
  0,1,
  1,0,
  1,1
};

/*----------------output set for training -----------------*/
double training_set[4]={0,1,1,1};
cntr=1;
while(1){
  cout<<"\n\t iteration: "<<cntr++<<"\n\n";
  trained=true;
  
  for(int i=0;i<4;i++){
    layer[0][0].input(input_set[i]);
    layer[0][0].node_function();
    result=layer[0][0].output();
    cout<<result;
    if(result != training_set[i]) {trained=false; cout<<": no match\n";system("sleep 2");error+=training_set[i]-result;}
    else{ cout<<": match\n";system("sleep 2");error+=training_set[i]-result;}		//delete this statement
  }
  if(trained) break;
  update_weights((double)error/4,layer[0][0].inputs);
  error/=4;
 
}
return 0;
}

neuron::neuron(){
  inputs[0]=inputs[1]=0;
  srand(time(NULL));
  weight[0]=rand()/(double)10000000000;
  weight[1]=-(rand()/(double)10000000000);
  
  cout<<"\n\n the weights are: "<<weight[0]<<" "<<weight[1]<<endl;
}

neuron::~neuron(){
  cout<<endl;
}

void neuron::input(double *args){
  this->inputs[0]=args[0];
  this->inputs[1]=args[1];
}

double neuron::output(){
  return result;
}

void neuron::node_function(){
  result=((int)(inputs[0]*weight[0]+inputs[1]*weight[1]))==0?0:1;
  
}

void update_weights(double e,double *inputs){
  weight[0]+= e*inputs[0];
  weight[1]+= e*inputs[1];
  system("clear");
  
}