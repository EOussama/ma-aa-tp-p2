#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#include "polycreux.h"

// Version A -------------------------

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

PolyCreux *ConvertArray(PolyCreux *poly)
{
  int index = 0;
  int count = CountMonomes(poly);

  PolyCreux *monomesArray = (PolyCreux *)malloc(count * sizeof(PolyCreux));
  PolyCreux *current = poly;

  while (current != NULL)
  {
    monomesArray[index++] = *current;
    current = current->PDroite;
  }

  return monomesArray;
}

void InsertMonome(PolyCreux **poly, int degre, int coefficient)
{
  if (*poly != NULL)
  {
    PolyCreux *lastPoly = GetLastMonome(*poly);
    PolyCreux *newPoly = CreateMonome(degre, coefficient);

    lastPoly->PDroite = newPoly;
    newPoly->PGauche = lastPoly;
  }
  else
  {
    *poly = CreateMonome(degre, coefficient);
  }
}

void DeleteMonome(PolyCreux *poly, int degre)
{
  PolyCreux *current = poly;
  PolyCreux *previous = NULL;

  while (current != NULL)
  {
    if (current->degre == degre)
    {
      if (previous == NULL)
      {
        poly = current->PDroite;
      }
      else
      {
        previous->PDroite = current->PDroite;
      }

      free(current);
      current = current->PDroite;

      continue;
    }

    previous = current;
    current = current->PDroite;
  }
}

void DestroyPolyCreux(PolyCreux **poly)
{
  PolyCreux *current = *poly;
  PolyCreux *next;

  while (current != NULL)
  {
    next = current->PDroite;
    free(current);
    current = next;
  }

  *poly = NULL;
}

void PrintMonome(PolyCreux poly)
{
  printf("+ %dx^%d ", poly.coefficient, poly.degre);
}

void PrintDesc(PolyCreux *poly)
{
  int count = CountMonomes(poly);
  PolyCreux *monomialsArray = ConvertArray(poly);

  qsort(monomialsArray, count, sizeof(PolyCreux), CompareDegreesDesc);

  for (int i = 0; i < count; i++)
  {
    PrintMonome(monomialsArray[i]);
  }

  free(monomialsArray);
}

void PrintAsc(PolyCreux *poly)
{
  int count = CountMonomes(poly);
  PolyCreux *monomialsArray = ConvertArray(poly);

  qsort(monomialsArray, count, sizeof(PolyCreux), CompareDegreesAsc);

  for (int i = 0; i < count; i++)
  {
    PrintMonome(monomialsArray[i]);
  }

  free(monomialsArray);
}

int CountMonomes(PolyCreux *poly)
{
  int count = 0;
  PolyCreux *current = poly;

  while (current != NULL)
  {
    count++;
    current = current->PDroite;
  }

  return count;
}

int CompareDegreesDesc(const void *a, const void *b)
{
  return ((PolyCreux *)b)->degre - ((PolyCreux *)a)->degre;
}

int CompareDegreesAsc(const void *a, const void *b)
{
  return ((PolyCreux *)a)->degre - ((PolyCreux *)b)->degre;
}

int GetMaxDegre(PolyCreux *poly)
{
  int minDegree = INT_MAX;

  while (poly != NULL)
  {
    if (poly->degre < minDegree)
    {
      minDegree = poly->degre;
    }

    poly = poly->PDroite;
  }

  return minDegree;
}

// Version B ---------------------------

void MultiplicationScalaire(PolyCreux *poly, int scalar)
{
  PolyCreux *current = poly;

  while (current != NULL)
  {
    current->coefficient *= scalar;
    current = current->PDroite;
  }
}
