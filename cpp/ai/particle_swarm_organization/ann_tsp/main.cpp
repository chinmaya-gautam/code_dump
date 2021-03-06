//PSO ALGORITHM FOR TSP

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstdio>

using namespace std;

#define POPULATION	20
#define DIMENTIONS	8
#define Vmax		4	//max velocity
#define ITERATIONS	100
#define OPTIMA		128	//for plotting,considering sin((pi/SCALE)x);
#define SCALE		255



class base{
	char x[POPULATION][DIMENTIONS];
	float history[ITERATIONS];
	int p[DIMENTIONS];
	float phi;
	float v[DIMENTIONS];		//individuals predispotion towards a perticular choice;
	
public:
	base();
	void run();
	void display();
	float Sig(int);
	float G(int*);
	void plot();
};

int main(){
	base b;
	b.run();
	
	cout<<endl;
	return 0;
}

base::base(){
	srand(time(NULL));
	cout<<"\nINITIALIZING\n";
	cout<<"\n=======================================================\n";
	phi=(float)(rand()%(Vmax*100))/100;
	cout<<"phi: "<<phi;
	cout<<"\nv: ";
	for(int i=0;i<DIMENTIONS;i++){
			v[i]=(float)(rand()%(Vmax*10000))/10000;
			cout<<v[i]<<" ";
	}
	
	for(int i=0;i<POPULATION;i++){
	cout<<"\nx("<<i+1<<") : ";
		for(int j=0;j<DIMENTIONS;j++){
			x[i][j]=rand()%SCALE;
			cout<<x[i][j]<<" ";
			if(i==0){
				p[j]=x[i][j];
			}
		}
		cout<<"\n";
	}
	cout<<"\n p:";
	for(int i=0;i<DIMENTIONS;cout<<p[i++]);
	cout<<"\n\n";
	
}

void base::run(){
	
	int g;
	int cntr=0;
	
	
	while(1){
		
		for(int i=0;i<POPULATION;i++){
			cout<<"\ncomparing: "<<x[i][0]<<" & "<<p[0];
			if(G(x[i])>G(p)){
				cout<<" better: "<<x[i][0];
				for(int j=0;j<DIMENTIONS;j++){
					p[j]=x[i][j];
				}
			}
		
			g=i;		//arbitrary
			for(int j=0;j<POPULATION;j++){
				if(i==j) continue;
			    if(G(x[g])>G(x[j])){g=j;}
			}
			for(int d=0;d<DIMENTIONS;d++){
				v[d]=v[d]+phi*(p[d] - x[i][d])+(Vmax - phi)*(x[g][d] - x[i][d]);
				v[d]=v[d]>Vmax?Vmax:v[d];
				v[d]=v[d]<-Vmax?-Vmax:v[d];
				x[i][d]=x[i][d]+v[d];
			}
			display();
			
		}
		if(cntr>ITERATIONS){plot();break;}
		cout<<"\n\n iterations: "<<cntr<<endl;
		int sum=0;
		for(int i=0;i<POPULATION;sum+=x[i++][0]);
		history[cntr]=sum/POPULATION;
	cntr++;
	}
	
}

float base::Sig(int x){
	return((float)1/((float)1+(float)exp(-x)));
}

float base::G(int arr[DIMENTIONS]){
	float result=0;
	//optimize sine x
	result=sin(((float)3.141/(float)(SCALE))*arr[0]);
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
		printf(" (%5.0f = %2.1f pi)\n",result,(float)result/(float)10);
	}
	
	cout<<"\n======================================================\n";
	
}
void base::plot(){
	int step;
	int plot_field[60][80];
	if(ITERATIONS>80){
		step=ITERATIONS/40;
	}
	else{
		step=ITERATIONS;
	}
	for(int i=0;i<60;i++){
		for(int j=0;j<80;j++){
			if(i==((int)(30-30*((float)OPTIMA)/SCALE))){
				plot_field[i][j]=2;
			}else{
				plot_field[i][j]=0;
			}
		}
	}
	for(int i=0;i<ITERATIONS;i+=step){
		plot_field[(int)(30-30*((float)history[i])/255)][i]=1;
		//cout<<history[i]<<endl;
	}
	cout<<"\n\n";
	for(int i=0;i<60;i++){
		for(int j=0;j<80;j++){
			if(plot_field[i][j]==1) cout<<"*";
			else if(plot_field[i][j]==2) cout<<"-";
			else cout<<" ";
		}
		cout<<endl;
	}
	cout<<"\n\n";
	
}
