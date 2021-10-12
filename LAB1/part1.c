#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
	//file operations
	FILE *fp; 
	if (argc < 2) {
		printf("not sufficient arguments");
		exit(0);
	}
	fp = fopen (argv[1],"r");
	int n,m; 
	fscanf(fp, "%d %d", &n, &m);
	
	if ((n%2) != 0) {
		printf("odd number of nodes, can't balance the partition\n");
	} else {
	int A[n/2];
        int B[n/2];
        int C[n+1][n+1];
        int D[n+1];

	//cost matrix initialization to 0
	for (int i=0; i<=n; i++) {
	   for (int j=0; j<=n; j++) {
		C[i][j] = 0;
		}	
	}

	//Making initial solution from 2n nodes
	for (int i =0; i<=(n/2) -1;i++) {
    A[i] = i+1;
    printf("A[%d] = %d \t\t\t", i, A[i]);
		B[i] = (n/2) + i + 1;//divide nodes
    printf("B[%d] = %d\n", i, B[i]);  }
	int n1, n2;

	//updating cost matrix from input file
	for (int i =1; i<=m; i++) {
		fscanf(fp, "%d %d", &n1, &n2);//scan the connected node
		if ((n1 <= n/2 && n2 > n/2) || (n1 > n/2 && n2 <=n/2)) {
			C[n1][n2] += 1;
			C[n2][n1] += 1;
      printf("C[%d][%d] = %d\t\t\n",n1,n2, C[n1][n2]) ;/////
		} else {
			C[n1][n2] = -1;
			C[n2][n1] = -1;
      printf("C[%d][%d] = %d\t\t\n",n1,n2, C[n1][n2]) ;
		}
    
	}
printf("\n\n\n\n\n\n\n");
	int G[n/2][n/2];
	int pair_a, pair_b, tmp_i, tmp_j;
	int fixed[n+1];
	int fin_pair_A[n/2];
	int fin_par_term_A[n/2];
	int fin_pair_B[n/2];
	int fin_par_term_B[n/2];
	int final_edges[n+1][n+1];
	int final_edges_term[n+1][n+1];
	int sum;	

	//STEPS to be repeated if Gm is > 0	
	REDO: ; //This is an empty statement
	int Total_gain = 0;
	int max_total_gain = -10000;
	for (int i =0; i<=n;i++) {
          fixed[i] =0;
        }
	
	//interations till all the nodes are fixed	
	while (1) {
	int maxgain = -10000;
	for (int i =0; i<=n;i++) {	
	  D[i] =0;
	}
	for (int i =0; i<=n;i++) {
	  for (int j =0; j<=n;j++) {
		D[i] = D[i]+C[i][j];//calculate D for every node. If there is external node C should be 1, internal node C should be -1. which is E-I
	     }
	  }


	for (int i =0; i<=(n/2) -1;i++) {
	  for (int j =0; j<=(n/2) -1;j++) {
		if (fixed[A[i]] == 0 && fixed[B[j]] == 0) {
			G[i][j] = D[A[i]] + D[B[j]] - 2*C[A[i]][B[j]];
      //printf("G[%d][%d] = %d\t\t", i, j, G[i][j]);
			if (G[i][j] > maxgain) {
			maxgain = G[i][j];
      
			pair_a = A[i];
			pair_b = B[j];
			tmp_i = i;
			tmp_j = j;
		  }
      //printf("\t\t\t");
      
		}
    //printf("\t\t\t");
     
	     }
	  }printf("\n");
  	A[tmp_i] = pair_b; 
  	B[tmp_j] = pair_a; 
    
    printf("maxgain  = %d\n", maxgain);
    printf("swap node %d and %d\n",pair_b,pair_a );


	fixed[pair_a] = 1;	
	fixed[pair_b] = 1;	//exclude these pairs


	
	for (int i =0; i<=n;i++) {
	  C[pair_a][i] = -C[pair_a][i];
	  C[i][pair_a] = -C[i][pair_a];
	  C[pair_b][i] = -C[pair_b][i];
	  C[i][pair_b] = -C[i][pair_b];
	}//modify the C matrix; internal ->external , external->internal
	
	Total_gain = Total_gain + maxgain;
	//finding maximum value
	if (Total_gain > max_total_gain) {
		max_total_gain = Total_gain;
		for (int i=0; i<=(n/2)-1; i++) {
		fin_pair_A[i] = A[i];	
		fin_pair_B[i] = B[i];	
		}
	for (int i=0; i<=n; i++) {
           for (int j=0; j<=n; j++) {
                final_edges[i][j] = C[i][j];
                 }
        	}
	}
	sum = 0;
	for (int i=1; i<=n; i++ ) {
		if (fixed[i] != 1) 
			sum++;
	}
	if (sum == 0)
		break;	
  }//while end

	if (max_total_gain > 0) {
	
	for (int i=0; i<=(n/2)-1; i++) {
                A[i] = fin_pair_A[i];
                fin_par_term_A[i] = fin_pair_A[i];
                B[i] = fin_pair_B[i];
                fin_par_term_B[i] = fin_pair_B[i];
                }
        for (int i=0; i<=n; i++) {
           for (int j=0; j<=n; j++) {
                C[i][j] = final_edges[i][j];
                final_edges_term[i][j] = final_edges[i][j];
                 }
                }

		goto REDO;
	}
	
	//final partitions and cut set

		printf("Partition A:\n");
	for (int i=0; i<=(n/2) - 1; i++) {
		printf("%d  ", fin_par_term_A[i]);
	}
        printf("\nPartition B:\n");
        for (int i=0; i<=(n/2) -1; i++) {
                printf("%d  ", fin_par_term_B[i]);
        }
        printf("\nCut Set:\n");
       for (int i=0; i<=(n/2) -1; i++) {
           for (int j=0; j<=(n/2) -1; j++) {
		if ((final_edges_term[fin_par_term_A[i]][fin_par_term_B[j]]) == 1) {
			printf ("%d  %d\n", fin_par_term_A[i], fin_par_term_B[j]);
		}
	  }
	}

 }
}