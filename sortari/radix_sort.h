#ifndef RADIXSORT_H
#define RADIXSORT_H

#include <vector>
using namespace std;

template <typename T>
void getMaxMin(vector<T> &v, long long nr_numere, T &mn, T &mx)
{
    mx = v[0];
    mn = v[0];

    for (int i = 1; i < nr_numere; i++)
    {
        T val = v[i];
        if (val < mn)
            mn = val;
        if (val > mx)
            mx = val;
    }
}

template <typename T>
void count(vector<T> &v, long long nr_numere, long long exp, long long base)
{

    vector<T> output(nr_numere);
    long long i;
    vector<int> count(base, 0);

    for (i = 0; i < nr_numere; i++)
    {
        long long digit = (v[i] / exp) % base;
        count[digit]++;
    }

    for (i = 1; i < base; i++)
        count[i] += count[i - 1];

    for (i = nr_numere - 1; i >= 0; i--)
    {
        long long digit = (v[i] / exp) % base;
        output[count[digit] - 1] = v[i];
        count[digit]--;
    }

    for (i = 0; i < nr_numere; i++)
        v[i] = output[i];
}

template <typename T>
void radixsort(vector<T> &v, long long nr_numere, long long base = 10)
{
    T mn, mx;
    getMaxMin(v, nr_numere, mn, mx);

    long long offset = 0;
    if (mn < 0)
    {
        offset = -mn;
        for (long long i = 0; i < nr_numere; i++)
            v[i] += offset;
        mx += offset;
    }

    for (long long exp = 1; mx / exp > 0; exp *= base)
    {
        count(v, nr_numere, exp, base);
        if (exp > mx / base) break;
    }

    if (offset)
        for (long long i = 0; i < nr_numere; i++)
            v[i] -= offset;
}

#endif