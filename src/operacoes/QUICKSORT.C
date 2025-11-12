#include "quicksort.H"
#include <string.h>

//função de troca
static void trocar(Conta* a, Conta* b){ 
    Conta aux=*a; 
    *a=*b; 
    *b=aux; 
}

static int particionar_por_nome(Conta vet[], int low, int high){
    Conta pivo = vet[high];
    int i = low;

    for(int j = low; j < high; j++){
        if(strcmp(vet[j].Nome, pivo.Nome) <= 0){
            trocar(&vet[i], &vet[j]);
            i++;
        }
    }

    trocar(&vet[i], &vet[high]);
    return i;
}

static int particionar_por_conta(Conta vet[], int low, int high) {
    Conta pivo = vet[high];
    int i = low;

    for (int j = low; j < high; j++) {
        if (vet[j].Conta <= pivo.Conta) {
            trocar(&vet[i], &vet[j]);
            i++;
        }
    }

    trocar(&vet[i], &vet[high]);
    return i;
}

void quicksort_nome(Conta vet[], int low, int high) {
    if (low < high) { 
        int pi = particionar_por_nome(vet, low, high); 
        quicksort_nome(vet, low, pi - 1); 
        quicksort_nome(vet, pi + 1, high); 
    }
}

void quicksort_conta(Conta vet[], int low, int high) {
    if (low < high) { 
        int pi = particionar_por_conta(vet, low, high); 
        quicksort_conta(vet, low, pi - 1); 
        quicksort_conta(vet, pi + 1, high); 
    }
}



