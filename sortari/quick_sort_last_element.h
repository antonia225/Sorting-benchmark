#ifndef quickSort_le
#define quickSort_le

#include <vector>
#include <algorithm>
#include <stdexcept>
using namespace std;

const int MAX_RECURSION_DEPTH = 10000;

template <typename T>
long long partition_le(vector<T> &v, long long low, long long high)
{
    T value = v[high];
    long long i = low;

    for (long long j = low; j < high; j++)
    {
        if (v[j] < value)
        {
            swap(v[i], v[j]);
            i++;
        }
    }

    swap(v[i], v[high]);
    return i;
}
template <typename T>
void quicksort_le(vector<T> &v, long long low, long long high, int depth)
{
    if (depth > MAX_RECURSION_DEPTH)
        throw runtime_error("Nu se poate sorta.");

    if (low < high)
    {
        long long pivot = partition_le(v, low, high);

        quicksort_le(v, low, pivot - 1, depth + 1);
        quicksort_le(v, pivot + 1, high, depth + 1);
    }
}

#endif