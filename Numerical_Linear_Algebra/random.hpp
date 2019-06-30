#include <iostream>
#include <random>
#include <chrono>
#include <functional>

using std::chrono::high_resolution_clock;

static double rng(size_t k = 1)
{
    std::mt19937::result_type seed = 
        high_resolution_clock::now().time_since_epoch().count();

    auto real_rand = std::bind(std::uniform_real_distribution<double>(0,k),
            std::mt19937(seed));

    return real_rand();
}