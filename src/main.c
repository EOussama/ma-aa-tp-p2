#include <stdio.h>

#include "a.h"
#include "b.h"

int main()
{
  int option;

  do
  {
    printf("Travail à faire (partie n°2):\n");
    printf("1. A\n");
    printf("2. B\n");
    printf("0. Exit\n");

    printf("> ");
    scanf("%d", &option);

    switch (option)
    {
      case 1:
      {
        version_a();
        break;
      }
      case 2:
      {
        version_b();
        break;
      }
      case 0:
      {
        printf("Fin du programme.\n");
        break;
      }
      default:
      {
        printf("Option invalide.\n");
        break;
      }
    }

    printf("------------------------\n\n");
  } while (option != 0);

  return 0;
}
