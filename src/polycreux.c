#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "polycreux.h"

PolyCreux *CreateMonome(int degre, int coefficient)
{
  PolyCreux *monome = (PolyCreux *)malloc(sizeof(PolyCreux));

  if (monome != NULL)
  {
    monome->degre = degre;
    monome->coefficient = coefficient;
    monome->PGauche = NULL;
    monome->PDroite = NULL;
  }

  return monome;
}

PolyCreux *GetLastMonome(PolyCreux *poly)
{
  if (poly == NULL)
  {
    return NULL;
  }

  PolyCreux *current = poly;

  while (current->PDroite != NULL)
  {
    current = current->PDroite;
  }

  return current;
}

void InsertMonome(PolyCreux *poly, int degre, int coefficient)
{
  if (poly != NULL)
  {
    PolyCreux *lastPoly = GetLastMonome(poly);
    PolyCreux *newPoly = CreateMonome(degre, coefficient);

    lastPoly->PDroite = newPoly;
    newPoly->PGauche = lastPoly;
  }
}
