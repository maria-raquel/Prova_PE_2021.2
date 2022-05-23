/*
>>>>>>>>>>> PROVA_PROGRAMAÇÃO_ESTRUTURADA <<<<<<<<<<<<<

* Professor: Igor Malheiros

>>>>>>>>>>>>>>>>>>>>>>>>>|<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
Alunos:
- Jonas Felipe | 20210026948
- Maria Raquel | 20200025900
*/

#ifndef FUNCOES_H
#define FUNCOES_H

//>================== Assinatura de funcoes: ==================

void clear(int *notas, int n);
void ord(int *notas, int n);
float desvio_padrao(int *notas, int n);
float media(int *notas, int n);
float mediana(int *notas, int n);
int repeticoes_nota(int *notas, int i);
int *moda(int *notas, int n, int *tm);
int valor_maximo(int *notas, int n);
int valor_minimo(int *notas, int n);
void plot_hist(int *notas, int n);
void printar_arrays(int *array, int n);

#endif