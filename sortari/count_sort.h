#ifndef countsort
#define countsort

#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
void count_sort(vector<T> &v)
{
    if (v.empty())
        return;

    T minim = *min_element(v.begin(), v.end());
    T maxim = *max_element(v.begin(), v.end());
    vector<unsigned long long> fr(maxim - minim + 1, 0);

    for (unsigned long long i = 0; i < v.size(); i++)
        fr[v[i] - minim]++;
    v.clear();

    for (unsigned long long i = 0; i < fr.size(); i++)
        while (fr[i] > 0)
        {
            v.push_back(i + minim);
            fr[i]--;
        }
}

#endif