#ifndef POLYCREUX_H
#define POLYCREUX_H

// Structure -------------------------

typedef struct PolyCreux
{
  int degre;
  int coefficient;
  struct PolyCreux *PGauche;
  struct PolyCreux *PDroite;
} PolyCreux;

// Version A -------------------------

PolyCreux *CreateMonome(int degre, int coefficient);

PolyCreux *GetLastMonome(PolyCreux *poly);

PolyCreux *ConvertArray(PolyCreux *poly);

void InsertMonome(PolyCreux **poly, int degre, int coefficient);

void DeleteMonome(PolyCreux *poly, int degre);

void DestroyPolyCreux(PolyCreux **poly);

void PrintMonome(PolyCreux poly);

void PrintDesc(PolyCreux *poly);

void PrintAsc(PolyCreux *poly);

int CountMonomes(PolyCreux *poly);

int CompareDegreesDesc(const void *a, const void *b);

int CompareDegreesAsc(const void *a, const void *b);

int GetMaxDegre(PolyCreux *poly);

// Version B ------------------------

void MultiplicationScalaire(PolyCreux *poly, int scalar);

void MultiplicationMonome(PolyCreux *poly, int degre, int coefficient);

PolyCreux *SommePolynome(PolyCreux *p1, PolyCreux *p2);

PolyCreux *SoustractionPolynome(PolyCreux *p1, PolyCreux *p2);

#endif