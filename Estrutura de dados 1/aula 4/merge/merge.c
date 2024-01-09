#include "list.h"

/* */
List* merge(List* A, List* B) {
    List* C = NULL; // Lista resultante
    List* tail = NULL; // Ponteiro para o último nó de C

    while (A != NULL || B != NULL) {
        if (A != NULL) {
            if (C == NULL) {
                C = A;
                tail = A;
            } else {
                tail->next = A;
                tail = A;
            }
            A = A->next;
        }

        if (B != NULL) {
            if (C == NULL) {
                C = B;
                tail = B;
            } else {
                tail->next = B;
                tail = B;
            }
            B = B->next;
        }
    }

    return C;
}


/* */
int main()
{
  int k;
  List *A = NULL, *B = NULL;
  for (k = 10; k >= 0; k -= 2)
    A = insert(A, k);
  for (k = 19; k >= 0; k -= 2)
    B = insert(B, k);
  print(A);
  print(B);
  List *C = merge(A, B);
  print(C);
  destroy(C);
  return 0;
}
