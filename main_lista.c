#include <stdlib.h>
#include <stdio.h>
#include "Lista.h"
#define MAX 20
/*
 * Programa que realiza operações com polinomios
 * Autor: Presley Demuner Reverdito
 * Universidade Federal de Mato Grosso
 */

 void menu(){
        printf("O que o Senhor(a) deseja fazer?\n");
        printf("1- Adiconar termo?\n");
        printf("2- Apagar termo?\n");
        printf("3- Verificar grau de um polinomio?\n");
        printf("4- Verificar o coeficiente de um polinomio?\n");
        printf("5- Somar polinomio?\n");
        printf("6- Subtrair polinomio?\n");
        printf("7- Multiplicar polinomio?\n");
        printf("8- Derivar um polinomio?\n");
        printf("9- Calcular o polinomio com o valor real x\n");
 }
 void cabecalho(){
    printf("################################################\n");
    printf("# Trabalho Manipulacao de Polinomios\n");
    printf("# Disciplina Estrutura de Dados\n");
    printf("# Prof. Frederico S. Oliveira\n");
    printf("# Autor: Presley Demuner Reverdito RGA: 201511902022\n");
    printf("################################################\n");

 }
int main(){
    cabecalho();
    char pergunta ,funcao= NULL;
    int opcao,tamanho1,tamanho2,i,expoente,escalar;
    Poli *f,*g,*derivado;
    float x;
    pergunta='y';
    while(pergunta == 'y'){
        printf("Digite o tamanho do Polinomio F");
        scanf("%d",&tamanho1);
        int vetor1[tamanho1];
        if(tamanho1>MAX){
            printf("Valor excedido");
            return;
        }
        printf("Digite os valores do Polinomio F");
        for(i=0;i<tamanho1;i++){
            scanf("%d",&vetor1[i]);
        }

        printf("Digite o tamanho do Polinomio G");
        scanf("%d",&tamanho2);
        int vetor2[tamanho2];
        if(tamanho2>MAX){
            printf("Valor excedido");
            return;
        }
        printf("Digite os valores do Polinomio G");
        for(i=0;i<tamanho2;i++){
            scanf("%d",&vetor2[i]);
        }

        f =criaPolinomio(vetor1,tamanho1);
        g =criaPolinomio(vetor2,tamanho2);

        menu();
        scanf("%d",&opcao);


       switch (opcao){
           case 1:
             printf("Insira polinomio, o expoente e o coeficiente desejado\n");
             printf("f Para o primeiro e g para o segundo\n");
             scanf("%c %d %d",&funcao, &expoente, &escalar);
             if (funcao =='f'){
                adicionaTermo(&f, expoente,escalar);
             }
             else
                adicionaTermo(&g, expoente,escalar);
             printf("Termo adicionado\n");
           break;

           case 2:
             printf("Insira o polinomio e o grau a ser exluido\n");
             printf("f Para o primeiro e g para o segundo\n");
             scanf("%c %d",&funcao, &expoente);
             if (funcao =='f')
                apagaTermo(&f,expoente);
            else
                apagaTermo(&g,expoente);
             printf("Termo apagado!");
           break;

           case 3:
             printf("Qual polinomio deseja saber o grau?\n");
             printf("f Para o primeiro e g para o segundo\n");
             scanf("%c",&funcao);
             if (funcao =='f')
                printf("%d",grauPolinomio(f));
             else
                printf("%d",grauPolinomio(g));

           break;

           case 4:
             printf("Insira o polinomio e o grau que deseja para saber o coefiente?\n");
             printf("f Para o primeiro e g para o segundo\n");
             scanf("%c %d",&funcao,&expoente);
             if (funcao =='f')
                printf("O coeficiente é:%d\n",coeficiente(f,expoente));
             else
                printf("O coeficiente é:%d\n",coeficiente(g,expoente));
           break;

           case 5:
             printf("A soma de F+G é:%d\n",somaPolinomios(f,g));
           break;

           case 6:
             printf("A subtracao de F-G é:%d\n",subPolinomios(f,g));
           break;

           case 7:
             printf("A multiplicacao de F*G é:%d\n",multPolinomios(f,g));
           break;

           case 8:
             printf("Qual polinomio deseja derivar?");
             printf("f Para o primeiro e g para o segundo\n");
             scanf("%c",&funcao);
             if (funcao =='f')
                derivado = derivaPolinomio(f);
             else
                derivado = derivaPolinomio(g);
             printf("O polinomio derivado é: ");
             imprimePolinomio(derivado);
           break;

           case 9:
             printf("Insere o polinomio e o valor de x\n");
             printf("f Para o primeiro e g para o segundo\n");
             scanf("%c %d",&funcao,&x);
             if (funcao =='f')
                valorPolinomio(f,x);
             else
                valorPolinomio(g,x);

           break;


            printf("Deseja continuar?(y/n)");
            scanf("%c",&pergunta);

        }

    }
printf("\nPrograma finalizado/n");

}



