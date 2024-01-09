#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TRUE 1
#define FALSE 0
void swap (int *A, int i, int j) {
  int t = A[i];
  A[i] = A[j];
  A[j] = t;
}

/* */
void swap_string (char **A, int i, int j) {
  char *t = A[i];
  A[i] = A[j];
  A[j] = t;
}

/* */
void print (int *A, int n, char *message) {
  printf("%s\n", message);
  int i;
  printf("A: {");
  for (i = 0; i < n; i++) {
    if (i == n-1)
      printf("%d", A[i]);
    else    
      printf("%d,", A[i]);
  }
  printf("}\n");
}

/* */
int check (int *A, int n, int ascending) {
  int i;
  for (i = 1; i < n; i++) {
    if (ascending) {
      if (A[i-1] > A[i])
        return FALSE;	      
    }
    else {
      if (A[i-1] < A[i])
        return FALSE;	      
    }    
  }
  return TRUE;  
}

/* */
void selection_sort (int *A, int n) {
  int aux;
  for (int i = 0; i < n; i++)
  {
    aux = i;
    for (int j = i+1; j < n; j++)
    {
      if (A[j]<A[aux])
      {
        aux = j;
      }
      
    }
    swap(A,i,aux);
  }
  
}

/* */
int main () {

  clock_t start, end;
  double elapsed_time;
  srand(time(NULL));


   
  int i;
  int n = 1000000;
   /*intervalo de valores sorteados*/
  int *A = (int *)malloc(n * sizeof(int));

  for (i = 0; i < n; i++) {
    A[i] = rand() % (n+1); /*valores aleatórios*/
  }  

  
  //print (A, n, "Input");
  start = clock();
  selection_sort (A, n);
  end = clock();
  //print (A, n, "Sorted");
  
  elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
  printf("Running time: %.2f\n", elapsed_time);
  if (!check(A, n, TRUE)) {
    printf("Error: non-ascending order!\n");
  }
  free (A);
  return 0;
}

