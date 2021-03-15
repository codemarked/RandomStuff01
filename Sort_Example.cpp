#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

bool initialized = false;
int vector_size = 10;
int main_vector[30];

int backup_vector[30];

int getRandom(int max) {
    return rand() % max + 1;
}

void init(int v[], int size) {
    for (int i = 0;i < size;i++) {
        v[i] = getRandom(99);
    }
    initialized = true;
}

void view_vector(int v[], int size) {
    for (int i = 0;i < size;i++) {
        cout << v[i] << " ";
    }
}

void createBackup() {
    for (int i = 0;i < vector_size;i++) {
        backup_vector[i] = main_vector[i];
    }
}

void applyBackup() {
    for (int i = 0;i < vector_size;i++) {
        main_vector[i] = backup_vector[i];
    }
}

void insertionSort(int v[],int size)
{
    int i, j, x;
    for (i = 1;i < size;i++)
    {
        x = v[i];
        j = i - 1;
        while (j >= 0 && v[j] > x)
        {
            v[j + 1] = v[j];
            j -= 1;
        }
        v[j + 1] = x;
    }
}

void binaryInsertionSort(int v[],int size) {
    int i, j, stanga, dreapta, m, x;
    for (i = 2; i < size; i++)
    {
        x = v[i];
        stanga = 0;
        dreapta = i - 1;
        while (stanga <= dreapta) {
            m = (stanga + dreapta) / 2;
            if (x < v[m]) dreapta = m - 1;
            else stanga = m + 1;
        }
        for (j = i; j >= stanga + 1; j--)
            v[j] = v[j - 1];
        v[stanga] = x;
    }
}

void selectionSort(int v[], int size)
{
    int i, j, k, x;
    for (i = 0;i < size - 1;i++)
    {
        k = i;
        x = v[i];
        for (j = i + 1;j < size;j++)
            if (v[j] < x)
            {
                x = v[j];
                k = j;
            }
        v[k] = v[i];
        v[i] = x;
    }
}

void bubbleSort(int v[], int size) {
    int ok = 0,i=0,aux;
    while (ok == 0)
    {
        ok = 1;
        for (i = 0;i < size - 1;i++) {
            if (v[i] > v[i + 1]) {
                aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
                ok = 0;
            }
        }
    }
}

void shakerSort(int v[], int size)
{
    int j, k, l, r, x;
    l = 1;r = size-1;k = size;
    do
    {
        for (j = r;j >= l;j--)
            if (v[j - 1] > v[j])
            {
                x = v[j - 1];
                v[j - 1] = v[j];
                v[j] = x;
                k = j;
            }
        l = k + 1;
        for (j = l;j <= r;j++)
            if (v[j - 1] > v[j])
            {
                x = v[j - 1];
                v[j - 1] = v[j];
                v[j] = x;
                k = j;
            }
        r = k - 1;
    } while (l <= r);
}

int main() {
    char litera = 'X';
    while (true) {
        system("cls");
        cout << endl;
        cout << "Use the operations from below:" << endl;
        cout << "- C - Initiate the vector with random values" << endl;
        cout << "- V - View table" << endl;
        cout << "- R - Reinitialize table" << endl;
        cout << "- I - Insertion Sort" << endl;
        cout << "- B - Binary Insertion Sort" << endl;
        cout << "- S - Selection Sort" << endl;
        cout << "- T - Bubble Sort" << endl;
        cout << "- H - Shaker Sort" << endl;
        cout << "- X - Exit" << endl;
        cout << endl;
        if (initialized) {
            view_vector(main_vector, vector_size);
        }
        cout << endl;
        cin >> litera;
        switch (litera) {
        case 'C': {
            init(main_vector,vector_size);
            break;
        }
        case 'V': {
            view_vector(main_vector, vector_size);
            break;
        }
        case 'R': {
            applyBackup();
            break;
        }
        case 'I': {
            createBackup();
            insertionSort(main_vector,vector_size);
            break;
        }
        case 'B': {
            createBackup();
            binaryInsertionSort(main_vector, vector_size);
            break;
        }
        case 'S': {
            createBackup();
            selectionSort(main_vector, vector_size);
            break;
        }        
        case 'T': {
            createBackup();
            bubbleSort(main_vector, vector_size);
            break;
        }        
        case 'H': {
            createBackup();
            shakerSort(main_vector, vector_size);
            break;
        }        
        case 'X': {
            exit(0);
            break;
        }
        }
    }
}
