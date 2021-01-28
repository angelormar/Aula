#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int partition(int *vetP, int inicio, int fim)
{
    int pivo, aux;
    int esq = inicio;
    int dir = fim;
    pivo = vetP[inicio];

    while (esq < dir)
    {
        while (vetP[esq] <= pivo)
        {
            esq++;
        }
        while (vetP[dir] > pivo)
        {
            dir--;
        }
        if (esq < dir)
        {
            aux = vetP[esq];
            vetP[esq] = vetP[dir];
            vetP[dir] = aux;
        }
    }

    vetP[inicio] = vetP[dir];
    vetP[dir] = pivo;

    return dir;
}

/*Esta função leva o último elemento como pivô, lugares
o elemento pivô em sua posição correta na classificação
array e coloca todos menores (menores que pivô)
à esquerda do pivô e todos os elementos maiores à direita
de pivô
*/
int partition2(int *vetP, int inicio, int fim)
{
    int pivo, aux, j;
    int i = inicio;
    pivo = vetP[fim];

    for (j = inicio; j < fim; j++)
    {

        if (vetP[j] <= pivo)
        {

            aux = vetP[j];
            vetP[j] = vetP[i];
            vetP[i] = aux;

            i++;
        }
    }
    vetP[fim] = vetP[i];
    vetP[i] = pivo;

    return i;
}

/* A função principal que implementa QuickSort
vetP -> Array a ser classificado,
inicio -> Índice inicial,
fim -> Índice final */
void quicksort(int *vetP, int inicio, int fim)
{
    int pivo;

    if (fim > inicio)
    {

        /* pivo é o índice de particionamento*/
        pivo = partition(vetP, inicio, fim);

        // Classifica os elementos separadamente antes
        // da partição e depois da partição
        quicksort(vetP, inicio, pivo - 1);
        quicksort(vetP, pivo + 1, fim);
    }
}

int merge(int *vetP, int inicio, int meio, int fim)
{
    int tamanho = fim - inicio + 1, k;
    int esquerdo = inicio;
    int direito = meio + 1;
    int fim_esquerdo = 0;
    int fim_direito = 0, *ordenado;
    ordenado = (int *)malloc(sizeof(int) * tamanho);
    if (ordenado == NULL){
    return 0;
    }

    for (int i = 0; i < tamanho; i++)
    {
        if (!fim_esquerdo && !fim_direito)
        {
            if (vetP[esquerdo] < vetP[direito])
            {
                ordenado[i] = vetP[esquerdo];
                esquerdo++;
            }
            else
            {
                ordenado[i] = vetP[direito];
                direito++;
            }
            if (esquerdo > meio)
            {
                fim_esquerdo = 1;
            }

            if (direito > fim)
            {
                fim_direito = 1;
            }
        }
        else
        {
            if (!fim_esquerdo)
            {
                ordenado[i] = vetP[esquerdo];
                esquerdo++;
            }
            else
            {
                ordenado[i] = vetP[direito];
                direito++;
            }
        }
    }

    for (int j = 0, k = inicio; j < tamanho; j++, k++)
    {
        vetP[k] = ordenado[j];
    }
}

int mergesort(int *vetP, int inicio, int fim)
{
    int meio;

    if (inicio < fim)
    {
        meio = floor((inicio + fim) / 2); //4  

        mergesort(vetP, inicio, meio);
        mergesort(vetP, meio + 1, fim);
        merge(vetP, inicio, meio, fim);
    }
}

int main()
{

    int vet[8] = {1,2,3,4,5,6,7,8}, *vetP;
    vetP = vet;
    //mergesort(vetP, 0, 8);
    quicksort(vetP, 0, 8);

    for (int i = 0; i < 8; i++)
    {
        printf(" %d", vetP[i]);
    }
}