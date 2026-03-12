#include <fstream>
#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <random>

#include "generator.h"
#include "sortari/heap_sort.h"
#include "sortari/quick_sort_last_element.h"
#include "sortari/quick_sort_random.h"
#include "sortari/merge_sort.h"
#include "sortari/shell_sort.h"
#include "sortari/count_sort.h"
#include "sortari/radix_sort.h"
#include "sortari/quick_sort_m3.h"
using namespace std;
using namespace chrono;

ofstream gheap("output_heap_sort.csv");
ofstream gquickran("output_quick_sort_random.csv");
ofstream gquickle("output_quick_sort_le.csv");
ofstream gmerge("output_merge_sort.csv");
ofstream gshell("output_shell_sort.csv");
ofstream gcount("output_count_sort.csv");
ofstream gradixb10("output_radix_sort_10.csv");
ofstream gradixb216("output_radix_sort_2^16.csv");
ofstream gshellk3("output_shell_sort_knuth3.csv");
ofstream gshellk5("output_shell_sort_knuth5.csv");
ofstream gquickm3("output_quick_sort_m3.csv");

template <typename T>
bool validare(vector<T> &v)
{
    for (unsigned long long i = 1; i < v.size(); i++)
        if (v[i] < v[i - 1])
            return 0;
    return 1;
}

int main()
{
    gheap << "N, min, max, sortat_crescator,validare, sortat_descrescator,validare, aproape_s_c,validare, aproape_s_d,validare, random_uniform,validare, numere_aproape_identice,validare, gauss, validare,inv_gauss, validare\n";
    gquickran << "N, min, max, sortat_crescator,validare, sortat_descrescator,validare, aproape_s_c,validare, aproape_s_d,validare, random_uniform,validare, gauss, validare,inv_gauss, validare\n";
    gquickle << "N, min, max, sortat_crescator,validare, sortat_descrescator,validare, aproape_s_c,validare, aproape_s_d,validare, random_uniform,validare, gauss, validare,inv_gauss, validare\n";
    gmerge << "N, min, max, sortat_crescator,validare, sortat_descrescator,validare, aproape_s_c,validare, aproape_s_d,validare, random_uniform,validare, gauss, validare,inv_gauss, validare\n";
    gshell << "N, min, max, sortat_crescator,validare, sortat_descrescator,validare, aproape_s_c,validare, aproape_s_d,validare, random_uniform,validare, numere_aproape_identice,validare, gauss, validare,inv_gauss, validare\n";
    gcount << "N, min, max, sortat_crescator,validare, sortat_descrescator,validare, aproape_s_c,validare, aproape_s_d,validare, random_uniform,validare, numere_aproape_identice,validare, gauss, validare,inv_gauss, validare\n";
    gradixb10 << "N, min, max, sortat_crescator,validare, sortat_descrescator,validare, aproape_s_c,validare, aproape_s_d,validare, random_uniform,validare, numere_aproape_identice,validare, gauss, validare,inv_gauss, validare\n";
    gradixb216 << "N, min, max, sortat_crescator,validare, sortat_descrescator,validare, aproape_s_c,validare, aproape_s_d,validare, random_uniform,validare, numere_aproape_identice,validare, gauss, validare,inv_gauss, validare\n";
    gshellk3 << "N, min, max, sortat_crescator,validare, sortat_descrescator,validare, aproape_s_c,validare, aproape_s_d,validare, random_uniform,validare, numere_aproape_identice,validare, gauss, validare,inv_gauss, validare\n";
    gshellk5 << "N, min, max, sortat_crescator,validare, sortat_descrescator,validare, aproape_s_c,validare, aproape_s_d,validare, random_uniform,validare, numere_aproape_identice,validare, gauss, validare,inv_gauss, validare\n";
    gquickm3 << "N, min, max, sortat_crescator,validare, sortat_descrescator,validare, aproape_s_c,validare, aproape_s_d,validare, random_uniform,validare, numere_aproape_identice,validare, gauss, validare,inv_gauss, validare\n";

    int n;
    long long nr_numere;
    cin >> n;

    vector<long long> v;
    vector<long long> copie;

    srand(time(nullptr));

    for (int i = 0; i < n; i++)
    {
        long long nrmin, nrmax;

        if (i < n / 2)
        {
            mt19937 rng(random_device{}());
            uniform_int_distribution<long long> random(-100000, 100000);
            nrmin = random(rng);
            nrmax = random(rng);

            if (i < (double) n / 6)
            {
                cout << "thousand int\n";
                nr_numere = 1000;
                v.reserve(1000);
                copie.reserve(1000);
            }

            else if (i < (double) n / 3)
            {
                cout << "million int\n";
                nr_numere = 1000000;
                v.reserve(1000000);
                copie.reserve(1000000);
            }

            else
            {
                cout << "100 million int\n";
                nr_numere = 100000000;
                v.reserve(100000000);
                copie.reserve(100000000);
            }
        }

        else
        {
            mt19937 rng(random_device{}());
            uniform_int_distribution<long long> random(LONG_MIN, LONG_MAX);
            nrmin = random(rng);
            nrmax = random(rng);

            if (i < (double) 2 * n / 3)
            {
                cout << "thousand long long\n";
                nr_numere = 1000;
                v.reserve(1000);
                copie.reserve(1000);
            }

            else if (i < (double) 5 * n / 6)
            {
                cout << "million long long\n";
                nr_numere = 1000000;
                v.reserve(1000000);
                copie.reserve(1000000);
            }

            else
            {
                continue;
                cout << "100 million long long\n";
                nr_numere = 100000000;
                v.reserve(100000000);
                copie.reserve(100000000);
            }
        }

        if (nrmin > nrmax)
            swap(nrmin, nrmax);

        gheap << nr_numere << "," << nrmin << "," << nrmax << ",";
        gquickran << nr_numere << "," << nrmin << "," << nrmax << ",";
        gquickle << nr_numere << "," << nrmin << "," << nrmax << ",";
        gmerge << nr_numere << "," << nrmin << "," << nrmax << ",";
        gshell << nr_numere << "," << nrmin << "," << nrmax << ",";
        gcount << nr_numere << "," << nrmin << "," << nrmax << ",";
        gradixb10 << nr_numere << "," << nrmin << "," << nrmax << ",";
        gradixb216 << nr_numere << "," << nrmin << "," << nrmax << ",";
        gshellk3 << nr_numere << "," << nrmin << "," << nrmax << ",";
        gshellk5 << nr_numere << "," << nrmin << "," << nrmax << ",";
        gquickm3 << nr_numere << "," << nrmin << "," << nrmax << ",";

        for (short int j = 0; j < 8; j++)
        {
            auto start = high_resolution_clock::now();
            switch (j)
            {
            case 0:
                try
                {
                    Generator_Numere_Sortate_Crescator(nrmin, nrmax, nr_numere, v);
                }
                catch (...)
                {
                    gheap << "-1, 0,";
                    gquickran << "-1, 0,";
                    gquickle << "-1, 0, ";
                    gmerge << "-1, 0";
                    gshell << "-1, 0";
                    gshellk3 << "-1, 0";
                    gshellk5 << "-1, 0";
                    gradixb10 << "-1, 0, ";
                    gradixb216 << "-1, 0, ";
                    gcount << "-1, 0, ";
                    gquickm3 << "-1, 0, ";
                    continue;
                }
                break;
            case 1:
                try
                {
                    Generator_Numere_Sortate_Descrescator(nrmin, nrmax, nr_numere, v);
                }
                catch (...)
                {
                    gheap << "-1, 0,";
                    gquickran << "-1, 0,";
                    gquickle << "-1, 0, ";
                    gmerge << "-1, 0";
                    gshell << "-1, 0";
                    gshellk3 << "-1, 0";
                    gshellk5 << "-1, 0";
                    gradixb10 << "-1, 0, ";
                    gradixb216 << "-1, 0, ";
                    gcount << "-1, 0, ";
                    gquickm3 << "-1, 0, ";
                    continue;
                }
                break;
            case 2:
                try
                {
                    Generator_Numere_Aproape_Crescator(nrmin, nrmax, nr_numere, v);
                }
                catch (...)
                {
                    gheap << "-1, 0,";
                    gquickran << "-1, 0,";
                    gquickle << "-1, 0, ";
                    gmerge << "-1, 0";
                    gshell << "-1, 0";
                    gshellk3 << "-1, 0";
                    gshellk5 << "-1, 0";
                    gradixb10 << "-1, 0, ";
                    gradixb216 << "-1, 0, ";
                    gcount << "-1, 0, ";
                    gquickm3 << "-1, 0, ";
                    continue;
                }
                break;
            case 3:
                try
                {
                    Generator_Numere_Aproape_Descrescator(nrmin, nrmax, nr_numere, v);
                }
                catch (...)
                {
                    gheap << "-1, 0,";
                    gquickran << "-1, 0,";
                    gquickle << "-1, 0, ";
                    gmerge << "-1, 0";
                    gshell << "-1, 0";
                    gshellk3 << "-1, 0";
                    gshellk5 << "-1, 0";
                    gradixb10 << "-1, 0, ";
                    gradixb216 << "-1, 0, ";
                    gcount << "-1, 0, ";
                    gquickm3 << "-1, 0, ";
                    continue;
                }
                break;
            case 4:
                try
                {
                    Generator_Numere_Random_Uniform(nrmin, nrmax, nr_numere, v);
                }
                catch (...)
                {
                    gheap << "-1, 0,";
                    gquickran << "-1, 0,";
                    gquickle << "-1, 0, ";
                    gmerge << "-1, 0";
                    gshell << "-1, 0";
                    gshellk3 << "-1, 0";
                    gshellk5 << "-1, 0";
                    gradixb10 << "-1, 0, ";
                    gradixb216 << "-1, 0, ";
                    gcount << "-1, 0, ";
                    gquickm3 << "-1, 0, ";
                    continue;
                }
                break;
            case 5:
                try
                {
                    Generator_Numere_Identice(nrmin, nrmax, nr_numere, v);
                }
                catch (...)
                {
                    gheap << "-1, 0,";
                    gquickran << "-1, 0,";
                    gquickle << "-1, 0, ";
                    gmerge << "-1, 0";
                    gshell << "-1, 0";
                    gshellk3 << "-1, 0";
                    gshellk5 << "-1, 0";
                    gradixb10 << "-1, 0, ";
                    gradixb216 << "-1, 0, ";
                    gcount << "-1, 0, ";
                    gquickm3 << "-1, 0, ";
                    continue;
                }
                break;
            case 6:
                try
                {
                    Generator_Numere_Random_Gaussian(nrmin, nrmax, nr_numere, v);
                }
                catch (...)
                {
                    gheap << "-1, 0,";
                    gquickran << "-1, 0,";
                    gquickle << "-1, 0, ";
                    gmerge << "-1, 0";
                    gshell << "-1, 0";
                    gshellk3 << "-1, 0";
                    gshellk5 << "-1, 0";
                    gradixb10 << "-1, 0, ";
                    gradixb216 << "-1, 0, ";
                    gcount << "-1, 0, ";
                    gquickm3 << "-1, 0, ";
                    continue;
                }
                break;
            case 7:
                try
                {
                    Generator_Numere_Random_Inverted_Gaussian(nrmin, nrmax, nr_numere, v);
                }
                catch (...)
                {
                    gheap << "-1, 0,";
                    gquickran << "-1, 0,";
                    gquickle << "-1, 0, ";
                    gmerge << "-1, 0";
                    gshell << "-1, 0";
                    gshellk3 << "-1, 0";
                    gshellk5 << "-1, 0";
                    gradixb10 << "-1, 0, ";
                    gradixb216 << "-1, 0, ";
                    gcount << "-1, 0, ";
                    gquickm3 << "-1, 0, ";
                    continue;
                }
                break;
            default:
                break;
            }
            auto end = high_resolution_clock::now();
            duration<double> elapsed;
            elapsed = end - start;
            cout << elapsed.count() << endl;

            // heap sort
            try
            {
                copie = v;
                auto start = high_resolution_clock::now();
                heapSort(copie);
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gheap << elapsed.count() << "," << validare(copie) << ",";
                cout << "1\n";
            }
            catch (...)
            {
                gheap << "-1,0,";
            }

            // merge sort
            try
            {
                copie = v;
                vector<long long> temp(nr_numere);
                auto start = high_resolution_clock::now();
                mergeSort(copie, 0, nr_numere - 1, temp);
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gmerge << elapsed.count() << "," << validare(copie) << ",";
                cout << "2\n";
            }
            catch (...)
            {
                gmerge << "-1,0,";
            }

            // quick sort - random pivot
            try
            {
                copie = v;
                auto start = high_resolution_clock::now();
                quickSort_random(copie, 0, nr_numere - 1);
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gquickran << elapsed.count() << "," << validare(copie) << ",";
                cout << "3\n";
            }
            catch (...)
            {
                gquickran << "-1,0,";
            }

            // quick sort - last element
            try
            {
                copie = v;
                auto start = high_resolution_clock::now();
                quicksort_le(copie, 0, nr_numere - 1, 0);
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gquickle << elapsed.count() << "," << validare(copie) << ",";
                cout << "4\n";
            }
            catch (...)
            {
                gquickle << "-1,0,";
            }

            // quick sort - median-of-three
            try
            {
                copie = v;
                auto start = high_resolution_clock::now();
                quicksort_m3(copie, 0, nr_numere - 1, 0);
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gquickm3 << elapsed.count() << "," << validare(copie) << ",";
                cout << "1\n";
            }
            catch (...)
            {
                gquickm3 << "-1,0,";
            }

            // Count sort
            try
            {
                copie = v;
                auto start = high_resolution_clock::now();
                count_sort(copie);
                auto end = high_resolution_clock::now();
                cout << "5\n";
                duration<double> elapsed = end - start;
                gcount << elapsed.count() << "," << validare(copie) << ",";
            }
            catch (...)
            {
                gcount << "-1,0,";
            }

            // Radix Sort base 2^16
            try
            {
                copie = v;
                auto start = high_resolution_clock::now();
                radixsort(copie, nr_numere, 65536);
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gradixb216 << elapsed.count() << "," << validare(copie) << ",";
                cout << "6\n";
            }
            catch (...)
            {
                gradixb216 << "-1,0,";
            }

            // Radix Sort base 10
            try
            {
                copie = v;
                auto start = high_resolution_clock::now();
                radixsort(copie, nr_numere, 10);
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gradixb10 << elapsed.count() << "," << validare(copie) << ",";
                cout << "7\n";
            }
            catch (...)
            {
                gradixb10 << "-1,0,";
            }

            // Shell sort classic
            try
            {
                copie = v;
                auto start = high_resolution_clock::now();
                shell_sort(copie, nr_numere);
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gshell << elapsed.count() << "," << validare(copie) << ",";
                cout << "8\n";
            }
            catch (...)
            {
                gshell << "-1,0,";
            }

            // Shell sort knuth generalized (k = 3)
            try
            {
                copie = v;
                auto start = high_resolution_clock::now();
                shell_sort_knuth_generalized(copie, 3, nr_numere);
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gshellk3 << elapsed.count() << "," << validare(copie) << ",";
                cout << "9\n";
            }
            catch (...)
            {
                gshellk3 << "-1,0,";
            }

            // Shell sort knuth generalized (k = 5)
            try
            {
                copie = v;
                auto start = high_resolution_clock::now();
                shell_sort_knuth_generalized(copie, 5, nr_numere);
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gshellk5 << elapsed.count() << "," << validare(copie) << ",";
                cout << "10\n";
            }
            catch (...)
            {
                gshellk5 << "-1,0,";
            }
        }

        gheap << endl;
        gquickran << endl;
        gquickle << endl;
        gmerge << endl;
        gshell << endl;
        gcount << endl;
        gradixb10 << endl;
        gradixb216 << endl;
        gshellk3 << endl;
        gshellk5 << endl;
        gquickm3 << endl;
    }
    return 0;
}
