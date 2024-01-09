#include "list.h"

List *create_circular(List *head)
{
  List *t = head;
  while (t->next != NULL)
  {
    t = t->next;
  }
  head->prev = t;
  t->next = head;
  return head;
}

int is_circular(List *l)
{
  if (l == NULL)
    return 0;

  List *slow = l;
  List *fast = l;

  while (fast != NULL && fast->next != NULL)
  {
    slow = slow->next;       // Avança um nó por vez
    fast = fast->next->next; // Avança dois nós por vez

    if (slow == fast)
    {
      return 1;
    }
  }

  return 0;
}

int main()
{
  int i;
  int n = 4;
  List *l = create();
  for (i = n; i >= 0; i--)
  {
    l = insert_front(l, i);
  }
  print(l);
  printf("Is circular: %d\n", is_circular(l));
  l = create_circular(l);

  printf("Is circular: %d\n", is_circular(l));
  return 0;
}
