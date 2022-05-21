int repeticoes_nota(int *notas, int i){
    if (notas[i] != notas[i+1])
        return 0;
    if (notas[i] == notas[i+1])
        return 1 + repeticoes_nota(notas, i+1);
}

int *moda(int *notas, int n){

    int modas[n], *modas_limpas, counts[n], maior_repeticao = 0, repeticoes = 0;

    counts[n-1] = 0;
    
    for(int i=0; i<n-1; i++)
        counts[i] = repeticoes_nota(notas, i);

    for(int i=0; i<n; i++)
        if (counts[i] > maior_repeticao)
            maior_repeticao = counts[i];

    for(int i=0; i<n; i++){
        if (counts[i] == maior_repeticao){
            modas[i] = notas[i];
            repeticoes++;
        }
        else modas[i] = -1;
    }
    
    modas_limpas = malloc(sizeof(int)*repeticoes);

    for(int i=0, j=0; i<n; i++)
        if (modas[i] != -1)
            modas_limpas[j++] = modas[i];

    return modas_limpas;
}