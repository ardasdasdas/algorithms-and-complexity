#include<iostream>
int getSecondSmallestNumber(int array[], int N) {
    if (N <= 1) return array[0];

    int result[2];
    result[0] = array[0];
    result[1] = array[1];
    for (int i = 2; i < N; i++) {
        if (result[1] < result[0])
            std::swap(result[0], result[1]);
        if (array[i] < result[1] && result[0] != array[i]) {
            result[1] = array[i];
        }
    }
    return result[1];
}
int main() {
    int  A[8] = { 7, 9, 8, -2, -2, 5, 7, 5 };

    std::cout << getSecondSmallestNumber(A, 8);
}