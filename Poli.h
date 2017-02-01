#ifndef POLI_H_INCLUDED
#define POLI_H_INCLUDED

typedef struct _polinomio
{
    int coe;
    int exp; /**< item armazenado no poli */
    struct _polinomio *prox; /**< ponteiro para o proximo poli. */
} Poli;

#endif // POLI_H_INCLUDED
