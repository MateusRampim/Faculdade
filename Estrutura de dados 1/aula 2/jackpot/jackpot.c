#include "queue.h"
#include <time.h>

void jackpot (int n, int r) {
  Queue *g0= create(r+1);
  Queue *g1= create(r+1);
  Queue *g2= create(r+1);
  for (int i = 1; i < r; i++)
  {
    enqueue(g0,i);
    enqueue(g1,i);
    enqueue(g2,i);
  }
  int ganhador  = 0,c1,c2,c3,aux;
   while (!ganhador)
   {
     c1=rand()%10;
     c2=rand()%10;
     c3=rand()%10;
     for (int i = 0; i <= c1; i++)
     {
      aux = dequeue(g0);
      enqueue(g0,aux);
     }
          for (int i = 0; i <= c2; i++)
     {
      aux = dequeue(g1);
      enqueue(g1,aux);
     }
          for (int i = 0; i <= c3; i++)
     {
      aux = dequeue(g2);
      enqueue(g2,aux);
     }
     if (front(g0)==front(g1) && front(g0)==front(g2) )
     {
       printf(" %d , %d , %d \n",front(g0),front(g1),front(g2) );
       printf("Ganhou \n");
      ganhador=1;
     }else
     {
      printf(" %d , %d , %d \n",front(g0),front(g1),front(g2) );
     }
     
     
   }
   
}

int main () {
  srand(time(NULL));	
  int n = 3;  /*número de carretéis*/ 
  int r = 10; /*sequência de números em cada carretel*/ 
  jackpot (n, r);
}
