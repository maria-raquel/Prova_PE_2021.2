/*
>>>>>>>>>>> PROVA_PROGRAMAÇÃO_ESTRUTURADA <<<<<<<<<<<<<

* Professor: Igor Malheiros

>>>>>>>>>>>>>>>>>>>>>>>>>|<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
Alunos:
- Jonas Felipe | 20210026948
- Maria Raquel | 20200025900
*/
#include <stdio.h>

void clear(int *notas, int tam);

void clear(int *notas, int tam){
    for (int i = 0; i < tam; i++){
        if (notas[i] > 10){
            notas[i] = 10;
        }
        if (notas[i] < 0){
            notas[i] = 0;
        }
    }
}
