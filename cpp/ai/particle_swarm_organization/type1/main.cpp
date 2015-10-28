//PSO ALGORITHM

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstdio>

using namespace std;

#define POPULATION 40
#define DIMENTIONS 12	//set according to DE' JONGS TEST CRITERION
#define Vmax		4
#define ITERATIONS 5



class base{
	int x[POPULATION][DIMENTIONS];
	int p[DIMENTIONS];
	float phi;
	float ro[DIMENTIONS];
	float v[DIMENTIONS];		//individuals predispotion towards a perticular choice;
	
public:
	base();
	void run();
	void display();
	float Sig(int);
	float G(int*);
};

int main(){
	base b;
	b.run();
	
	cout<<endl;
	return 0;
}

base::base(){
	srand(time(NULL));
	
	phi=(float)(rand()%(Vmax*10000))/10000;
	
	for(int i=0;i<DIMENTIONS;i++){
		ro[i]=(float)(rand()%10000)/10000;
		v[i]=(float)(rand()%10000)/10000;
	}
	
	for(int i=0;i<POPULATION;i++){
		for(int j=0;j<DIMENTIONS;j++){
			x[i][j]=rand()%2;
			if(i==0){
				p[j]=x[i][j];
			}
		}
	}
}

void base::run(){
	
	int g;
	int cntr=0;
	
	
	while(1){
		cntr++;
		for(int i=0;i<POPULATION;i++){
			if(G(x[i])>G(p)){
				for(int j=0;j<DIMENTIONS;j++){
					p[j]=x[i][j];
				}
			}
		
			g=i;		//arbitrary
			for(int j=0;j<POPULATION;j++){
				if(i==j) continue;
			    if(G(p)>G(x[j])){g=j;}
			}
			for(int d=0;d<DIMENTIONS;d++){
				v[d]=v[d]+phi*(p[d] - x[i][d])+(Vmax - phi)*(x[g][d] - x[i][d]);
				
				if(ro[d]<Sig(v[d])){x[i][d]=1;}
				else{x[i][d]=0;}
			}
			display();
			
		}
		cout<<"\n\n iterations: "<<cntr<<endl;
		if(cntr>ITERATIONS){break;}
		
	}
	
}

float base::Sig(int x){
	return((float)1/((float)1+(float)exp(-x)));
}

float base::G(int arr[DIMENTIONS]){
	float result=0;
	//optimize sine x
	for(int i=0;i<DIMENTIONS;i++){
		result+=arr[i]*pow(2,i);
	}
	
	result=sin((float)3.141/255*result);
	return result;
	
}

void base::display(){
	float result;
	cout<<"\n======================================================\n";
	for(int i=0;i<POPULATION;i++){
		for(int j=DIMENTIONS-1;j>=0;j--){
			cout<<x[i][j];
		}
		//calculate its equivalent decimal
		result=0;
		for(int j=0;j<DIMENTIONS;j++){
		result+=x[i][j]*pow(2,j);
		}
		printf(" (%5.0f = %2.1f pi)\n",result,result/255);
	}
	cout<<"\n======================================================\n";
	
}