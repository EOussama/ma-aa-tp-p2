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

void InsertMonome(PolyCreux *poly, int degre, int coefficient);

#endif