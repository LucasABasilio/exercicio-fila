/*Lucas Assun��o Basilio
Armazenar em uma fila uma sequ�ncia aleat�ria e com quantidade indefinida de matr�culas e notas que os alunos tiraram em uma prova.
Os dados devem ser fornecidos pelo usu�rio e armazenados em uma fila na mesma ordem em que foram digitados.
Sempre que o usu�rio fornece uma matr�cula deve fornecer tamb�m a respectiva nota do aluno.
Os dados devem ent�o serem armazenados em uma pilha de forma que fiquem ordenados e que a maior nota fique no topo.
Em caso de empate entre duas notas a matr�cula pode ser utilizada como crit�rio de desempate, uma vez que n�o h� matr�culas repetidas.
Ao final do processo, desempilhar os elementos e apresent�-los na tela. Como tratam-se de dados com uma quantidade indefinida, n�o se deve utilizar um vetor para fazer a ordena��o dos dados.*/


//Bibliotecas necess�rias
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "Pilha.h"
#include "Fila.h"

using namespace std;


void organizarnotas(){ //Fun��o para organizar as notas em ordem decrescente na pilha

    TipoDadoFila elementofila; // Variavel para guardar os elementos da fila
    TipoDadoPilha elementopilha; // Variavel para guardar os elementos da pilha

    while(!Fila_Vazia()){
        if(Pilha_Vazia()){
            Fila_Desenfileirar(elementofila);
            elementopilha.matricula = elementofila.matricula;
            elementopilha.nota = elementofila.nota;
            Pilha_Empilhar(elementopilha);
        }
        else{
            Fila_Frente(elementofila);
            Pilha_Topo(elementopilha);
            if(elementofila.nota > elementopilha.nota){
                Fila_Desenfileirar(elementofila);
                elementopilha.matricula = elementofila.matricula;
                elementopilha.nota = elementofila.nota;
                Pilha_Empilhar(elementopilha);
            }
            else if(elementofila.nota == elementopilha.nota){
                if(elementofila.matricula > elementopilha.matricula){
                    Fila_Desenfileirar(elementofila);
                    elementopilha.matricula = elementofila.matricula;
                    elementopilha.nota = elementofila.nota;
                    Pilha_Empilhar(elementopilha);
                }
                else{
                    Pilha_Desempilhar(elementopilha);
                    elementofila.matricula = elementopilha.matricula;
                    elementofila.nota = elementopilha.nota;
                    Fila_Enfileirar(elementofila);
                }
            }
            else{
                Pilha_Desempilhar(elementopilha);
                elementofila.matricula = elementopilha.matricula;
                elementofila.nota = elementopilha.nota;
                Fila_Enfileirar(elementofila);
            }
        }
    }
}


int main()
{

    int opcao; // Variavel utilizada de indice no menu
    TipoDadoPilha alunopilha; // Variavel para guardar os elementos da pilha
    TipoDadoFila alunofila; // Variavel para guardar os elementos da fila

    Fila_Construtor(); // Para iniciar a fila;
    Pilha_Construtor(); // Para iniciar a pilha

     do{  //menu com op��es para testar a implementa��o da Fila Din�mica


          printf("Programa para ordenamento de notas\n\n");
          printf("Escolha uma das opcoes abaixo.");
          printf("\n\n\nMenu: \n");
          printf("\n1 - Adicionar nota");
          printf("\n2 - Parar de adicionar notas");
          printf("\n\n");
          scanf("%d", &opcao);

          switch(opcao){

             case 1:
                        printf("\n\nDigite a matricula: ");
                        scanf("%d", &alunofila.matricula);
                        printf("\nDigite a nota: ");
                        scanf("%d", &alunofila.nota);

                        if(Fila_Enfileirar(alunofila))  //Tenta armazenar na fila
                           printf("\n\nElemento armazenado na Fila\n\n");
                        else printf("Erro: Nao ha memoria disponivel\n\n");

                        system("pause");

                        break;

            case 2:
                        system("pause");
                        break;
          }
    }while(opcao != 2);

    printf("\n\n");

    organizarnotas();

    while(!Pilha_Vazia()){ // Apresentar na tela as notas em ordem decrescente
        Pilha_Desempilhar(alunopilha);
        printf("Matricula: %d\n", alunopilha.matricula);
        printf("Nota: %d\n\n", alunopilha.nota);
    }


    Pilha_Destrutor();
    Fila_Destrutor();

    return 0;
}
