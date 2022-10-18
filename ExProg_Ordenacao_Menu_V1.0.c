/*
    Centro Universit�rio de Goi�s - Uni-Anhanguera
    Disciplina: Algoritmos e Programa��o Estruturada
    Professor:  Sandro Teixeira Carvalho
    Alunos(a):  Gabriel de Castro Costa         -   202113117
                Gustavo Muller Bueno Lagares    -   202151136
    Objetivo:   Desenvolvimento de programa com algoritmos para
                variados metodos de ordenacao, com menu de selecao
                e contagem de tempo de execucao de cada metodo.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZEARRAY 100000
#define LIMITRAND 50000



int menuPrograma();
void menuProgramaAciona(int opcao, int *arrayCalled);
void preencherArray(int *array, int sizeArray);
void imprimirArray(int *array, int sizeArray);
void ordenaBubbleSort(int *array, int sizeArray);
void ordernaInsertionSort(int *array, int sizeArray);
void ordenaSelectionSort(int *array, int sizeArray);
void ordenaHeapSort(int *array, int N);
void ordenaQuickSort(int *array, int inicio, int fim);
void ordenaMergeSort(int *array, int sizeArr);
void sort(int *array, int *arrayTmp, int initArr, int endArr);
void merge(int *array, int *arrayTmp, int initArr, int midArr, int endArr);
void ordenaShellSort(int *array, int sizeArray);



//Main
int main(void){

    int opcaoSelect;
    int emptyArray[SIZEARRAY];

    do {
        opcaoSelect = menuPrograma();
        menuProgramaAciona(opcaoSelect, emptyArray);
    }
    while(opcaoSelect != 0);

    return 0;
}


//Menu com opcoes
int menuPrograma(){
    int opcaoMenu;

    printf("********** PROGRAMA COM METODOS DE ORDENACAO **********");
    printf("\n\nEscolha uma das opcoes abaixo: \n\n");
    printf("  (1) Preencher o array com numeros aleatorios\n");
    printf("  (2) Ordenar o array pelo metodo Bubble Sort\n");
    printf("  (3) Ordenar o array pelo metodo Insertion Sort\n");
    printf("  (4) Ordenar o array pelo metodo Selection Sort\n");
    printf("  (5) Ordenar o array pelo metodo Heap Sort\n");
    printf("  (6) Ordenar o array pelo metodo Quick Sort\n");
    printf("  (7) Ordenar o array pelo metodo Merge Sort\n");
    printf("  (8) Ordenar o array pelo metodo Shell Sort\n");
    printf("  (9) Imprimir o array...\n");
    printf("  (0) Para sair..\n\n");
    printf("  Opcao: ");
    scanf("  %d", &opcaoMenu);

    return opcaoMenu;
}


//Menu com acoes
void menuProgramaAciona(int opcao, int *arrayCalled){

    clock_t timer;

    switch(opcao)
    {
        case 0: break;

        case 1:
            preencherArray(arrayCalled, SIZEARRAY);
            printf("Array preenchido\n\n");
        break;

        case 2:
            printf("--- Metodo Bubble Sort selecionado ---\n");
            timer = clock();
            printf("Ordenando... ");
            ordenaBubbleSort(arrayCalled, SIZEARRAY);
            timer = clock() - timer;
            printf("Pronto, a ordenacao levou %fs\n\n", ((float) timer / CLOCKS_PER_SEC));
        break;

        case 3:
            printf("--- Metodo Insertion Sort selecionado ---\n");
            timer = clock();
            printf("Ordenando... ");
            ordernaInsertionSort(arrayCalled, SIZEARRAY);
            timer = clock() - timer;
            printf("Pronto, a ordenacao levou %fs\n\n", ((float) timer / CLOCKS_PER_SEC));
        break;

        case 4:
            printf("--- Metodo Selection Sort selecionado ---\n");
            timer = clock();
            printf("Ordenando... ");
            ordenaSelectionSort(arrayCalled, SIZEARRAY);
            timer = clock() - timer;
            printf("Pronto, a ordenacao levou %fs\n\n", ((float) timer / CLOCKS_PER_SEC));
        break;

        case 5:
            printf("Metodo Heap Sort selecionado!\n\n");
             timer = clock();
            printf("Ordenando... ");
            ordenaHeapSort(arrayCalled, SIZEARRAY);
            timer = clock() - timer;
            printf("Pronto, a ordenacao levou %fs\n\n", ((float) timer / CLOCKS_PER_SEC));
        break;

        case 6:
            printf("Metodo Quick Sort selecionado!\n\n");
             timer = clock();
            printf("Ordenando... ");
            ordenaQuickSort(arrayCalled, 0, SIZEARRAY);
            timer = clock() - timer;
            printf("Pronto, a ordenacao levou %fs\n\n", ((float) timer / CLOCKS_PER_SEC));
        break;

        case 7:
            printf("--- Metodo Merge Sort selecionado ---\n");
            timer = clock();
            printf("Ordenando...");
            ordenaMergeSort(arrayCalled,SIZEARRAY);
            timer = clock() - timer;
            printf("Pronto, a ordenacao levou %fs\n\n", ((float) timer / CLOCKS_PER_SEC));
        break;

        case 8:
            printf("--- Metodo Shell Sort selecionado! ---\n");
            timer = clock();
            printf("Ordenando... ");
            ordenaShellSort(arrayCalled, SIZEARRAY);
            timer = clock() - timer;
            printf("Pronto, a ordenacao levou  %fs\n\n", ((float) timer / CLOCKS_PER_SEC));
        break;

        case 9:
            imprimirArray(arrayCalled, SIZEARRAY);
        break;

        default:
            printf("Opcao Invalida\n");
    }
}


//Metodo para preencher array
void preencherArray(int *array, int sizeArray){
    int countA;

    srand(time(NULL));

    for(countA = 0; countA < sizeArray; countA++){
        array[countA] = 1+(rand()%LIMITRAND);
    }
}


//Metodo para imprimir o array preenchido
void imprimirArray(int *array, int sizeArray){
    int countB;
    int flagLimit = 0;
    const int VISUALLIMIT = 100;

    printf("\n");

    for(countB = 0; countB < sizeArray; countB++){
        if(countB < VISUALLIMIT || countB > sizeArray - (VISUALLIMIT + 1)) {
            printf("%d ", array[countB]);
        } else {
            if (flagLimit == 0){
                printf(" ... ");
                flagLimit = 1;
            }
        }

    }

    printf("\n\n");
}


//Metodo para ordenacao - BubbleSort
void ordenaBubbleSort(int *array, int sizeArray) {
    int loopOutPos, loopInPos, varAuxCh;

    for (loopOutPos = 0; loopOutPos < sizeArray - 1; loopOutPos++){
        for(loopInPos = loopOutPos + 1; loopInPos < sizeArray; loopInPos++){
            if(array[loopOutPos] > array[loopInPos]){
                varAuxCh = array[loopInPos];
                array[loopInPos] = array[loopOutPos];
                array[loopOutPos] = varAuxCh;
            }
        }
    }
}


//Metodo para ordenacao - Insertion Sort
void ordernaInsertionSort(int *array, int sizeArray){

    int loopOut, loopIn, auxVar;

    for(loopOut = 1; loopOut < sizeArray; loopOut++) {
        auxVar = array[loopOut];
        for(loopIn = loopOut-1; loopIn >= 0 && auxVar < array[loopIn]; loopIn--) {
            array[loopIn+1] = array[loopIn];
        }
        array[loopIn+1] = auxVar;
     }

}


//Metodo para ordenacao - Selection Sort
void ordenaSelectionSort(int *array, int sizeArray){
    int loopOutPos, loopInPos, minValue, auxVar;

    for (loopOutPos = 0; loopOutPos < (sizeArray-1); loopOutPos++) {
        minValue = loopOutPos;
        for (loopInPos = (loopOutPos+1); loopInPos < sizeArray; loopInPos++) {
            if(array[loopInPos] < array[minValue]) {
                minValue = loopInPos;
            }
        }
        if(array[loopOutPos] != array[minValue]) {
            auxVar = array[loopOutPos];
            array[loopOutPos] = array[minValue];
            array[minValue] = auxVar;
        }
    }
}

void troca(int* a, int* b)
{
    int temp = *a;

    *a = *b;

    *b = temp;
}


void heapify(int *array, int N, int i)
{

    int maior = i;
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;

    if (esquerda < N && array[esquerda] > array[maior])

        maior = esquerda;


    if (direita < N && array[direita] > array[maior])

        maior = direita;


    if (maior != i) {

        troca(&array[i], &array[maior]);

        heapify(array, N, maior);
    }
}

//Metodo para ordenacao - Heap Sort
void ordenaHeapSort(int *array, int N){

    for (int i = N / 2 - 1; i >= 0; i--)

        heapify(array, N, i);

    // Heap sort
    for (int i = N - 1; i >= 0; i--) {

        troca(&array[0], &array[i]);

        heapify(array, i, 0);
    }
}

// Metodo para ordenacao - Quick Sort

void ordenaQuickSort(int *array, int inicio, int fim)
{
	int i, j, pivo, aux;
	i = inicio;
	j = fim-1;
	pivo = array[(inicio + fim) / 2];
	while(i <= j)
	{
		while(array[i] < pivo && i < fim)
		{
			i++;
		}
		while(array[j] > pivo && j > inicio)
		{
			j--;
		}
		if(i <= j)
		{
			aux = array[i];
			array[i] = array[j];
			array[j] = aux;
			i++;
			j--;
		}
	}
	if(j > inicio)
		ordenaQuickSort(array, inicio, j+1);
	if(i < fim)
		ordenaQuickSort(array, i, fim);
}


//Metodo para ordenacao - Merge Sort
void ordenaMergeSort(int *array, int sizeArr) {
    int *arrayTmp = malloc(sizeof(int) * sizeArr);
    sort(array, arrayTmp, 0, sizeArr - 1);
    free(arrayTmp);
}

void sort(int *array, int *arrayTmp, int initArr, int endArr) {
    if (initArr >= endArr) return;

    int midArr = (initArr + endArr) / 2;

    sort(array, arrayTmp, initArr, midArr);
    sort(array, arrayTmp, midArr + 1, endArr);

    if (array[midArr] <= array[midArr + 1]) return;

    merge(array, arrayTmp, initArr, midArr, endArr);
}

void merge(int *array, int *arrayTmp, int initArr, int midArr, int endArr) {
    int auxVar,
        initMainArr = initArr, initTmpArr = midArr + 1;

    for (auxVar = initArr; auxVar <= endArr; auxVar++) arrayTmp[auxVar] =  array[auxVar];

    auxVar = initArr;

    while (initMainArr <= midArr && initTmpArr <= endArr) {
        if (arrayTmp[initMainArr] <= arrayTmp[initTmpArr])  array[auxVar++] = arrayTmp[initMainArr++];
        else  array[auxVar++] = arrayTmp[initTmpArr++];
    }

    while (initMainArr <= midArr)  array[auxVar++] = arrayTmp[initMainArr++];

    while (initTmpArr <= endArr)  array[auxVar++] = arrayTmp[initTmpArr++];

}


//Metodo para ordenacao - Shell Sort
void ordenaShellSort(int *array, int sizeArray){
    int loopOut, loopIn, valueVar;
    int gapVar = 1;

    while(gapVar < sizeArray){
        gapVar = 3*gapVar+1;
    }

    while(gapVar > 1) {
        gapVar = gapVar / 3;
        for(loopOut = gapVar; loopOut < sizeArray; loopOut++){
            valueVar = array[loopOut];
            loopIn = loopOut - gapVar;
            while(loopIn >= 0 && valueVar < array[loopIn]) {
                array[loopIn + gapVar] = array[loopIn];
                loopIn = loopIn - gapVar;
            }
            array [loopIn + gapVar] = valueVar;
        }
    }
}


