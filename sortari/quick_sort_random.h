#ifndef quicksort_random
#define quicksort_random

#include <vector>
#include <random>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

template <typename T>
long long partition(vector<T> &v, long long low, long long high)
{
    long long pivot = v[high];
    long long i = (low - 1);

    for (long long j = low; j <= high - 1; j++)
    {
        if (v[j] <= pivot)
        {
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i + 1], v[high]);
    return (i + 1);
}

template <typename T>
long long partition_r(vector<T> &v, long long low, long long high)
{
    long long random = low + rand() % (high - low);

    swap(v[random], v[high]);

    return partition(v, low, high);
}

template <typename T>
void quickSort_random(vector<T> &v, long long low, long long high, int depth = 0)
{
    if (depth > MAX_RECURSION_DEPTH)
        throw runtime_error("Nu se poate sorta.");

    if (low < high)
    {

        long long pivot = partition_r(v, low, high);

        quickSort_random(v, low, pivot - 1, depth + 1);
        quickSort_random(v, pivot + 1, high, depth + 1);
    }
}

#endif