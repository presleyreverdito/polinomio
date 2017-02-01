/** @file Lista.c
 *  @brief Conteudo das funcoes referentes ao tipo abstrato de dado Lista Simplesmente Encadeada.
 *
 *  Este arquivo contem os conteudos das funcoes do tipo abstrato de dado Lista.
 *
 *  @author Frederico S. Oliveira
 *  Editado por Presley Demuner Reverdito
 */
#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#include "Lista.h"
#include"Poli.h"
#include <math.h>

Poli *criaPolinomio(int valores[], int tam)
{
    int i,expoente=777,coeficiente=777;
    Poli *p = criaPolinomioVazio();
    for(i=0; i<tam; i++)
    {
        if(i%2 == 0)  // Se 'i' for par
        {
            coeficiente= valores[i];
        }
        else  // Se 'i' for ímpar
        {
            expoente = valores[i];
            adicionaTermo(&p,coeficiente,expoente);
        }
    }

    return p;
}

/*
Poli *criaPolinomio(int valores[], int tam){
    Poli *aux = NULL;
    int i;
    int primeiraVerificacao = 1;
    int grauAnterior;
    Poli *p = malloc(sizeof(Poli));
    for(i=0;i<tam;i++){
        if(i%2){ // Se 'i' for par
            if(primeiraVerificacao){
           // Poli *p = malloc(sizeof(Poli));
            p->exp  = valores[i];
            p->prox = aux;
            aux = p;
            primeiraVerificacao = 0;
            grauAnterior = p->exp;
            }
            else{
                if(grauAnterior == valores[i]){
                   p->coe += valores[i-1];
                   i--;
                }
                else{
                    Poli *p = malloc(sizeof(Poli));
                    p->exp  = valores[i];
                    p->prox = aux;
                    aux = p;
                    grauAnterior = p->exp;
                }
            }
        }
        else{
            p->coe = valores[i];
        }
    }

    return p;
}
*/

void apagaPolinomio(Poli **f)
{

    Poli *aux = *f;
    while(*f!=NULL)
    {
        *f = (*f)->prox;
        free(aux);
        aux=*f;
    }

}
Poli* criaPolinomioVazio()
{

    return NULL;
}
void adicionaTermo(Poli **f,int coeficiente,int expoente)
{
    Poli *aux = *f;
    Poli *aux2;
    if(*f==NULL)                                                ///Quando vazia, cria o polinomio
    {
        Poli *aux= malloc(sizeof(Poli));
        aux->coe=coeficiente;
        aux->exp= expoente;
        aux->prox= NULL;
        *f=aux;
        return;
    }
    else
    {
        while(aux!=NULL)                                        ///Quando nao for vazia, entra no laço, até NULL
        {
            if(aux->exp == expoente)                            ///Quando o grau for igual
            {
                aux->coe+=coeficiente;
                return;
            }
            else if(expoente>aux->exp)                         ///Quando achamos o lugar correto para inserir (ordenado)
            {
                Poli *p = malloc(sizeof(Poli));
                p->prox=aux;
                p->coe=coeficiente;
                p->exp=expoente;
                if(aux == *f)                                   ///Caso seja o maior grau de todos, insere no topo da lista
                {
                    *f = p;
                }
                else                                            ///QUando esta no meio de dois elementos
                {
                    aux2->prox=p;
                }


                return;
            }
            else                                                ///Quando nao for nenhum dos casos para avançar na lista...
            {
                aux2 = aux;
                aux = aux->prox;
            }


        }

    }
    Poli *p = malloc(sizeof(Poli));                                ///... caso seja o ultimo elemento adiciona no final da lista
    p->coe = coeficiente;
    p->exp = expoente;
    p->prox = NULL;
    aux2->prox = p;
}
void apagaTermo(Poli **p,int x)
{
    Poli *aux=*p;
    Poli *anterior = NULL;
    for(  ; aux!=NULL ; anterior=aux, aux=aux->prox)
    {
        if(aux->exp == x)
        {
            if(aux==*p)
            {
                *p=aux->prox;
                free(aux);
                return;
            }
            else
            {
                anterior->prox = aux->prox;
                free(aux);
                return;
            }
        }

    }
    printf("Termo inexistente\n");
    return;
}
int grauPolinomio(Poli *f)
{
    if(f ==NULL)
    {
        return -1;
    }
    return f->exp;


}
int coeficiente(Poli *f,int expoente)
{
    while(f!= NULL)
    {
        if(f->exp != expoente)
        {
            f=f->prox;
        }
        else
        {
            return f->coe;
        }

    }

}
Poli *somaPolinomios(Poli *f,Poli *g)
{

    Poli *resultado = criaPolinomioVazio();
    for(; f!=NULL ; f = f->prox)
    {
        adicionaTermo(&resultado, f->coe, f->exp);
    }
    for(; g!=NULL ; g = g->prox)
    {
        adicionaTermo(&resultado, g->coe, g->exp);
    }

    return resultado;
}
Poli *subPolinomios(Poli *f,Poli *g)
{
    Poli *resultado = criaPolinomioVazio();
    for(; f!=NULL ; f = f->prox)
    {
        adicionaTermo(&resultado, f->coe, f->exp);
    }
    for(; g!=NULL ; g = g->prox)
    {
        adicionaTermo(&resultado,-(g->coe), g->exp);
    }

    return resultado;
}
Poli *multPolinomios(Poli *f,Poli *g)
{
    int coeficiente,expoente;
    Poli *resultado = criaPolinomioVazio();
    for( ; f != NULL ; f = f->prox)
    {
        for( ; g!=NULL ; g = g->prox)
        {
            expoente = f->exp + g->exp;
            coeficiente = f->coe * g->coe;
            adicionaTermo(&resultado,coeficiente,expoente);
        }
    }

    return resultado;
}
Poli *derivaPolinomio(Poli *f)
{
    Poli *resultado = criaPolinomioVazio();
    int coeficiente, expoente;
    for( ; f!=NULL; f = f->prox)
    {
        coeficiente = f->coe*f->exp;
        expoente = f->exp -1;
        adicionaTermo(&resultado,coeficiente,expoente);
    }
    return resultado;
}
float valorPolinomio(Poli *f,float x)
{
    float resultado;
    for(; f != NULL; f = f->prox)
    {
        resultado += pow(x,f->exp)*f->coe;

    }
    return resultado;
}
void imprimePolinomio(Poli *f)
{
    Poli *primeira = f;
    while(f!=NULL)
    {
        if(f->coe>0 && f != primeira)
            printf("+%dx^%d",f->coe,f->exp);
        else
            printf("%dx^%d",f->coe,f->exp);
        f=f->prox;
    }
    printf("\n");
}
