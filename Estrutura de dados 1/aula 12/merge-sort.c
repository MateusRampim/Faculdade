#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0

/* */
void swap(int *A, int i, int j)
{
  int t = A[i];
  A[i] = A[j];
  A[j] = t;
}

/* */
void swap_char(char *A, int i, int j)
{
  char t = A[i];
  A[i] = A[j];
  A[j] = t;
}

/* */
void swap_string(char **A, int i, int j)
{
  char *t = A[i];
  A[i] = A[j];
  A[j] = t;
}

/* */
void print(int *A, int n, char *message)
{
  printf("%s\n", message);
  int i;
  printf("A: {");
  for (i = 0; i < n; i++)
  {
    if (i == n - 1)
      printf("%d", A[i]);
    else
      printf("%d,", A[i]);
  }
  printf("}\n");
}

/* */
void print_char(char *A, int n, char *message)
{
  printf("%s\n", message);
  int i;
  printf("A: {");
  for (i = 0; i < n; i++)
  {
    if (i == n - 1)
      printf("%c", A[i]);
    else
      printf("%c,", A[i]);
  }
  printf("}\n");
}

/* */
int check(int *A, int n, int ascending)
{
  int i;
  for (i = 1; i < n; i++)
  {
    if (ascending)
    {
      if (A[i - 1] > A[i])
        return FALSE;
    }
    else
    {
      if (A[i - 1] < A[i])
        return FALSE;
    }
  }
  return TRUE;
}

/*Função para intercalar dois subvetores em um conjunto ordenado.
 *{A} é o vetor de entrada, {l} é a esquerda (de left),
 {m} é o meio (ou middle), {r} é a direita (de right),
 {O} é o vetor auxilar (de output). */
void merge(int A[], int l, int m, int r, int O[])
{
  int i = l;
  int k = l;
  int j = m + 1;
  while ((i <= m) && (j <= r))
  {
    if (A[i] <= A[j])
    {
      O[k++] = A[i++];
    }
    else
    {
      O[k++] = A[j++];
    }
  }
  while (j <= r)
  {
    O[k++] = A[j++];
  }
  while (i <= m)
  {
    O[k++] = A[i++];
  }

  for (i = l; i <=r; i++)
  {
    A[i] = O[i];
  }
}

/*Função principal do algoritmo Merge-Sort.*/
void merge_sort(int A[], int l, int r, int O[])
{
  if (l < r)
  {
    int m = ((l + r) / 2);
    merge_sort(A, l, m, O);
    merge_sort(A, m + 1, r, O);
    merge(A, l, m, r, O);
  }
}

/* */
int main(int argc, char *argv[])
{
  clock_t start, end;
  double elapsed_time;
  srand(time(NULL));
  if (argc < 2)
  {
    printf("run: %s [size]\n", argv[0]);
    exit(1);
  }
  int i;
  int n = atoi(argv[1]);
  ;
  int *A = (int *)malloc(n * sizeof(int));
  int *O = (int *)malloc(n * sizeof(int)); /*array auxiliar*/
  for (i = 0; i < n; i++)
  {
    //A[i] = rand() % (n + 1); /*valores aleatórios*/
    // A[i] = i;   /*valores em ordem crescente*/
    // A[i] = n-i; /*valores em ordem descrescente*/
    A[i] = 0;   /*valores iguais*/
  }
  start = clock();
  //print(A, n, "Input");
  merge_sort(A, 0, n - 1, O);
  //print(A, n, "Sorted");
  end = clock();
  elapsed_time = (end - start) / (double)CLOCKS_PER_SEC;
  printf("Running time: %.2f\n", elapsed_time);
  if (!check(A, n, TRUE))
  {
    printf("Error: non-ascending order!\n");
  }
  free(A);
  free(O);
  return 0;
}
