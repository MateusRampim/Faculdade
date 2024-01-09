
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
int* process_interval (int *A, int n, int range) {
  int i, j;
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
  return C;
}

int query (int *C, int n, int i, int j) {
  return (C[j]-C[i-1]);
}

/* */
int main () {
  int a, b, n = 15;
  int range = 10;
  int A[] = {9,2,0,8,7,9,3,2,0,7,5,0,2,6,0};
  print (A, n, "Input");
  int *C = process_interval (A, n, range);
  a = 0, b = 3;
  printf("Consulta: qtd elems no intervalo [%d - %d] = %d\n", a, b, query(C,n,a,b));
  a = 4, b = 8;
  printf("Consulta: qtd elems no intervalo [%d - %d] = %d\n", a, b, query(C,n,a,b));
  a = 0, b = 0;
  printf("Consulta: qtd elems no intervalo [%d - %d] = %d\n", a, b, query(C,n,a,b));
  a = 6, b = 6;
  printf("Consulta: qtd elems no intervalo [%d - %d] = %d\n", a, b, query(C,n,a,b));
  a = 2, b = 4;
  printf("Consulta: qtd elems no intervalo [%d - %d] = %d\n", a, b, query(C,n,a,b));
  a = 9, b = 9;
  printf("Consulta: qtd elems no intervalo [%d - %d] = %d\n", a, b, query(C,n,a,b));
  return 0;
}

