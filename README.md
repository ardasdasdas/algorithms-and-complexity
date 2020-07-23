# Algorithms and Complexity
## Divide & Conquer
#### [Fast Long Integer Multiplication](https://github.com/ardasdasdas/algorithms-and-complexity/tree/master/Divide%20and%20Conquer/Long%20Integer%20Multiplication)
The problem that we want to consider is how to perform arithmetic on long integers, and multiplication in particular. The reason for doing arithmetic on long numbers stems from cryptography. Most techniques for encryption are based on number-theoretic techniques. For example, the character string to be encrypted is converted into a sequence of numbers, and encryption keys are stored as long integers.
## Sorting Algoritihms
|    Name     | Best-Case | Average-Case | Worst-Case |
| ----------- | --------- | ------------ | ---------- |
|  [QuickSort](https://github.com/ardasdasdas/algorithms-and-complexity/blob/master/Sorting%20Algortihms/QuickSort.cpp)  |   NlogN   |    NlogN     |    N^2     |
|  [MergeSort](https://github.com/ardasdasdas/algorithms-and-complexity/blob/master/Sorting%20Algortihms/MergeSort.cpp)  |   NlogN   |    NlogN     |     NlogN      |
|  [HeapSort](https://github.com/ardasdasdas/algorithms-and-complexity/blob/master/Sorting%20Algortihms/HeapSort.cpp)   |   NlogN   |    NlogN     |   NlogN    |
|[InsertionSort](https://github.com/ardasdasdas/algorithms-and-complexity/blob/master/Sorting%20Algortihms/InsertionSort.cpp)|     N     |     N^2      |    N'2     |
| [BubbleSort](https://github.com/ardasdasdas/algorithms-and-complexity/blob/master/Sorting%20Algortihms/BubbleSort.cpp)  |     N     |     N^2      |    N'2     |
## Different Examples
#### [Find Smallest Interval In An Array](https://github.com/ardasdasdas/algorithms-and-complexity/blob/master/Different%20Examples/findSmallestInterval.cpp)
Given a list of “n” numbers A = [a0, a1, …, an-1] and an integer k >=2, and to find the smallest interval [x..y] such that at least k numbers of the list lie within this interval. (The size of the interval [x..y] is y-x.) For example, if the array A is [3.1, 6.2, 10, 5.8, 2.2, 6.0, 7.3], and k = 4 then the interval [5.8..7.3] is the smallest interval containing 4 elements of the array (namely {5.8, 6.0, 6.2, 7.3}). May assume that k<=n.
#### [Get Second Smallest In An Array](https://github.com/ardasdasdas/algorithms-and-complexity/blob/master/Different%20Examples/getSecondSmallestNumber.cpp)
Write a function GetSecondSmallest(int A[], int N) that returns the second smallest number in the array without sorting. For example A[8] = { 7, 9, 8, -2, -2, 5, 7, 5 }
#### [Minimum Coin Exchange](https://github.com/ardasdasdas/algorithms-and-complexity/blob/master/Different%20Examples/minCoinExchange.cpp)
Given a value V, if we want to make a change for V Rs, and we have an infinite supply of each of the denominations in Turkish currency, i.e., we have an infinite supply of { 1, 2, 5, 10, 20, 50, 100 } valued coins, what is the minimum number of coins?
