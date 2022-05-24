/*
>>>>>>>>>>> PROVA_1_PROGRAMAÇÃO_ESTRUTURADA <<<<<<<<<<<<<

* Professor: Igor Malheiros

>>>>>>>>>>>>>>>>>>>>>>>>>>|<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
Alunos:
- Jonas Felipe | 20210026948
- Maria Raquel | 20200025900
*/

#include "limpeza.h"

//>================== LIMPEZA E ORGANIZACAO DOS DADOS: ==================

/*Funcao que realiza a limpeza de notas invalidas nos dados. 
  Notas maiores que 10 são transformadas em 10, e menores que 0 em 0.
    > int *notas = array de notas 
    > int n = tamanho do array
*/
void limpeza(int *notas, int n){
    for (int i = 0; i < n; i++){
        if (notas[i] > 10){
            notas[i] = 10;
        }
        if (notas[i] < 0){
            notas[i] = 0;
        }
    }
}

/*Funcao que organiza o array de notas em ordem crescente, pelo metodo bubble sort
    > int *notas = array de notas 
    > int n = tamanho do array
*/
void ordenacao(int *notas, int n){
    int temp = 0;
    int troca;
    do{
        troca = 0; //a variavel troca indica se houve uma troca de valores na ordencao (inicia False)
        for(int i = 0; i < n-1; i++){ //percorre todos os elementos do array 
            if (notas[i] > notas[i+1]){ //se o valor do array for menor que o proximo ele realiza a troca
                temp = notas[i];
                notas[i] = notas[i+1];
                notas[i+1] = temp;
                troca = 1; //como houve troca a variavel "troca" recebe True
            }
        }
    }while(troca);  //enquanto houver trocas essa ordenacao e executada
}