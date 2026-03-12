#ifndef heapsort_sort_me
#define heapsort_sort_me

#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
void heapify(vector<T>& arr, long long n, long long i) {
    while (true) {
        long long largest = i;
        long long left = 2 * i + 1;
        long long right = 2 * i + 2;

        if (left < n && arr[left] > arr[largest])
            largest = left;

        if (right < n && arr[right] > arr[largest])
            largest = right;

        if (largest != i) {
            std::swap(arr[i], arr[largest]);
            i = largest;
        } else {
            break;
        }
    }
}

template <typename T>
void buildMaxHeap(vector<T>& arr,long long n) {
    for (long long i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

template <typename T>
void heapSort(vector<T>& arr) {
    long long n = arr.size();

    buildMaxHeap(arr,n);

    for (long long i = n-1;i>0;i--) {
        swap(arr[0], arr[i]); 
        heapify(arr,i,0);
    }
}

#endif