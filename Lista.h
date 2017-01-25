/** @file Lista.h
 *  @brief Prototipos das funcoes referentes ao tipo abstrato de dado Lista Simplesmente Encadeada.
 *
 *  Este arquivo contem os prototipos das funcoes do tipo abstrato de dado Lista.
 *
 *  @author Frederico S. Oliveira
 * Editado por Presley Demuner Reverdito.
 */
#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "Poli.h"

/**
 * @brief Definicao do TAD lista
 */

/*typedef struct _lista{
  struct _polinomio *primeiro; /**< ponteiro para o primeiro elemento da lista.
  //Poli *ultimo; < ponteiro para o ultimo elemento da lista
} lista;*/

/**
 * @brief Cria um novo polinomio.
 * @param Recebe uma lista de inteiros contendo o grau e coeficiente de cada termo.
 */
Poli *criaPolinomio(int valores[], int tam);

/**
 * @brief Verifica se a lista passada como parametro estah vazia.
 * @param lista variavel do tipo lista. Observe que nao eh um ponteiro.
 * @return Zero (true) se lista vazia, um (false) se nao-vazia.
 */
void apagaPolinomio(Poli **f);

/**
 * @brief Adiciona um termo a um polinˆomio.
 *
 * @param Recebe dois inteiros, respectivamente, o coeficiente do termo e o seu grau.
 */
void adicionaTermo(Poli **f,int coeficiente,int expoente);

/**
 * @brief Apaga um termo de um polinomio.
 *
 * @param Recebe um inteiro que indica o grau do termo a ser apagado.(poiscao)
 */
void apagaTermo(Poli **f,int x);

/**
 * @brief Retorna o grau do polinomio.
 * @param O grau de um polinomio ́e o grau do termo de maior grau.
 */
int grauPolinomio(Poli *f);

/**
 * @brief Retorna o coeficiente de um termo de um polinomio.
 * @param O inteiro representa o grau do termo pretendido.
 */
int coeficiente(Poli *f,int expoente);

/**
 * @brief Retorna a soma de dois polinomios
 */
Poli *somaPolinomios(Poli *f,Poli *g);

/**
 * @brief Retorna a subtracao de dois polinomios.
 */
Poli *subPolinomios(Poli *f,Poli *g);

/**
 * @brief Retorna a multiplicacao de dois polinomios.
 */
Poli *multPolinomios(Poli *f,Poli *g);

/**
 * @brief Retorna a derivada de um polinomio.
 */
Poli *derivaPolinomio(Poli *f);

/**
 * @brief Retorna o valor do polinomio quando assume o valor x.
 * @param valor real assumido pelo x.
 */
float valorPolinomio(Poli *f,float x);

/**
 * @brief Escreve na tela o polinomio ordenado.
 */
void imprimePolinomio(Poli *f);
#endif // LISTA_H_INCLUDED
