#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
  int row_min,row_max,col_min,col_max;
  int umin,vmin;
  int total=0,temp,max=0;
  int s_rows,s_columns;
  int rows,columns;
  int mat[100][100];/*={
	1,-2,3,-4,5,
	-5,4,-3,2,-1,
	1,-3,5,-7,9,
	-9,7,-5,3,-1
	};*/


	while(true){
		cin>>rows>>columns;
		if(rows==0&&columns==0)break;
		for(int i=0;i<rows;i++)
			for(int j=0;j<columns;j++)
				cin>>mat[i][j];
		/*select numberof rows and columns to process*/
		for(int rc=3;rc<=rows;rc++){
			for(int cc=3;cc<=columns;cc++){
				/*select starting rows ans columns*/
				for(int i=0;i<=rows-rc;i++){
					for(int j=0;j<=columns-cc;j++){
						
						/*print the feisble region of matrix*/
						if(max<total)max=total; 
						total=0;
						for(int u=i;u<i+rc;u++){
							for(int v=j;v<j+cc;v++){
								total+=mat[u][v];
							}
						}
						s_rows=rc-2;
						s_columns=cc-2;
						temp=total;
						//now for the sub matrix inside the sub matrix:
						for(int s_rc=1;s_rc<=s_rows;s_rc++){
							for(int s_cc=1;s_cc<=s_columns;s_cc++){
								//select starting rows ans columns
								for(int s_i=i+1;s_i<=(i+1) + s_rows-s_rc;s_i++){
									for(int s_j=j+1;s_j<=(j+1) + s_columns-s_cc;s_j++){
										//print the feisble region of matrix
										total=temp;
										for(int s_u=s_i;s_u<s_i+s_rc;s_u++){
											for(int s_v=s_j;s_v<s_j+s_cc;s_v++){
												total-=mat[s_u][s_v];
											}
										}
										if(max<total)max=total;
									//feasible region prints till here
									}
								}
								//starting rows and columns
							}
						}
						
						/*feasible region prints till here*/
					}
				}
				/*starting rows and columns*/
			}
			
		}
	
	printf("%d\n",max);
	}
	return 0;
}