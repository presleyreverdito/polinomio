/** @file poli.h
 *  @brief Conteudo do tipo abstrato de dado poli.
 *  @author Frederico S. Oliveira
 */
/**
 * @brief Definicao do TAD poli
 * Editado por Presley Demuner Reverdito.
 */
 #ifndef POLI_H_INCLUDED
#define POLI_H_INCLUDED
typedef struct _polinomio {
  int coe;
  int exp; /**< item armazenado no poli */
  struct _polinomio *prox; /**< ponteiro para o proximo poli. */
} Poli;

#endif // POLI_H_INCLUDED
