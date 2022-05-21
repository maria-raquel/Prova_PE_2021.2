/*
>>>>>>>>>>> PROVA_PROGRAMAÇÃO_ESTRUTURADA <<<<<<<<<<<<<

* Professor: Igor Malheiros

>>>>>>>>>>>>>>>>>>>>>>>>>|<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
Alunos:
- Jonas Felipe | 20210026948
- Maria Raquel | 20200025900
*/
#include <stdio.h>
void plot_hist(int *notas, int tam);

void plot_hist(int *notas, int tam){
    int freq[11] = {0};
    for(int i = 0; i < tam; i++){
        freq[notas[i]]++;
    }
    printf("---- Histograma ------\n");
    for (int i = 0; i < 6; i++){
        printf("%.2d|",i);
        for (int j = 0; j < freq[i]; j++){
            printf("◼");
        }
        printf("\t(:c)\n");
    }
    for (int i = 6; i < 11; i++){
    printf("%.2d|",i);
    for (int j = 0; j < freq[i]; j++){
        printf("◼");
    }
    printf("\t(:D)\n");
    }
}


int main(){
    int notas[13] = {5, 3, 3, 8, 7, 10, 10, 0, 2, 7, 12, 9, 10};
    plot_hist(notas, 13);


}
