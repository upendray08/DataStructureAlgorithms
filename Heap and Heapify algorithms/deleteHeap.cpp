#include <bits/stdc++.h>
using namespace std;
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }
    if (i != largest)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
void printarray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void deleteRoot(int arr[], int &n)
{
    int lastelement = arr[n - 1];
    arr[0] = lastelement;
    n = n - 1;
    heapify(arr, n, 0);
    printarray(arr, n);
}

int main()
{
    // Array representation of Max-Heap
    //     10
    //    /  \
    //   5    3
    //  / \
    // 2   4
    int arr[] = {10, 5, 3, 2, 4};
    int n = sizeof(arr) / sizeof(int);
    printarray(arr, n);
    deleteRoot(arr, n);
    // printarray(arr, n - 1);
    deleteRoot(arr, n);
    deleteRoot(arr, n);
    deleteRoot(arr, n) ;
    deleteRoot(arr, n);
    // printarray(arr, n);
    return 0;
}