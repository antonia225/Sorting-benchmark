#ifndef QUICK_SORT_M3_H
#define QUICK_SORT_M3_H

#include <vector>
#include <algorithm>
using namespace std;

#ifndef MAX_RECURSION_DEPTH
#define MAX_RECURSION_DEPTH 10000
#endif

template <typename T>
long long medianOfThree(vector<T> &v, long long low, long long high)
{
    long long mid = low + (high - low) / 2;

    if (v[low] > v[mid])
        swap(v[low], v[mid]);
    if (v[low] > v[high])
        swap(v[low], v[high]);
    if (v[mid] > v[high])
        swap(v[mid], v[high]);

    swap(v[mid], v[high]);
    return v[high];
}

template <typename T>
long long partition_m3(vector<T> &v, long long low, long long high)
{
    T pivot = medianOfThree(v, low, high);
    long long i = low - 1;

    for (long long j = low; j < high; ++j)
        if (v[j] < pivot)
        {
            i++;
            swap(v[i], v[j]);
        }

    swap(v[i + 1], v[high]);
    return i + 1;
}

template <typename T>
void quicksort_m3(vector<T> &v, long long low, long long high, int depth)
{
    if (depth > MAX_RECURSION_DEPTH)
        throw runtime_error("Nu se poate sorta.");
        
    if (low < high)
    {
        long long pivot = partition_m3(v, low, high);

        quicksort_m3(v, low, pivot - 1, depth + 1);
        quicksort_m3(v, pivot + 1, high, depth + 1);
    }
}

#endif