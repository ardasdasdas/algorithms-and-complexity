#include<iostream>
using namespace std;
void findSmallestInterval(double A[], int N, int k) {
    if (N <= 1 || k <= 1 || N < k) return; // N ve k degerlerini kontrol ettim

    double* intervalArray = new double[k]; // elde edeceğim sonucu tutmak icin bir adet k boyutunda dizi tanimladım

    heapSort(A, N); //best-case, average-case ve worst-case'leri nlogn oldugu icin heapSort'u kullandım
    double smallestInterval = A[k - 1] - A[0]; // siralanmis arrayde verilen k degerine karsilik gelen sayidan en kucuk sayiyi cikardim
    int index[2];// en kucuk araligi veren sayilarin dizideki indekslerini tutabilmek icin bir dizi olusturdum
    index[0] = 0;
    index[1] = k - 1;
    for (int i = 1; i < N / 2; i++)// donguyu N/2'ye kadar dondurdum cunku i+k-1 indeksini kontrol ettigidim icin N/2'den sonrasi NULL deger verecekti
    {
        if (A[i + k - 1] - A[i] < smallestInterval && i + k - 1 < N) // en kucuk araligi ve bu araligi saglayan sayilarin indekslerini bu if else yapisi ile buldum 
        {
            smallestInterval = A[i + k - 1] - A[i];
            index[0] = i;
            index[1] = i + k - 1;
        }
    }
    int j = 0;
    for (int i = index[0]; i < index[1] + 1; i++) // buldugum indeksleri burada kullandim ve en kucuk araligi saglayan k adet sayiyi diziye kaydettim
    {
        intervalArray[j] = A[i];
        j++;
    }
    for (int i = 0; i < k; i++) // buldugum diziyi ekrana yazdirdim
    {
        cout << intervalArray[i] << " ";
    }
}
int main() {
    double  A[7] = { 3.1, 6.2, 10, 5.8, 2.2, 6.0, 7.3 };

    findSmallestInterval(A, 7, 4);
}