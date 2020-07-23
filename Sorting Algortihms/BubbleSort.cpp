#include<iostream>
#define size 5
void bubbleSort(int array[], int n) {
    if (n <= 1)
        return;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-i-1; j++) {
                if (A[j] > A[j + 1])
                std::swap(A[j], A[j + 1]);
        }
    }
}
int main() {
    int A[size] = { 5,8,1,2,3 };
    bubbleSort(A, size);
    for (int i = 0; i < size; i++)
        std::cout << A[i] << " ";
}
