#include <bits/stdc++.h>
using namespace std;
// int arr[1001];
#define MAX 1000 // max size heap 1000
void heapify(int arr[], int n, int i)
{
    int parent = (i - 1) / 2;
    if (arr[i] > arr[parent] && parent >= 0)
    {
        swap(arr[i], arr[parent]);
        // recursively
        heapify(arr, n, parent);
    }
}
void insertHeap(int arr[], int &n, int value)
{
    n = n + 1;
    arr[n - 1] = value;
    heapify(arr, n, n - 1);
}
void printarray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    // Array representation of Max-Heap
    //     10
    //    /  \
    //   5    3
    //  / \
    // 2   4
    // int arr[MAX] = {10, 5, 3, 2, 4};
    int arr[MAX];
    // int n = 5;
    // printarray(arr, n);
    int n = 0;
    printarray(arr, n);
    insertHeap(arr, n, 20);
    insertHeap(arr, n, 10);
    insertHeap(arr, n, 30);
    insertHeap(arr, n, 5);
    insertHeap(arr, n, 50);
    insertHeap(arr, n, 40);
    printarray(arr, n);

    return 0;
}