/** @file poli.h
 *  @brief Conteudo do tipo abstrato de dado poli.
 *  @author Frederico S. Oliveira
 */
/**
 * @brief Definicao do TAD poli
 * Editado por Presley Demuner Reverdito.
 */
typedef struct polinomio {
  int coe;
  int exp; /**< item armazenado no poli */
  struct polinomio *prox; /**< ponteiro para o proximo poli. */
} Poli;
