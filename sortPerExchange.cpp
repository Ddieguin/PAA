#include <iostream>

using namespace std;

bool isSorted(int vector[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (vector[i] > vector[i + 1])
            return false;
    }
    return true;
}

void swap(int vetor[], int i, int j)
{
    int aux = vetor[i];
    vetor[i] = vetor[j];
    vetor[j] = aux;
}

void exchange(int vetor[], int inf, int tam)
{
    if (inf == tam)
    {
        if (isSorted(vetor, tam))
        {
            for (int i = 0; i <= tam; i++)
            {
                printf("%d", vetor[i]);
            }
            printf("\n");
        }
    }
    else
    {
        for (int i = inf; i <= tam; i++)
        {
            swap(vetor, inf, i);
            exchange(vetor, inf + 1, tam);
            swap(vetor, inf, i);
        }
    }
}

int main()
{

    int vector[] = {5, 6, 7, 8, 9, 10, 11, 1, 0};
    int n = sizeof(vector) / sizeof(int);
    exchange(vector, 0, n - 1);
}