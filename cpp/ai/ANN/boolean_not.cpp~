 /*******************************************************************************
 * 			ARTIFICIAL NEURAL NETWORK				*
 * 				BOOLEAN not					*
 * *****************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>

#define NUM_LAYERS 	1
#define NUM_NEURONS 	1

using namespace std;

  void update_weights(double,double);
  double weight;
  
//$$$$$$$$$$$$$$$$$$$$$$$$$ THE NEURON OBJECT DEFINITION $$$$$$$$$$$$$$$$$$$$$$$$$
class neuron{
  int result;
public:
  double inputs;
  neuron();
  ~neuron();
  void input(double);
  void node_function();
  double output();
};

//######################### THE MAIN FUNCTION #####################################
int main(){
neuron layer[NUM_LAYERS][NUM_NEURONS];
bool trained;
int cntr,result;
double error=0;
/*----------------------input set------------------------*/
double input_set[2]={-1,1};

/*----------------output set for training -----------------*/
double training_set[2]={1,-1};
cntr=1;
while(1){
  cout<<"\n\t iteration: "<<cntr++<<"\n\n";
  trained=true;
  
  for(int i=0;i<2;i++){
    layer[0][0].input(input_set[i]);
    layer[0][0].node_function();
    result=layer[0][0].output();
    cout<<result;
    if(result != training_set[i]) {trained=false; cout<<": no match\n";system("sleep 2");error+=training_set[i]-result;}
    else{ cout<<": match\n";system("sleep 2");error+=training_set[i]-result;}		//delete this statement
  }
  if(trained) break;
  cout<<"\nupdating with error: "<<error<<endl;
  update_weights(-error/4,layer[0][0].inputs);
 
}
return 0;
}

neuron::neuron(){
  inputs=0;
  srand(time(NULL));
  weight=-rand()/(double)10000000000;
  cout<<"\n\n the weights are: "<<weight<<endl;
}

neuron::~neuron(){
  cout<<endl;
}

void neuron::input(double args){
  this->inputs=args;
}

double neuron::output(){
  return result;
}

void neuron::node_function(){
  result=((int)(inputs*weight))<=0?-1:1;
  cout<<"\nresult: "<<result<<" input: "<<inputs<<" weight: "<<weight<<endl;
  
}

void update_weights(double e,double inputs){
  weight+= e*inputs;
  system("clear");
  cout<<"\nweight: "<<weight;
  
}