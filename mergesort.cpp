#include <iostream>

using namespace std;

int length(int *v)
{
    int tam = 0;
    for (int i = 0; v[i] != '\0'; i++)
    {
        tam++;
    }
    return tam;
}

void merge(int v[], int left, int middle, int right)
{
    int helper[length(v)];
    for (int i = left; i <= right; i++)
    {
        helper[i] = v[i];
    }

    int i = left;
    int j = middle + 1;
    int k = left;

    while (i <= middle && j <= right)
    {

        if (helper[i] < helper[j])
        {
            v[k] = helper[i];
            i++;
        }
        else
        {
            v[k] = helper[j];
            j++;
        }
        k++;
    }

    while (i <= middle)
    {
        v[k] = helper[i];
        i++;
        k++;
    }

    while (j <= right)
    {
        v[k] = helper[j];
        j++;
        k++;
    }
}

void mergeSort(int v[], int left, int right)
{

    if (left >= right)
        return;

    else
    {

        int middle = (left + right) / 2;
        mergeSort(v, left, middle);
        mergeSort(v, middle + 1, right);

        merge(v, left, middle, right);
    }
}

int main()
{

    int v[5] = {5, 4, 3, 2, 1};
    int n = (sizeof(v) / sizeof(int));
    mergeSort(v, 0, 5);
    return 0;
}