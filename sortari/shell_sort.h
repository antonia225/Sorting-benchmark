#ifndef shellsort
#define shellsort

#include <cmath>
#include <vector>
using namespace std;

template <typename T> 
// varianta clasica
void shell_sort(vector<T>& v, long long n) {
    for (long long space = n / 2; space > 0; space /= 2) {
        for (long long i = space; i < n; i++) {
            T aux = v[i];
            long long j;
            for (j = i; j >=space && v[j - space] > aux; j -= space)
                v[j] = v[j - space];
            v[j] = aux;
        }
    }
}

template <typename T> 
// knuth gaps - generalization
void shell_sort_knuth_generalized(vector<T> &v, long long k, long long n) {
    long long h = 1;
    //daca k > n => insertion sort
    while (h < n / k)
        h = h * k + 1;
    for (long long space = h; space > 0; space /= k) {
        for (long long i = space; i < n; i++) {
            T aux = v[i];
            long long j;
            for (j = i; j >=space && v[j - space] > aux; j -= space)
                v[j] = v[j - space];
            v[j] = aux;
        }
    }
}

#endif