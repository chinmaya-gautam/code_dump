#include <cstdio>
#include <algorithm>
 
using namespace std;
 
int sum[80][80];
int dp[80][80][80][80];
int x;
bool found; 
void solve(int n, int m){
found=true;
for(int i = 0; i < n; i++)
for(int j = 0; j < m ; j++){
scanf("%d", &x);
sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + x;

}

int ans = -(1<<29);
for(int i = n - 1; i >= 0; i--){
  printf("\ni= %d",i);
  for(int j = m - 1; j >= 0; j--){
  printf("\n----------\nj = %d",j);
  for(int a = i + 3; a <= n; a++){
  printf("\n~~~~~~~~~~\n\ta = %d",a);
  for(int b = j + 3; b <= m; b++){
  printf("\n####################\n\t\tb = %d\n",b);
int x1 = i + 1, y1 = j + 1, x2 = a - 1, y2 = b - 1;
int &res = dp[x1][y1][x2][y2];
res = sum[x2][y2] - sum[x2][y1] - sum[x1][y2] + sum[x1][y1];
if(x2 - x1 > 1)res = min(res, dp[x1 + 1][y1][x2][y2]);
if(x2 - x1 > 1)res = min(res, dp[x1][y1 + 1][x2][y2]);
if(y2 - y1 > 1)res = min(res, dp[x1][y1][x2 - 1][y2]);
if(y2 - y1 > 1)res = min(res, dp[x1][y1][x2][y2 - 1]);


ans = max(ans, sum[a][b] - sum[a][j] - sum[i][b] + sum[i][j] - res);
if(ans==19&&found){
  found=false;
  printf("\nvalues: %d %d %d %d %d\n",a,b,i,j,res);
  printf("\nmore values: %d %d %d %d\n",x1,x2,y1,y2);
}

  
}
}
}
}
 
printf("%d\n", ans);
}
 
int main(){
int n, m;
while(true){
scanf("%d %d", &n, &m);
if(n == 0 && m == 0)break;
solve(n, m);
}
return 0;
}