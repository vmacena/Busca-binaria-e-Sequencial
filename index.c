/*Faça um programa em C que crie um vetor com 500 números inteiros gerados
aleatoriamente. Em seguida, o programa deverá solicitar um valor do usuário a
ser buscado no vetor e verificar se o mesmo pertence ou não ao vetor,
imprimindo a mensagem ao usuário.
O programa deverá implementar duas formas de busca no vetor: sequencial e
binária. Para realizar a busca binária, você deverá criar o seu próprio algoritmo
de ordenação. 
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define SIZE 500


int randInt(int min, int max) {
    return min + rand() % (max - min + 1);
}


void sort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}


int searchSequential(int arr[], int n, int x) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}


int searchBinary(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x) {
            return mid;
        }
        if (arr[mid] > x) {
            return searchBinary(arr, l, mid - 1, x);
        }
        return searchBinary(arr, mid + 1, r, x);
    }
    return -1;
}

int main() {
    int arr[SIZE];
    int i, x, result;

    
    srand(time(NULL));


    for (i = 0; i < SIZE; i++) {
        arr[i] = randInt(1, 500);
    }


    sort(arr, SIZE);

    printf("\n");


    printf("Digite um numero a ser buscado no vetor: ");
    scanf("%d", &x);

 
    result = searchSequential(arr, SIZE, x);
    if (result == -1) {
        printf("%d nao encontrado no vetor (busca sequencial)\n", x);
    } else {
        printf("%d encontrado na posicao %d (busca sequencial)\n", x, result);
    }

   
    result = searchBinary(arr, 0, SIZE - 1, x);
    if (result == -1) {
        printf("%d nao encontrado no vetor (busca binaria)\n", x);
    } else {
        printf("%d encontrado na posicao %d (busca binaria)\n", x, result);
    }

  
    printf("Vetor ordenado:\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
