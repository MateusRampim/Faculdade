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
int random_partition(int A[], int left, int right)
{
  srand(time(NULL));
  int ran = right - left + 1;
  ran = rand() % (ran);
  swap(A, right, ran + left);
  int p = partition(A, left, right);
  return p;
}
/* */
void quick_sort(int *A, int left, int right)
{
  if (left < right)
  {
    int p = random_partition(A, left, right);
    quick_sort(A, left, p - 1);
    quick_sort(A, p + 1, right);
  }
}
void quick_find(int *A, int left, int right, int k)
{
  int p = random_partition(A, left, right);
  if (p < k)
  {
    quick_find(A, p + 1, right, k);
  }
  else if (p > k)
  {
    quick_find(A, left, p - 1, k);
  }
  else
  {
    printf(" o valor é : %d \n", A[p]);
    return;
  }
}
int partition_median_of_three(int A[], int left, int right)
{
  int *B= (int *)malloc(3 * sizeof(int));
  B[0]= A[left],B[1] = A[(left+ right)/2],B[2]=A[right];
  quick_find(B,0,2,1);
  if (B[1]==A[left])
  {
    swap(A,left,right);
  }else if (B[1] == A[(left+ right)/2])
  {
    swap(A,A[(left+ right)/2],right);
  }
  
  


  return partition(A, left, right);
}
/* */
int main()
{
  int n = 8;
  int A[] = {7, 1, 3, 10, 17, 2, 21, 9};
  print(A, n, "Input");
  quick_find(A, 0, n - 1, 7);
  print(A, n, "Partial sorted");
  return 0;
}
