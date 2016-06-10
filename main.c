#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int main(int argc, const char* argv[]){

    int tam[9] = {100, 500, 1000, 5000, 30000, 80000, 100000, 150000, 200000}; //Vetor com os tamanhos de vetores para testes
    int i, position = 0, qntd = 0, partition = 0;

    //printf("Tamanhos de Vetores:\n1 - 100\n2 - 500\n3 - 1000\n4 - 5000\n5 - 30000\n6 - 80000\n7 - 100000\n8 - 150000\n9 - 200000\n\n");

    //printf("Informe o tamanho do vetor: ");
    //scanf("%d", &position);

    qntd = tam[8]; //Armazena o tamanho do vetor escolhido

    int vet[qntd]; //Cria o vetor com o tamanho escolhido

    srand(time(NULL)); //Reinicia a semente aleatória

    for(i = 0; i < qntd;i++){ //Percorre todo o vetor adicionado os valores aleatórios
        vet[i] = (rand()%qntd); //Armazena no vetor o valor aleatório gerado
        //printf("%d ", vet[i]);
    }
    //printf("\n");


    quickSort(&vet,0,qntd); //Chama a função QuickSort

    //for(i = 0; i < qntd; i++){
      //printf("%d ", vet[i]);
    //}
    //printf("\n");

    return 0;
}

void swap(int *a, int i, int j)
{
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
}

void quickSort(int *vet, int esq, int dir){
    int q;
    ///*
    if(esq < dir){
        q = lomuto_partition(vet, esq, dir);
        quickSort(vet, esq, q-1);
        quickSort(vet, q+1, dir);
    }
    //*/
    /*
    if(esq < dir){
        q = hoare_partition(vet, esq, dir);
        quickSort(vet, esq, q);
        quickSort(vet, q+1, dir);
    }
    */
}

int hoare_partition(int *vet, int esq, int dir){
    int pivot = vet[esq], i = esq - 1, j = dir + 1;
    while(true){
        do{
            i++;
        }while(vet[i] < pivot);
        do{
            j--;
        }while(vet[j] > pivot);
        if(i >= j){
            return j;
        }
        swap(vet, i, j);
    }
}

int lomuto_partition(int *vet, int esq, int dir){
    int x = vet[dir],i = esq - 1,j = esq;
    for(j = esq; j <= dir-1; j++){
        if(vet[j] <= x){
            i++;
            swap(vet, i, j);
        }
    }
    swap(vet, i+1, dir);
    return (i+1);
}


