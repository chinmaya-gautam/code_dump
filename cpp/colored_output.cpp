#include <iostream>

using namespace std;

int main()
{
for (int i = 0; i <= 70; i++)
{
std::cout <<i<<" ->    \033[0;" << i << "mHello!\033[0m" << std::endl;
std::cout <<i<<" ->    \033[1;" << i << "mHello!\033[0m" << std::endl;
}

cout<<endl;
return 0;
}