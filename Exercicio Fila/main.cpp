/*Lucas Assunção Basilio
Armazenar em uma fila uma sequência aleatória e com quantidade indefinida de matrículas e notas que os alunos tiraram em uma prova.
Os dados devem ser fornecidos pelo usuário e armazenados em uma fila na mesma ordem em que foram digitados.
Sempre que o usuário fornece uma matrícula deve fornecer também a respectiva nota do aluno.
Os dados devem então serem armazenados em uma pilha de forma que fiquem ordenados e que a maior nota fique no topo.
Em caso de empate entre duas notas a matrícula pode ser utilizada como critério de desempate, uma vez que não há matrículas repetidas.
Ao final do processo, desempilhar os elementos e apresentá-los na tela. Como tratam-se de dados com uma quantidade indefinida, não se deve utilizar um vetor para fazer a ordenação dos dados.*/


//Bibliotecas necessárias
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "Pilha.h"
#include "Fila.h"

using namespace std;


void organizarnotas(){ //Função para organizar as notas em ordem decrescente na pilha

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

     do{  //menu com opções para testar a implementação da Fila Dinâmica


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
