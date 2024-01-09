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
/*Função intercala*/
int merge(int A[], int l, int m, int r, int O[], int rlevel)
{
  for (int i = 0; i < rlevel; i++)
  {
    printf("   ");
  }
  
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
  printf("Intercalando : { ");
  for (i = l; i <= r; i++)
  {
    A[i] = O[i];
    printf("%d ",A[i]);
  }
  printf("} \n");
}

/*Função principal do algoritmo Merge-Sort.*/
void merge_sort(int A[], int l, int r, int O[], int rlevel)
{
  int m = ((l + r) / 2);
  for (int i = 0; i < rlevel; i++)
  {
    printf("   ");
  }
  printf("merge-sort(%d,%d,%d) \n",l,m,r);
  
  if (l < r)
  {
    rlevel++;
    merge_sort(A, l, m, O,rlevel);
    merge_sort(A, m + 1, r,O,rlevel);
    merge(A, l, m, r, O,rlevel);
  }
}

/* */
int main()
{
  clock_t start, end;
  double elapsed_time;
  int n = 8; /*quantidade de elementos*/
  int A[] = {5, 2, 7, 4, 8, 1, 9, 8};
  int O[n]; /*vetor auxiliar*/
  start = clock();
  print(A, n, "Input");
  merge_sort(A, 0, n - 1, O, 0);
  print(A, n, "Sorted");
  end = clock();
  elapsed_time = (end - start) / (double)CLOCKS_PER_SEC;
  printf("Running time: %.2f\n", elapsed_time);
  if (!check(A, n, TRUE))
  {
    printf("Error: non-ascending order!\n");
  }
  return 0;
}
