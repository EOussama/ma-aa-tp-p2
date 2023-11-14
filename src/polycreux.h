#ifndef POLYCREUX_H
#define POLYCREUX_H

typedef struct PolyCreux
{
  int degre;
  int coefficient;
  struct PolyCreux *PGauche;
  struct PolyCreux *PDroite;
} PolyCreux;

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

#endif