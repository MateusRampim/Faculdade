#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

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
void partition_print(int *A, int left, int right, int rlevel)
{
  /*Terminar*/
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
/* */
int partition(int A[], int left, int right)
{
  int p = A[right];
  int i = left - 1;
  for (int j = left; j < right; j++)
  {
    if (A[j] <= p)
    {
      i = i + 1;
      swap(A, i, j);
    }
  }
  swap(A, i + 1, right);
  return i + 1;
}

/* */
void quick_sort(int *A, int left, int right)
{
  if (left < right)
  {
    int p = partition(A, left, right);
    quick_sort(A, left, p - 1);
    quick_sort(A, p + 1, right);
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
  int range = 10; /*intervalo de valores sorteados*/
  int *A = (int *)malloc(n * sizeof(int));

  for (i = 0; i < n; i++)
  {
    //A[i] = rand() % (n + 1); /*valores aleatórios*/
    // A[i] = i; /*ordem crescente*/
    //A[i] = n-i; /*ordem descrente*/
     A[i] = 0; /*iguais*/
  }

  start = clock();
  // print (A, n, "Input");
  quick_sort(A, 0, n - 1);
  //print(A, n, "Sorted");
  end = clock();
  elapsed_time = (end - start) / (double)CLOCKS_PER_SEC;
  printf("Running time: %.2f\n", elapsed_time);
  if (!check(A, n, TRUE))
  {
    printf("Error: non-ascending order!\n");
  }
  free(A);
  return 0;
}
