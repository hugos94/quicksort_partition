
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, const char* argv[]){

    int tam[9] = {100, 500, 1000, 5000, 30000, 80000, 100000, 150000, 200000}; //Vetor com os tamanhos de vetores para testes
    int i, position = 0, qntd = 0, partition = 0;

    printf("Tamanhos de Vetores:\n1 - 100\n2 - 500\n3 - 1000\n4 - 5000\n5 - 30000\n6 - 80000\n7 - 100000\n8 - 150000\n9 - 200000\n\n");

    printf("Informe o tamanho do vetor: ");
    scanf("%d", &position);

    qntd = tam[position-1]; //Armazena o tamanho do vetor escolhido

    int vet[qntd]; //Cria o vetor com o tamanho escolhido

    srand(time(NULL)); //Reinicia a semente aleatória

    for(i = 0; i < qntd;i++){ //Percorre todo o vetor adicionado os valores aleatórios
        vet[i] = (rand()%qntd); //Armazena no vetor o valor aleatório gerado
    }

    //const char *metodos[] = {"1 - Hoare","2 - Lomuto", "3 - One-sided", "4 - Gries", "5 - Sedgewick"};

    printf("Métodos de Partição:\n1 - Hoare\n2 - Lomuto\n3 - One-sided\n4 - Gries\n5 - Sedgewick\n\n");

    printf("Informe o método de partição a ser utilizado: ");
    scanf("%d", &partition);

    quickSort(vet,0,qntd-1); //Chama a função QuickSort

    for(i = 0; i < qntd; i++){
      printf("%d ", vet[i]);
    }
    printf("\n");


    return 0;
}

void quickSort(int vet[], int esq, int dir){
  int i, j, pivo, aux;
  i = esq;
  j = dir;
  pivo = vet[(esq+dir)/2];

  while(i <= j){
    while(vet[i] < pivo && i < dir){
        i++;
    }
    while(vet[j] > pivo && j > esq){
        j--;
    }
    if(i <= j){
        aux = vet[i];
        vet[i] = vet[j];
        vet[j] = aux;
        i++;
        j--;
    }
    int cont;
    for(cont = 0; cont < 10; cont++){
        printf("%d ", vet[cont]);
    }
    printf("\n");
  }
  if(j > esq){
    quickSort(vet, esq, j);
  }
  if(i < dir){
    quickSort(vet,i, dir);
  }
}

int hoare_partition(int vet[], int esq, int dir){
    int x = vet[esq];
    int i = esq - 1;
    int j = dir + 1;
    while(true){
        while(vet[j] <= x){
            j--;
        }
        while(vet[i] >= x){
            i++;
        }
        if(i < j){
            swap(vet[i], vet[j]);
        }else{
        return j;
        }
    }
}

int lomuto_partition(int vet[], int esq, int dir){
    int x = vet[dir];
    int i = esq - 1;
    int j;
    for(j = esq; j <= dir-1; j++){
        if(vet[j] <= x){
            i++;
            swap(vet[i], vet[j]);
        }
    }
    swap(vet[i+1], vet[dir]);
    return (i+1);
}

void swap(int a, int b){int aux = a; a = b; b = aux;}
