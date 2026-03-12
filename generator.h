#ifndef generator
#define generator
#include <vector>
#include <random>
#include <cmath>
#include <algorithm>
#include <type_traits>

template <typename T>
void Generator_Numere_Sortate_Crescator(T minim, T maxim, unsigned long long nr_numere, std::vector<T>& numbers)
{
    numbers.clear();
    if (nr_numere == 0)
        return;

    if (maxim < minim)
        std::swap(maxim, minim);

    if (minim == maxim)
    {
        for (unsigned long long i = 0; i < nr_numere; i++) 
            numbers.push_back(minim);
        return;
    }
    else
    {   
        std::mt19937 rng(std::random_device{}());
        std::uniform_real_distribution<double> random(1.5, 2.5);
        double scalar = random(rng);
        if constexpr (std::is_floating_point<T>::value)
        {
            std::uniform_real_distribution<T> dist(0, static_cast<T>((static_cast<double>(maxim) - static_cast<double>(minim)) / nr_numere * scalar));
            T current = minim;
            for (long long i = 0; i < nr_numere; i++) 
            {
                T next = current + dist(rng);
                if (next > maxim) next = maxim;
                numbers.push_back(next);
                current = next;
            }
        }
        else
        {
            double range = (static_cast<double>(maxim) - static_cast<double>(minim)) / nr_numere * scalar;
            T step = static_cast<T>(range) > 1 ? static_cast<T>(range) : 1;
            std::uniform_int_distribution<T> dist(0, step);
            T current = minim;
            for (long long i = 0; i < nr_numere; i++) 
            {
                T next = current + dist(rng);
                if (next > maxim) next = maxim;
                numbers.push_back(next);
                current = next;
            }
        }
    }
}

template <typename T>
void Generator_Numere_Sortate_Descrescator(T minim, T maxim, unsigned long long nr_numere, std::vector<T>& numbers)
{
    numbers.clear();
    if (nr_numere == 0)
        return;

    if (maxim < minim)
        std::swap(maxim, minim);

    if (minim == maxim)
    {
        for (unsigned long long i = 0; i < nr_numere; i++) 
            numbers.push_back(minim);
        return;
    }
    else
    {   
        std::mt19937 rng(std::random_device{}());
        std::uniform_real_distribution<double> random(1.5, 2.5);
        double scalar = random(rng);
        if constexpr (std::is_floating_point<T>::value)
        {
            std::uniform_real_distribution<T> dist(0, static_cast<T>((static_cast<double>(maxim) - static_cast<double>(minim)) / nr_numere * scalar));
            T current = maxim;
            for (long long i = 0; i < nr_numere; i++) 
            {
                T next = current - dist(rng);
                if (next < minim) next = minim;
                numbers.push_back(next);
                current = next;
            }
        }
        else
        {
            double range = (static_cast<double>(maxim) - static_cast<double>(minim)) / nr_numere * scalar;
            T step = static_cast<T>(range) > 1 ? static_cast<T>(range) : 1;
            std::uniform_int_distribution<T> dist(0, step);
            T current = maxim;
            for (long long i = 0; i < nr_numere; i++) 
            {
                T next = current - dist(rng);
                if (next < minim) next = minim;
                numbers.push_back(next);
                current = next;
            }
        }
    }
}

template <typename T>
void Generator_Numere_Aproape_Crescator(T minim, T maxim, unsigned long long nr_numere, std::vector<T>& numbers)
{
    numbers.clear();
    if (nr_numere == 0)
        return;

    if (maxim < minim)
        std::swap(maxim, minim);

    Generator_Numere_Sortate_Crescator(minim, maxim, nr_numere, numbers);

    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<unsigned long long> random(0, nr_numere / 4);
    unsigned long long swaps = random(rng);
    std::uniform_int_distribution<unsigned long long> dis(0, nr_numere - 1);
    for (unsigned long long i = 0; i < swaps; i++)
    {
        unsigned long long id1 = dis(rng);  // fixed: was T
        unsigned long long id2 = dis(rng);  // fixed: was T
        std::swap(numbers[id1], numbers[id2]);
    }
}

template <typename T>
void Generator_Numere_Aproape_Descrescator(T minim, T maxim, unsigned long long nr_numere, std::vector<T>& numbers)
{
    numbers.clear();
    if (nr_numere == 0)
        return;

    if (maxim < minim)
        std::swap(maxim, minim);

    Generator_Numere_Sortate_Descrescator(minim, maxim, nr_numere, numbers);

    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<unsigned long long> random(0, nr_numere / 4);
    unsigned long long swaps = random(rng);
    std::uniform_int_distribution<unsigned long long> dis(0, nr_numere - 1);
    for (unsigned long long i = 0; i < swaps; i++)
    {
        unsigned long long id1 = dis(rng);  // fixed: was T
        unsigned long long id2 = dis(rng);  // fixed: was T
        std::swap(numbers[id1], numbers[id2]);
    }
}

template <typename T>
void Generator_Numere_Random_Uniform(T minim, T maxim, unsigned long long nr_numere, std::vector<T>& numbers)
{
    numbers.clear();
    if (nr_numere == 0)
        return;

    if (maxim < minim)
        std::swap(maxim, minim);

    if (minim == maxim)
    {
        for (unsigned long long i = 0; i < nr_numere; i++) 
            numbers.push_back(minim);
        return;
    }
    else
    {
        std::mt19937 rng(std::random_device{}());
        if constexpr (std::is_floating_point<T>::value)
        {
            std::uniform_real_distribution<T> dist(minim, maxim);
            for (unsigned long long i = 0; i < nr_numere; i++)
                numbers.push_back(dist(rng));
        }
        else
        {
            std::uniform_int_distribution<T> dist(minim, maxim);
            for (unsigned long long i = 0; i < nr_numere; i++)
                numbers.push_back(dist(rng));
        }
    }   
}

template <typename T>
void Generator_Numere_Random_Gaussian(T minim, T maxim, unsigned long long nr_numere, std::vector<T>& numbers)
{
    numbers.clear();
    if (nr_numere == 0)
        return;

    if (maxim < minim)
        std::swap(maxim, minim);

    if (minim == maxim)
    {
        for (unsigned long long i = 0; i < nr_numere; i++) 
            numbers.push_back(minim);
        return;
    }
    else
    {
        double diferenta = static_cast<double>(maxim) - static_cast<double>(minim);  // fixed: was maxim - minim
        std::mt19937 rng(std::random_device{}());
        std::uniform_real_distribution<double> dev(0, diferenta / 6);
        std::uniform_real_distribution<double> mean(diferenta * 0.2, diferenta * 0.8);
        double mean1 = mean(rng) + static_cast<double>(minim);
        double dev1 = dev(rng);
        std::normal_distribution<double> gaus(mean1, dev1);

        if constexpr (std::is_floating_point<T>::value)
        {
            for (unsigned long long i = 0; i < nr_numere; i++)
            {
                T value = static_cast<T>(gaus(rng));
                if (value < minim) value = minim;
                if (value > maxim) value = maxim;
                numbers.push_back(value);
            }
        }
        else
        {
            for (unsigned long long i = 0; i < nr_numere; i++)
            {
                T value = static_cast<T>(round(gaus(rng)));
                if (value < minim) value = minim;
                if (value > maxim) value = maxim;
                numbers.push_back(value);
            }
        }
    }
}

template <typename T>
void Generator_Numere_Identice(T minim, T maxim, unsigned long long nr_numere, std::vector<T>& numbers)
{
    numbers.clear();
    if (nr_numere == 0)
        return;

    if (maxim < minim)
        std::swap(maxim, minim);

    if (minim == maxim)
    {
        for (unsigned long long i = 0; i < nr_numere; i++) 
            numbers.push_back(minim);
        return;
    }
    else
    {
        std::mt19937 rng(std::random_device{}());
        if constexpr (std::is_floating_point<T>::value)
        {
            std::uniform_real_distribution<T> interval(minim, maxim);
            T val = interval(rng);
            T lo = std::max(minim, static_cast<T>(val - sqrt(static_cast<double>(nr_numere))));  // fixed: clamped bounds
            T hi = std::min(maxim, static_cast<T>(val + sqrt(static_cast<double>(nr_numere))));  // fixed: clamped bounds
            std::uniform_real_distribution<T> numere(lo, hi);
            for (unsigned long long i = 0; i < nr_numere; i++)
                numbers.push_back(numere(rng));
        }
        else
        {
            std::uniform_int_distribution<T> interval(minim, maxim);
            T val = interval(rng);
            T lo = std::max(minim, static_cast<T>(val - static_cast<T>(sqrt(static_cast<double>(nr_numere)))));  // fixed: clamped bounds
            T hi = std::min(maxim, static_cast<T>(val + static_cast<T>(sqrt(static_cast<double>(nr_numere)))));  // fixed: clamped bounds
            std::uniform_int_distribution<T> numere(lo, hi);
            for (unsigned long long i = 0; i < nr_numere; i++)
                numbers.push_back(numere(rng));
        }
    }
}

template <typename T>
void Generator_Numere_Random_Inverted_Gaussian(T minim, T maxim, unsigned long long nr_numere, std::vector<T>& numbers)
{
    numbers.clear();
    if (nr_numere == 0)
        return;

    if (maxim < minim)
        std::swap(maxim, minim);

    if (minim == maxim)
    {
        for (unsigned long long i = 0; i < nr_numere; i++)
            numbers.push_back(minim);
    }
    else
    {
        std::mt19937 rng(std::random_device{}());
        double diferenta = static_cast<double>(maxim) - static_cast<double>(minim);  // fixed: was maxim - minim
        std::uniform_real_distribution<double> dev(0, diferenta / 6);
        double dev1 = dev(rng);
        std::normal_distribution<double> gaus(0, dev1);
        std::bernoulli_distribution weight(0.5);

        if constexpr (std::is_floating_point<T>::value)
        {
            for (unsigned long long i = 0; i < nr_numere; i++)
            {
                T value;
                if (weight(rng))
                    value = static_cast<T>(std::abs(gaus(rng)) + static_cast<double>(minim));
                else
                    value = static_cast<T>(static_cast<double>(maxim) - std::abs(gaus(rng)));
                numbers.push_back(value);
            }
        }
        else
        {
            for (unsigned long long i = 0; i < nr_numere; i++)
            {
                T value;
                if (weight(rng))
                    value = static_cast<T>(std::round(std::abs(gaus(rng))) + static_cast<double>(minim));
                else
                    value = static_cast<T>(static_cast<double>(maxim) - std::round(std::abs(gaus(rng))));
                numbers.push_back(value);
            }
        }
    }
}

#endif
