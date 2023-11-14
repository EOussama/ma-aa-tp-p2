#include <stdio.h>

#include "b.h"
#include "polycreux.h"

void version_b()
{
  int option;
  PolyCreux *poly = NULL;

  do
  {
    printf("PolyCreux :\n");
    printf("1. Insertion d'un monôme dans l'ordre décroissant des puissances de x\n");
    printf("2. L'affichage du polynôme dans l'ordre décroissant des puissances de x\n");
    printf("3. La multiplication d'un polynôme par un scalaire (entier)\n");
    printf("0. Exit version B\n");

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
        PrintDesc(poly);
        break;
      }
      case 3:
      {
        int scalaire;
        printf("Entrer le scalaire : ", scalaire);
        scanf("%d", &scalaire);

        MultiplicationScalaire(poly, scalaire);
        break;
      }
      case 0:
      {
        printf("Fin du version B.\n");
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
}