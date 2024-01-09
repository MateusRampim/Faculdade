#include "list.h"

/* */
int sum (List *l) {
  List *t = l;
  int cont = 0;
  for (t=l; t!= NULL; t=t->next)
  {
    cont+=t->data;
  }
  return cont;
}

/* */
int main () {
  int k;
  List *l = NULL;
  for (k = 0; k <= 4; k++) 
    l = insert_back (l, k);
  for (k = 9; k >= 5; k--) 
    l = insert_back (l, k);
  print (l);
  printf("Sum = %d\n", sum(l));
  destroy (l);
  return 0;
}
