#include <stdio.h>
#include "polycreux.h"

int main()
{
  PolyCreux *poly = CreateMonome(3, 1);

  InsertMonome(poly, 2, 4);
  InsertMonome(poly, 0, 6);
  InsertMonome(poly, 10, 2);
  InsertMonome(poly, 1, -3);
  DeleteMonome(poly, 2);

  printf("Ordre décroissant : ");
  PrintDesc(poly);
  printf("\n");

  printf("Ordre croissant : ");
  PrintAsc(poly);
  printf("\n");

  DestroyPolyCreux(poly);

  return 0;
}