/*
>>>>>>>>>>> PROVA_PROGRAMAÇÃO_ESTRUTURADA <<<<<<<<<<<<<

* Professor: Igor Malheiros

>>>>>>>>>>>>>>>>>>>>>>>>>|<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
Alunos:
- Jonas Felipe | 20210026948
- Maria Raquel | 20200025900
*/

#include <stdio.h>
#include "funcoes.h"

int main(){
    int notas[13] = {5, 3, 3, 8, 7, 10, 10, -5, 2, 7, 12, 9, 10};
    int *modas;
    int n = 13; //tamanho do array notas

    clear(notas, n);
    ord(notas, n);

    printf("Media aritimedica: %f\n", media(notas, n));
    printf("Mediana: %f\n", mediana(notas, n));
    
    int tamanho_modas = 0, *tm;
    tm = &tamanho_modas;
    modas = moda(notas, n, tm);
    printf("Moda(s): ");
    printar_arrays(modas, tamanho_modas);

    printf("Desvio padrao: %f\n", desvio_padrao(notas, n));
    printf("Valor maximo: %d\n", valor_maximo(notas, n));
    printf("Valor minimo: %d\n", valor_minimo(notas, n));

    plot_hist(notas, n, 0);
    plot_hist(notas, n, 1);

    return 0;
}