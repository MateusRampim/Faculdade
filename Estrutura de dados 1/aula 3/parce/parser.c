#include "stack.h"

int parser(char *c)
{
  Stack *s = create(strlen(c));
  int i = 0;
  while (c[i] != '\0')
  {
    if (c[i] == ' ')
    {
    }
    else
    {
      printf("%c", c[i]);
      if ((c[i] == '[') || (c[i] == '('))
      {
        push(s, c[i]);
      }
      else if ((c[i] == ')') || (c[i] == ']'))
      {
        switch (pop(s))
        {
        case '(':
          if (c[i] == ')')
          {
          }
          else
          {
            return 0;
          }

          break;
        case '[':

          if (c[i] == ']')
          {
          }
          else
          {
            return 0;
          }
          break;
        default:
          break;
        }
      }
    }

    i++;
  }

  /*Terminar*/
  /*Utilizar somente as operações push, pop, empty, ... (interface)*/

  print(s);
  return empty(s);
}

int main()
{
   char *c = "( ( ) [ ( ) ] )";
  //char *c = "( [ ) ]";
  //  char *c = "( ) [ ]";
  // char *c = "( [ ]";
  // char *c = ") (";
  printf("()");
  if (parser(c))
    printf("true  (bem formada)\n");
  else
    printf("false (mal formada)\n");
  return 0;
}
