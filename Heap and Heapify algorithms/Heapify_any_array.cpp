#include <bits/stdc++.h>
// #define MAX 1000
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
    if (largest != i)
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
void buildheap(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; --i)
    {
        heapify(arr, n, i);
    }
}
int main()
{
    // 10 ,30,50,20,35,15
    // int arr[6] = {10, 30, 50, 20, 35, 15};
    // int n = 6;
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    // getline(cin,arr);
    buildheap(arr, n);
    printarray(arr, n);
    return 0;
}