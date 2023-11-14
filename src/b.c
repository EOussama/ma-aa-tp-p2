#include <stdio.h>

#include "b.h"
#include "polycreux.h"

PolyCreux *CreatePolyCreux1()
{
  PolyCreux *poly = CreateMonome(50, -6);

  InsertMonome(&poly, 8, -2);
  InsertMonome(&poly, 0, 1);

  return poly;
}

PolyCreux *CreatePolyCreux2()
{
  PolyCreux *poly = CreateMonome(50, 6);

  InsertMonome(&poly, 13, -5);
  InsertMonome(&poly, 8, -2);
  InsertMonome(&poly, 0, 8);

  return poly;
}

void version_b()
{
  int option;

  PolyCreux *poly = NULL;
  PolyCreux *p1 = CreatePolyCreux1();
  PolyCreux *p2 = CreatePolyCreux2();

  do
  {
    printf("PolyCreux :\n");
    printf("1. Insertion d'un monôme dans l'ordre décroissant des puissances de x\n");
    printf("2. L'affichage du polynôme dans l'ordre décroissant des puissances de x\n");
    printf("3. La multiplication d'un polynôme par un scalaire (entier)\n");
    printf("4. La multiplication d'un polynôme par un monôme\n");
    printf("5. La somme de deux polynômes\n");
    printf("6. La soustraction de deux polynômes\n");
    printf("7. Le produit de deux polynômes\n");
    printf("8. L'évaluation de p1 et p2 polynôme en -2\n");
    printf("9. L'évaluation d'une polynôme en une données x entrée au clavier\n");
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

        printf("Entrer le scalaire : ");
        scanf("%d", &scalaire);

        MultiplicationScalaire(poly, scalaire);
        break;
      }
      case 4:
      {
        int degre, coefficient;

        printf("Entrer le degré du monôme : ");
        scanf("%d", &degre);

        printf("Entrer le coefficient du monôme :");
        scanf("%d", &coefficient);

        MultiplicationMonome(poly, degre, coefficient);
        break;
      }
      case 5:
      {
        PolyCreux *p3 = SommePolynome(p1, p2);

        printf("La somme de \np1(x) = ");
        PrintDesc(p1);
        printf("\net \np2(x) = ");
        PrintDesc(p2);
        printf("\nest \np3(x) = ");
        PrintDesc(p3);
        printf("\n");
        break;
      }
      case 6:
      {
        PolyCreux *p3 = SoustractionPolynome(p1, p2);

        printf("La soustraction de \np1(x) = ");
        PrintDesc(p1);
        printf("\net \np2(x) = ");
        PrintDesc(p2);
        printf("\nest \np3(x) = ");
        PrintDesc(p3);
        printf("\n");
        break;
      }
      case 7:
      {
        PolyCreux *p3 = ProduitPolynome(p1, p2);

        printf("Le produit de \np1(x) = ");
        PrintDesc(p1);
        printf("\net \np2(x) = ");
        PrintDesc(p2);
        printf("\nest \np3(x) = ");
        PrintDesc(p3);
        printf("\n");
        break;
      }
      case 8:
      {
        long p1Resultat = EvaluationPolynome(p1, -2);
        long p2Resultat = EvaluationPolynome(p2, -2);

        printf("[ p1(x) = ");
        PrintDesc(p1);
        printf("] en -2 est %ld\n", p1Resultat);

        printf("[ p2(x) = ");
        PrintDesc(p2);
        printf("] en -2 est %ld\n", p2Resultat);

        break;
      }
      case 9:
      {
        int x;

        printf("Entrer une valeur pour x : ");
        scanf("%d", &x);

        long p1Resultat = EvaluationPolynome(p1, x);
        long p2Resultat = EvaluationPolynome(p2, x);

        printf("[ p1(x) = ");
        PrintDesc(p1);
        printf("] en %d est %ld\n", x, p1Resultat);

        printf("[ p2(x) = ");
        PrintDesc(p2);
        printf("] en %d est %ld\n", x, p2Resultat);

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