#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>


typedef struct tree
{
        int a[3][3],g,h,f;
        struct tree *ch1;
        struct tree *ch2;
        struct tree *ch3;
        struct tree *ch4;
        struct tree *next;
        struct tree *parent;
        }list;
        
        
       
list *rear=NULL,*front=NULL,*q_rear=NULL,*q_front=NULL;        
int final[3][3],c[3][3],y,z;

 

int check_f(int x[3][3])
{
    int r=1;
    for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
    {
            if(x[i][j]!=final[i][j])
            r=0;
            }
            return r;
            }

void copy_a(int p[3][3],int q[3][3])
{
     for(int i=0;i<3;i++)
     for(int j=0;j<3;j++)
     p[i][j]=q[i][j];
     }
     
     

               
                 

void find_zero()
{    for(int i=0;i<3;i++)
     for(int j=0;j<3;j++)
     {
             if(c[i][j]==0)
             {
                           y=i;
                           z=j;
                           }}}


int compare(list *n1,list *n2)
{
    int r=1;
    for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
    {    
         if(n1->a[i][j]!=n2->a[i][j])
         r=0;
         }
         return r;
         }
    
    
int chk_list(list *n)
{
    list *temp;
    temp=front;
    int r=0;
    while(temp!=NULL)
    {
                           if(compare(temp,n)==1)
                           {
                                                       r=1;
                                                       break;
                                                       }
                                                       temp=temp->next;
                           }
                           return r;
                           }
int count()
{
    list *temp;
    int k=0;
    temp=q_front;
    while(temp->next!=NULL)
    {
          k++;
          temp=temp->next;
          }
          return k;
          }
                              
void point_rear()
{
     list *temp;
     temp=q_front;
     while(temp->next!=NULL)
     {
                      temp=temp->next;
                      }
                      q_rear=temp;
                      rear=temp;
                      }
                          

void arrange()
{
     list *t1,*t2,*t3;
     int i,j;
     i=count();
     j=i;
     for(int k=0;k<i;k++)
     {
             t1=q_front;
             t2=q_front->next;
             
     for(int l=1;l<j;l++)
     {
                      if(t1->next->f>t2->next->f)
                      {
                                                 t3=t2;
                                                 t1->next=t2->next;
                                                 t3->next=t3->next->next;
                                                 t1->next->next=t2;
                                                 }
                      j--;
                      t1=t1->next;
                      t2=t2->next;
                                                 }
                                                 }
     point_rear();
                                                 }
                                                 
                      


int cal_h(int n[3][3])
{
    int hu=0,t1,k,l;
    for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
    {
            t1=final[i][j];
            if(t1!=0)
            for(k=0;k<3;k++)
            for(l=0;l<3;l++)
            { 
                    if(t1==n[k][l])
                    hu=hu+(abs(k-i)+abs(l-j));
                    }
            }
            return hu;
            }
            
                             
    
    
     
                           
void cal_ghf(list *n)
{
     if(n==front)
     n->g=0;
     else
     n->g=((n->parent->g)+1);
     n->h=cal_h(n->a);
     n->f=(n->g)+(n->h);
     }
     
     
                           
void enque(list *n)
{
     if(q_front==NULL)
     {
                      q_front=n;
                      q_rear=n;
                      }
     else
     {
         q_rear->next=n;
         q_rear=n;
         }
}



void t_list(list *n)
{
     if(front==NULL)
     {
                      front=n;
                      rear=n;
                      }
     else
     {
         rear->next=n;
         rear=n;
         }
         cal_ghf(n);
}

void deque()
{
     if(q_front==q_rear)
     {
                        q_front=NULL;
                        q_rear=NULL;
                        }
                        else
                        q_front=q_front->next;
     }                                


void mov_up()
{
     int p;
     list *temp=(list *)malloc(sizeof(list));
     copy_a(temp->a,c);
     p=temp->a[y+1][z];
     temp->a[y+1][z]=0;
     temp->a[y][z]=p;
     temp->next=NULL;
     q_front->ch1=temp;
     q_front->ch1->parent=q_front;
     if(chk_list(temp)!=1)
     {
                          t_list(temp);
                          enque(temp);
                          }}
     
void mov_down()
{
     int p;
     list *temp=(list *)malloc(sizeof(list));
     copy_a(temp->a,c);
     p=temp->a[y-1][z];
     temp->a[y-1][z]=0;
     temp->a[y][z]=p;
     temp->next=NULL;
     q_front->ch2=temp;
     q_front->ch2->parent=q_front;
     if(chk_list(temp)!=1)
     {
                          t_list(temp);
                          enque(temp);
                          }}


void mov_left()
{
     int p;
     list *temp=(list *)malloc(sizeof(list));
     copy_a(temp->a,c);
     p=temp->a[y][z+1];
     temp->a[y][z+1]=0;
     temp->a[y][z]=p;
     temp->next=NULL;
     q_front->ch3=temp;
     q_front->ch3->parent=q_front;
     if(chk_list(temp)!=1)
     {
                          t_list(temp);
                          enque(temp);
                          }}

void mov_right()
{
     int p;
     list *temp=(list *)malloc(sizeof(list));
     copy_a(temp->a,c);
     p=temp->a[y][z-1];
     temp->a[y][z-1]=0;
     temp->a[y][z]=p;
     temp->next=NULL;
     q_front->ch4=temp;
     q_front->ch4->parent=q_front;
     if(chk_list(temp)!=1)
     {
                          t_list(temp);
                          enque(temp);
                          }}

void print_array(int r[3][3])
{
                for(int i=0;i<3;i++)
                {
                        for(int j=0;j<3;j++)
                        {
                                printf("%d\t",r[i][j]);
                                }
                                printf("\n");
                                }
                                }


int count_step(list *nd)
{
    int i=0;
     while(nd!=NULL)
              {
                            i++;
                             nd=nd->parent;
                             }
                             return i;
                             }

void p_result(list *nd)
{
     int i;
     i=count_step(nd);
     printf("%d steps are required\n",i-1);
              while(nd!=NULL)
              {
                             printf("\n");
                             print_array(nd->a);
                             nd=nd->parent;
                             }
                             }


void bfs(list *n)
{
     if(check_f(n->a)==1)
     p_result(n);
     t_list(n);
     enque(n);
     while(check_f(q_front->a)!=1)
     {
                                  copy_a(c,q_front->a);
                                  find_zero();
                                  if(y!=2)
                                  mov_up();
                                           else
                                           q_front->ch1=NULL;
                                  if(y!=0)
                                  mov_down();
                                             else
                                             q_front->ch2=NULL;
                                  if(z!=2)
                                  mov_left();
                                             else
                                             q_front->ch3=NULL;
                                  if(z!=0)
                                  mov_right();
                                              else
                                             q_front->ch4=NULL;
                                  arrange();
                                  deque();
                                  }
                                  printf("\nthe required steps are:\n");
                                  p_result(q_front);
                                  }
                                  
     
     
        
main()
{
      int i,j;
      list *nd=(list *)malloc(sizeof(list));
      nd->ch1=NULL;
      nd->ch2=NULL;
      nd->ch3=NULL;
      nd->ch4=NULL;
      nd->next=NULL;
      nd->parent=NULL;
      printf("enter initial state:\n");
      for(i=0;i<3;i++)
      for(j=0;j<3;j++)
      scanf("%d",&nd->a[i][j]);
      printf("enter final state:\n");
      for(i=0;i<3;i++)
      for(j=0;j<3;j++)
      scanf("%d",&final[i][j]);
      bfs(nd);
      scanf("%d",&i);
      
      
      }     
