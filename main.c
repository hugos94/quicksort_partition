#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <windows.h>

#include <sys/time.h>

struct timeval tv1, tv2;

int main(int argc, const char* argv[]){

    clock_t begin, end;
    double time_spent;

    int tam[9] = {100, 500, 1000, 5000, 30000, 80000, 100000, 150000, 200000}; //Vetor com os tamanhos de vetores para testes
    int i, j, k, position = 0, qntd = 0, partition = 0;

    for(j = 0; j < 9; j++){

            qntd = tam[j]; //Armazena o tamanho do vetor escolhido
            int vetH[qntd]; //Cria o vetor com o tamanho escolhido
            int vetL[qntd];
            double mediaH = 0;
            double mediaL = 0;

            for(k = 0; k < 20; k++){

                srand(time(NULL)); //Reinicia a semente aleatória

                for(i = 0; i < qntd; i++){ //Percorre todo o vetor adicionado os valores aleatórios
                    vetH[i] = vetL[i] = (rand()%qntd); //Armazena no vetor o valor aleatório gerado
                    //printf("%d ", vet[i]);
                }
                //printf("\n");

                gettimeofday(&tv1, NULL);

                int inicio = GetTickCount();

                quickSortH(&vetH,0,qntd); //Chama a função QuickSort

                int fim = GetTickCount();

                gettimeofday(&tv2, NULL);

                mediaH += (double) (tv2.tv_usec - tv1.tv_usec) / 1000000 +
         (double) (tv2.tv_sec - tv1.tv_sec);

                gettimeofday(&tv1, NULL);

                quickSortL(&vetL,0,qntd); //Chama a função QuickSort

               gettimeofday(&tv2, NULL);

               mediaL += (double) (tv2.tv_usec - tv1.tv_usec) / 1000000 +
         (double) (tv2.tv_sec - tv1.tv_sec);

            }
            mediaH = mediaH/20;
            mediaL = mediaL/20;

            printf("Media: %f %f\n", mediaH, mediaL);

    }


    return 0;
}

void swap(int *a, int i, int j)
{
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
}

void quickSortH(int *vet, int esq, int dir){
    int q;
    if(esq < dir){
        q = hoare_partition(vet, esq, dir);
        quickSortH(vet, esq, q);
        quickSortH(vet, q+1, dir);
    }
}


void quickSortL(int *vet, int esq, int dir){
    int q;
    if(esq < dir){
        q = lomuto_partition(vet, esq, dir);
        quickSortL(vet, esq, q-1);
        quickSortL(vet, q+1, dir);
    }
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


