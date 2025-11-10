#include "QUICKSORT.H"
#include <string.h>

static void trocar(Cliente* a, Cliente* b){ 
    Cliente aux=*a; 
    *a=*b; 
    *b=aux; 
}

static int conta(Cliente vet[], int low, int high){
    Cliente pi = vet[high];
    int i = low;

    for(int j = low; j < high; j++){
        if(strcmp(vet[j].conta, pi.conta) <= 0){
            trocar(&vet[i], &vet[j]);
            i++;
        }
    }

    trocar(&vet[i], &vet[high]);
    return i;
}

void quicksort(Cliente vet[],int low,int high){
    if(low < high){ 
        int pi=conta(vet, low, high); 
        quicksort(vet, low, pi - 1); 
        quicksort(vet, pi + 1, high); 
    }
}

static int nome(Cliente vet[], int low, int high){
    Cliente pi = vet[high];
    int i = low;

    for(int j = low; j < high; j++){
        if(strcmp(vet[j].nome, pi.nome) <= 0){
            trocar(&vet[i], &vet[j]);
            i++;
        }
    }

    trocar(&vet[i], &vet[high]);
    return 1;
}

void quicksort(Cliente vet[],int low,int high){
    if(low < high){ 
        int pi=nome(vet, low, high); 
        quicksort(vet, low, pi - 1); 
        quicksort(vet, pi + 1, high); 
    }
}
