#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int set_size = 50;
int set_numbers[50];

int cut_size = 6;
int cut_return[6];

int getRandom(int max) {
    return rand() % max + 1;
}

void init(int v[], int size) {
    for (int i = 0;i < size;i++) {
        cout << (v[i] = getRandom(99)) << " ";
    }
    cout << endl;
}

void randomCut(int v[], int size) {
    int random_int, added = 0,cut;
    for (int i = 0;i < 6;i++) {
        random_int = getRandom(size - 1);
        cut = v[random_int];
        v[random_int] = 0;
        cut_return[added] = cut;
        cout << cut << " ";
        added++;
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

void view(int v[], int size) {
    for (int i = 0;i < size;i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    cout << "Initializing random number array" << endl;
    init(set_numbers, set_size);
    cout << endl << "Extracting numbers:" << endl;
    randomCut(set_numbers, set_size);
    selectionSort(cut_return, cut_size);
    cout << endl << endl << "Displaying sorted array(Selection Sort):" << endl;
    view(cut_return, cut_size);
}
