#include<iostream>
#define size 5
void insertionSort(int array[], int n) {
    if (n <= 1)
        return;

    insertionSort(array, n - 1);

    int last = array[n - 1];
    int j = n - 2;

    while (j >= 0 && array[j] > last) {
        array[j + 1] = array[j];
        j--;
    }
    array[j + 1] = last;
}
int main() {
    int A[size] = { 5,8,1,2,3 };
    insertionSort(A, size);
    for (int i = 0; i < size; i++) 
        std::cout << A[i] << " ";
}