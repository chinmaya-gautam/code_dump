#include <iostream>

using namespace std;

int main(){

  int player,coins,cpu_coins,coins_picked;
  bool turn;
  cout<<"play as player 1 or player2?";
  cin>>player;
  if(player==1) turn=true;
  coins=10;
  while(coins>0){
    if(turn){
      cout<<"\n\npick up your coins: ";
      cin>>coins_picked;
      coins-=coins_picked;
      turn=false;
    }
    else{
      if(coins%3==0){
	cpu_coins=2;
      }
      else{
	cpu_coins=1;
      }
      cout<<"\n\ncpu pics "<<cpu_coins<<" coins\n";
      coins-=cpu_coins;
      turn=true;
      
    }
  }
  if(turn){cout<<"\nyou win\n";}
  else{cout<<"\nyou lose\n";}
  return 0;
}