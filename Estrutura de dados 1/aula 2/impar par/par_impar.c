#include "queue.h"
#include <time.h>

int main()
{
  srand(time(NULL));
  int i = 0, n = 10;
  int x;
  Queue *par = create(n);
  Queue *impar = create(n);

  while (i < n)
  {
    x = rand() % 100;
    

    if (x % 2 == 0)
    { 
      enqueue(par, x);
    }
    else
    {
      enqueue(impar, x);
    }

    i++;
  }

  print(par);
  print(impar);

  /*Use somente as operações definidas em queue.h*/
  /*Não use para resolver esse exercício o operador -> aqui!*/
  /*Terminar*/
  return 0;
}
