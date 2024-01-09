#include "list.h"

List *split(List *l, List *x, List *y)
{
  if (l == NULL || x == NULL || y == NULL || x == y)
  {
    // Verificações de segurança
    return l;
  }

  List *t = l, *j = NULL, *i = NULL;

  while (t != NULL && t != x)
  {
    j = t;
    t = t->next;
  }

  if (t == NULL)
  {

    return l;
  }

  if (j != NULL)
  {

    j->next = NULL;
  }
  else
  {

    l = NULL;
  }

  // Continue procurando o nó y
  while (t != NULL && t != y)
  {
    i = t;
    t = t->next;
  }

  if (t == NULL)
  {
    // y não foi encontrado na lista
    return l;
  }

  // Ajuste os ponteiros para reconectar a lista
  if (j != NULL)
  {
    j->next = t->next;
  }
  if (t != NULL)
  {
    t->next->prev = j;
  }

  return l;
}

int main()
{
  int i;
  int n = 9;

  List *l = create();

  for (i = n; i >= 0; i--)
  {

    l = insert_front(l, i);
  }

  List *x = search(l, 3);
  List *y = search(l, 7);
  print(l);
  List *ls = split(l, x, y);

  print(ls);
  destroy(ls);

  return 0;
}
