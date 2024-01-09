#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define NOT_FOUND -1
void swap(int *A, int i, int j)
{
  int t = A[i];
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
int linear_search(char **words, int n, char *key)
{
  for (int i = 0; i < n; i++)
  {
    if (strcasecmp(words[i], key) == 0)
    {
      return i;
    }
  }
  return NOT_FOUND;
}

/* */
int binary_search_iterative(char **words, int n, char *key)
{
  int final = n;
  int inicio = 0;
  int meio;
  while (inicio <= final)
  {
    meio = inicio + (final - inicio) / 2;
    if (strcasecmp(words[meio], key) == 0)
    {
      return meio;
    }
    else if (strcasecmp(words[meio], key) < 0)
    {
      inicio = meio + 1;
    }
    else
    {
      final = meio - 1;
    }
  }
  return NOT_FOUND;
}

/* */
int binary_search_recursive(char **words, int l, int r, char *key)
{
  if (l <= r)
  {

    int meio = l + (r - l) / 2;
    if (strcasecmp(words[meio], key) == 0)
    {
      return meio;
    }
    else if (strcasecmp(words[meio], key) < 0)
    {
      return binary_search_recursive(words, meio + 1, r, key);
    }
    else
    {
      return binary_search_recursive(words, l, meio - 1, key);
    }
  }

  return NOT_FOUND;
}

/* */
int get_number_of_lines(FILE *f)
{
  int n = 0;
  if (f == NULL)
    return n;
  while (!feof(f))
  {
    char c;
    fscanf(f, "%c", &c);
    if (c == '\n')
      n++;
  }
  rewind(f);
  return (n - 1);
}

/* */
int main()
{

  clock_t start, end;
  double elapsed_time;
  char *key = "paralelepipedo";
  FILE *f = fopen("palavras.txt", "r");
  int n = get_number_of_lines(f);
  char **words = (char **)malloc(n * sizeof(char *));
  int i, index;
  for (i = 0; i < n; i++)
    words[i] = (char *)malloc(256 * sizeof(char));
  i = 0;
  while (!feof(f))
  {
    fscanf(f, "%s", words[i]);
    i++;
  }
  /*Busca linear*/
  start = clock();
  index = linear_search(words, n, key);
  end = clock();
  elapsed_time = (end - start) / (double)CLOCKS_PER_SEC;
  printf("Running time (linear): %.2f\n", elapsed_time);
  if (index >= 0)
  {
    printf("Key %s, found at %d\n", key, index);
  }
  else
  {
    printf("Element not found.\n");
  }

  /*Busca binária iterativa*/
  start = clock();
  index = binary_search_iterative(words, n, key);
  end = clock();
  elapsed_time = (end - start) / (double)CLOCKS_PER_SEC;
  printf("Running time (binary): %.2f\n", elapsed_time);
  if (index >= 0)
  {
    printf("Key %s, found at %d\n", key, index);
  }
  else
  {
    printf("Element not found.\n");
  }

  /*Busca binária recursiva*/
  start = clock();
  index = binary_search_recursive(words, 0, n - 1, key);
  end = clock();
  elapsed_time = (end - start) / (double)CLOCKS_PER_SEC;
  printf("Running time (binary): %.2f\n", elapsed_time);
  if (index >= 0)
  {
    printf("Key %s, found at %d\n", key, index);
  }
  else
  {
    printf("Element not found.\n");
  }

  /*Desalocando estruturas*/
  for (i = 0; i < n; i++)
    free(words[i]);
  free(words);
  fclose(f);
  return 0;
}
