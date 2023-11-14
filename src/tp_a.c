#include <stdio.h>
#include "polycreux.h"

int main()
{
  int option;
  PolyCreux *poly = NULL;

  do
  {
    printf("PolyCreux :\n");
    printf("1. Insertion d'un monôme dans l'ordre décroissant des puissances de x\n");
    printf("2. Suppression d'un monôme à partir de son degré\n");
    printf("3. L'affichage du polynôme dans l'ordre décroissant des puissances de x\n");
    printf("4. L'affichage du polynôme dans l'ordre croissant des puissances de x\n");
    printf("5. La destruction du polynôme\n");
    printf("0. Exit\n");

    printf("> ");
    scanf("%d", &option);

    switch (option)
    {
      case 1:
      {
        int degre, coefficient;
        int maxDegre = GetMaxDegre(poly);

        do
        {
          printf("Entrer le degré (doit être plus petit que %d): ", maxDegre);
          scanf("%d", &degre);
        } while (degre >= maxDegre);

        printf("Entrer le coefficient : ");
        scanf("%d", &coefficient);

        InsertMonome(&poly, degre, coefficient);
        break;
      }
      case 2:
      {
        int degre;

        printf("Entrer la degré : ");
        scanf("%d", &degre);

        DeleteMonome(poly, degre);
        break;
      }
      case 3:
      {
        PrintDesc(poly);
        break;
      }
      case 4:
      {
        PrintAsc(poly);
        break;
      }
      case 5:
      {
        DestroyPolyCreux(&poly);
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