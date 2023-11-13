#include <stdio.h>
#include "polycreux.h"

int main()
{
  PolyCreux *poly = CreateMonome(3, 0);

  InsertMonome(poly, 2, 4);
  InsertMonome(poly, 0, 6);

  PolyCreux *current = poly;

  while (current != NULL)
  {
    printf("Degree: %d, Coefficient: %d\n", current->degre, current->coefficient);
    current = current->PDroite;
  }

  return 0;
}