
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0

void swap (int *A, int i, int j) {
  int t = A[i];
  A[i] = A[j];
  A[j] = t;
}

/* */
void swap_char (char *A, int i, int j) {
  char t = A[i];
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
void print_float (double *A, int n, char *message) {
  printf("%s\n", message);
  int i;
  printf("A: {");
  for (i = 0; i < n; i++) {
    if (i == n-1)
      printf("%f", A[i]);
    else    
      printf("%f,", A[i]);
  }
  printf("}\n");
}

/* */
void print_char (char *A, int n, char *message) {
  printf("%s\n", message);
  int i;
  printf("A: {");
  for (i = 0; i < n; i++) {
    if (i == n-1)
      printf("%c", A[i]);
    else    
      printf("%c,", A[i]);
  }
  printf("}\n");
}

/* */
void partition_print (int *A, int left, int right, int rlevel) {
  int i, r;
  for (r = 0; r < rlevel; r++) { printf ("    "); }	
  printf("P: {");
  for (i = left; i <= right; i++) {
    if (i == right)
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
int check_float (double *A, int n, int ascending) {
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
void counting_sort (int *A, int n, int range) {
  int i, j;
  
  /*Alocando vetores auxiliares: */
  int *T = (int *)malloc(n * sizeof(int)); /*temporário*/
  int *C = (int *)malloc((range+1) * sizeof(int)); /*contador*/

  for (i = 0; i < range; i++)
  {
    C[i] = 0;
  }
  
  for (j = 0; j < n; j++)
  {
    C[A[j]] = C[A[j]] +1 ;
  }
  
  for (int i = 1; i < range+1; i++)
  {
    C[i] =C[i] +C[i-1] ;
  }
  
  for (int i = n-1; i >= 0; i--)
  {
    T[C[A[i]]-1] = A[i];
    C[A[i]]=C[A[i]]-1;
  }

  for (i = 0; i < n; i++) {
    A[i] = T[i];
  }
  
  /*Desalocando vetores auxiliares: */
  free (T);
  free (C);
}

/* */
int main (int argc, char *argv[]) {

  clock_t start, end;
  double elapsed_time;
  srand(time(NULL));

  if (argc < 2) {
    printf("run: %s [size]\n", argv[0]);
    exit(1);
  }

  int i;
  int n = atoi(argv[1]);;
  int range = 1000000; /*intervalo de valores sorteados*/
  int *A = (int *)malloc(n * sizeof(int));

  for (i = 0; i < n; i++) {
    A[i] = rand() % range; /*valores aleatórios*/
  }  

  start = clock();
  print (A, n, "Input");
  counting_sort (A, n, range);
  print (A, n, "Sorted");
  end = clock();
  elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
  printf("Running time: %.2f\n", elapsed_time);
  if (!check(A, n, TRUE)) {
    printf("Error: non-ascending order!\n");
  }
  free (A);
  return 0;
}

