#include "stack.h"

int main()
{
  int tam = 6;
  Stack *s = create(tam);
  Stack *aux = create(tam);
  srand(time(NULL));
  int i;
  for (i = 0; i < tam; i++)
  {
    push(s, rand() % 10);
  }
  print(s);
  while (!empty(s))
  {

    if (get_peek(s) % 2 == 0)
    {
      pop(s);
    }
    else
    {
      push(aux, pop(s));
    }
  }
  while (!empty(aux))
  {
    push(s, pop(aux));
  }
  print(s);

  destroy(s);
}
