#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
#include<string.h>
#include<time.h>
// Here, the parameter is a pointer to a pointer


void initialize(int **arr, int m, int n)
{
    // assign values to the allocated memory
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++) {
            *(*(arr + i) + j) = 0 ;
        }
    }
}

void devidenode(int * arr1, int * arr2, int * arr3, int size)
{
  int i;
  for(i = 0; i<=size/2 -1  ; i++){
    arr1[i] = i+1;
    //printf("A[%d] = %d\t", i,arr1[i]);
    if(i<=(size/3)-1)
    {
      arr2[i] = (size/2) + i +1;
      //printf("B[%d] = %d\t", i,arr2[i]);
    }
    // printf("\n");
    if(i<=(size/6)-1)
    {
      arr3[i] = (5*size)/6 + i + 1;
      //printf("C[%d] = %d", i,arr3[i]);
    }
    //printf("\n");

}

}

void print(int * arr1, int * arr2, int * arr3, int size )
{
  int i;
  for(i = 0; i<=size/2 -1  ; i++)
  {
    printf("A[%d] = %d\t", i,arr1[i]);
    if(i<=(size/3)-1)
    {
      printf("B[%d] = %d\t", i,arr2[i]);
    }
    // printf("\n");
    if(i<=(size/6)-1)
    {
      printf("C[%d] = %d", i,arr3[i]);
    }
    printf("\n\n");

  }
}

void graphcost(int **arr, int nodenum, int n1, int n2)
{       
  if ((n1 <= nodenum/2 && n2 > nodenum/2) || (n1 > nodenum/2 && n2 <=nodenum/2) || (nodenum/2 < n1 < (nodenum - nodenum/6 +1) &&  n2 >= (nodenum - nodenum/6 + 1)) || (nodenum/2 < n2 < (nodenum - nodenum/6 + 1) &&  n1 >= (nodenum - nodenum/6 + 1)) ){
    //      // n1 = (1,6] && n2 = (6,~) ||  n2 = (1,6] && n1 = (6,~) || n1 = (6, 10] && n2 = [11, ~) || n2 = (6, 10] && n1 = [11, ~)
    // assign values to the allocated memory

*(*(arr + n1 ) + n2 ) =  *(*(arr + n1 ) + n2) + 1 ;
*(*(arr + n2 ) + n1 ) = *(*(arr + n2) + n1) + 1 ;

    // for (int i = 0; i < nodenum; i++)
    // {   
    //     for (int j = 0; j < nodenum; j++) {
    //         printf("%d ", *(*(arr + i) + j));
    //     }
    //     printf("\n");
    // } 
    // printf(" finish\n");

}
// else if (*(*(arr + n1) + n2) = 0){   
    else {   
  
*(*(arr + n1 ) + n2) = *(*(arr + n1) + n2) - 1 ;
*(*(arr + n2 ) + n1) = *(*(arr + n2) + n1) - 1;

}

    // for (int i = 0; i < nodenum; i++)
    // {   
    //     for (int j = 0; j < nodenum; j++) {
    //         printf("%d ", *(*(arr + i) + j));
    //     }
    //     printf("\n");
    // } 
    // printf(" finish\n");

    
}

void updaecost(int **arr,int n1, int n2,int nodenum){
for(int i = 0;i <= nodenum; i ++){



*(*(arr + n1 ) + i ) =  *(*(arr + n1 ) + i) *(-1)  ;

*(*(arr + n2 ) + i ) = *(*(arr + n2) + i) *(-1);
*(*(arr + i ) + n1 ) =  *(*(arr + i ) + n1) *(-1)  ;

*(*(arr + i ) + n2 ) = *(*(arr + i) + n2) *(-1);

}

}
void swap (int * arr1, int * arr2,int node1, int node2 )
{
    
    printf("original arr1[%d] = %d, arr2[%d] = %d\n ", node1, arr1[node1], node2, arr2[node2]);
    int tmp;
    tmp = arr1[node1] ;
    arr1[node1] = arr2[node2];
    arr2[node2] = tmp;
    printf("new arr1[%d] = %d, arr2[%d] = %d\n", node1, arr1[node1], node2, arr2[node2]);

}




void print_array(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}







void maxgain(){

}


void updategain( int **fix, int **cost, int *D, int *A, int *B, int *C, int nodenum,int fixnum ){
int G[nodenum][nodenum];
int cloum, row;
int N1;
int  recod_i,recod_j,recod_k;
                   

int max = -10;
for(int i = 0 ; i <(nodenum/2); i++)
{
    for(int j = 0; j<(nodenum/3); j++)
    {
        
        
        for (int k = 0; k <=(nodenum)/6 -1; k++)
        {  //printf("fix[%d][%d] = %d",i,j,(*(*(fix + A[i] -1) + B[j]-1)));
       
        //printf("fix[%d][%d] = %d", A[i] - 1, B[j] -1 , fix[A[i] -1][B[j]-1]);

            if ((*(*(fix + A[i] -1) + B[j]-1)) == 0 
             || (*(*(fix + A[i] -1) + C[k]-1)) == 0 
             ||(*(*(fix + B[j] -1) + C[k]-1)) == 0  ) 
             {
                 
                // G1[i][j] = D[A[i]] + D[B[j]] - 2* (*(*(cost + A[i] -1) + B[j]-1));
                // G2[i][k] = D[A[i]] + D[C[k]] - 2* (*(*(cost + A[i] -1) + C[k]-1));
                // G3[j][k] = D[B[j]] + D[C[k]] - 2* (*(*(cost + B[j] -1) + C[k]-1));

//---------------------------------G1--------------------------
               G[A[i]][B[j]] = D[A[i]] + D[B[j]] - 2*cost[A[i]][B[j]];
               printf("D[%d] = %d, D[%d] = %d \t",A[i],D[A[i]], B[j],D[B[j]]);
               printf("cost[%d][%d] = %d\t ",A[i],B[j], cost[A[i]][B[j]]);
               printf("G[%d][%d] = %d\t\n", A[i], B[j], G[A[i]][B[j]]);
               if(G[A[i]][B[j]] > max){
                   max = G[A[i]][B[j]] ;
                   cloum = A[i];
                   row = B[j];
                   N1 = 1;
                   recod_i = i;
                   recod_j = j;
                   
        
               }

//---------------------------------G2--------------------------
               G[A[i]][C[k]] = D[A[i]] + D[C[k]] - 2*cost[A[i]][C[k]];
               printf("D[%d] = %d, D[%d] = %d \t",A[i],D[A[i]], C[k],D[C[k]]);
               printf("cost[%d][%d] = %d\t ",A[i],C[k], cost[A[i]][C[k]]);
               printf("G[%d][%d] = %d\t\n", A[i], C[k], G[A[i]][C[k]]);
                if(G[A[i]][C[k]] > max){
                   max = G[A[i]][C[k]] ;
                   cloum = A[i];
                   row = C[k];
                   recod_i = i;
                   recod_k = k;
                   N1 = 2;
               }
//----------------------------G3------------------------------------------------------
               G[B[j]][C[k]] = D[B[j]] + D[C[k]] - 2*cost[B[j]][C[k]];

               printf("D[%d] = %d, D[%d] = %d \t",B[j],D[B[j]], C[k],D[C[k]]);
               printf("cost[%d][%d] = %d\t ",B[j],C[k], cost[B[j]][C[k]]);
               printf("G[%d][%d] = %d\t\n", B[j], C[k], G[B[j]][C[k]]);
                    if(G[B[j]][C[k]] > max){
                   max = G[B[j]][C[k]] ;
                   cloum = B[j];
                   row = C[k];
                   recod_j = i;
                   recod_k = k;

                  N1=3;
               }

             }
        }
        }
    
               
}

// fix[cloum][row] = 1;
*(*(fix + cloum ) + row) =  1;
*(*(fix + row ) + cloum) =  1;


printf("fix[%d][%d] = %d", row, cloum, *(*(fix + cloum ) + row));
printf("fix[%d][%d] = %d\n\n", cloum, row, *(*(fix + cloum ) + row));
printf("N1 = %d ",N1);
printf("maxgain =%d , swap the node %d and %d \n", max, cloum, row);


switch(N1){
case 1: swap( A, B ,recod_i, recod_j);break;
case 2: swap(A, C, recod_i, recod_k);break;
case 3:swap(B, C, recod_j, recod_k);break;

}
//  if(N1 == 1)
// // // print(A,B,C,nodenum);
//  {swap( A, B ,cloum, row);}
//  else if(N1 == 2)

//  {swap(A, C, cloum, row);}

//   else if (N1 == 3)
// { swap(B, C, cloum, row);}

 updaecost( cost, cloum,  row, nodenum);

//return cloum, row;
if (fixnum ==1){

  print(A, B, C, nodenum);

}




}















 
// Program to pass the 2D array to a function in C
int main (int argc, char *argv[]) 

{   int nodenum,edgenum;
    int *A, *B;
    FILE *fp; 
    if (argc < 2) {
        printf("not sufficient arguments");
        exit(0);
    }
    fp = fopen (argv[1],"r");
    fscanf(fp, "%d %d", &nodenum, &edgenum);

    
    if ((nodenum%6) != 0) {
        printf("the number of nodes can't divided by 6, can't balance the partition\n");}
    else{
    
    // dynamically create an array of pointers of size `m`
    int **cost = (int **)malloc((nodenum +1)* sizeof(int *));
    // dynamically allocate memory of size `m×n` and let *arr point to it
    *cost = (int *)malloc(sizeof(int) * (nodenum+1) * (nodenum+1));
    // position allocated memory across `m` pointers
    A = (int *)malloc(sizeof(int)* (nodenum)+1);

    for (int i = 0; i < nodenum+1; i++) {
        cost[i] = (*cost + (nodenum+1)*i);
    }



int i , j ;
int r = nodenum+1;
int c = nodenum+1;
 
  int** fixed = (int**)malloc(r * sizeof(int*));
    for (i = 0; i < r;i++ )
    {
        fixed[i] = (int*)malloc(c*sizeof(int));
    }
    
//   for ( i = 0; i < r; i++)
//   {
//       for (j = 0 ; j < c; j++)
//       {
//           fixed[i][j] = 0;
//       }
      
      
//   }

///////-------------------print fixed[][]---------------
// for(i = 0; i <r;i++){
//     for(j = 0; j < c; j++)
//     {
//         printf("fixed[%d][%d] = %d ", i,j,fixed[i][j]);
//     }printf("\n");
// }


  

    int A[nodenum/2];
    int B[nodenum/3];
    int C[nodenum/6];
    int D[nodenum+1];
    int n1, n2;//divide nodes





    initialize(cost, nodenum+1, nodenum+1);
    initialize(fixed, nodenum, nodenum);
    for (int i = 0; i <nodenum+1; i++)
    {
        D[i] = 0;
    }


    devidenode(A,B,C,nodenum);
    print(A,B,C,nodenum);
  
     for (int i =1; i<=edgenum; i++) 
   {
        fscanf(fp, "%d %d", &n1, &n2);
     //scan the connected node
    graphcost(cost, nodenum, n1, n2);
    
     
   }


    for (int i =1; i<nodenum+1;i++) {
      for (int j =1; j<nodenum+1;j++) {
       D[i] = D[i]+(*(*(cost + i ) + j));//calculate D for every node. If there is external node C should be 1, internal node C should be -1. which is E-I
         }
         //printf("D[%d] = %d\n", i,D[i] );
      }



 for (int d = 0;d <((nodenum/6)^2*11) ;d++)//((nodenum/6)^2*11); d++ )
 {
updategain(  fixed,  cost,  D,  A,  B,  C,  nodenum, d );
for (int i =1; i<nodenum+1;i++) {
      for (int j =1; j<nodenum+1;j++) {
       D[i] = D[i]+(*(*(cost + i ) + j));//calculate D for every node. If there is external node C should be 1, internal node C should be -1. which is E-I
         }
         //printf("D[%d] = %d\n", i,D[i] );
      }

//  swap(B,C,3, 0);
//  

 }

print(A,B,C,nodenum);



//   for(i = 0; i <r;i++){
//     for(j = 0; j < c; j++)
//     {
//         printf("fixed[%d][%d] = %d ", i,j,fixed[i][j]);
//     }printf("\n");
// //}


// }



//----------------print cost----------------------------------------------------------------
 
    

    //  for (int i = 0; i < nodenum+1; i++)
    // {
    //     for (int j = 0; j < nodenum+1; j++) {
    //         printf("%d ", *(*(cost + i) + j));
            
        
    //     }
    //     printf("\n");
    // }
 
    // deallocate memory
    // free(*cost);
    // free(cost);
 
    return 0;
}
    }
    

