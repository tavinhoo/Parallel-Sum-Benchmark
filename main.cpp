#include <iostream>
#include <numeric>
#include <vector>
#include <chrono>
#include <omp.h>
#include "oneapi/tbb.h"

int main() {

    int n = 100000000;
    std::vector<int> vect(n);

    // Preenche o vetor com valores de 1 a 100000000 sem a necessidade de um for;
    std::iota(vect.begin(), vect.end(), 1);

    // std::cout << vect.at(0) << std::endl; -> valor: 1
    // std::cout << vect.at(vect.size() - 1) << std::endl; -> valor: 100000000

    // Início
    auto startSeq = std::chrono::high_resolution_clock::now();

    // Soma sequencial
    int sequencialSum = 0;

    for(int i = 0; i<n ; i++) {
        sequencialSum += vect[i];
    }

    // Fim
    auto endSeq = std::chrono::high_resolution_clock::now();

    // Cálculo de tempo
    std::chrono::duration<double> timeSeq = endSeq - startSeq;

    std::cout << "Tempo de execução da soma sequencial: " << timeSeq.count() << " segundos." << std::endl;

    // Soma paralelizada
    int parallelSum = 0;

    auto startPrll = std::chrono::high_resolution_clock::now();

    #pragma omp parallel for reduction(+:parallelSum)
    for(int i = 0; i<n ; i++) {
        parallelSum += vect[i];
    }

    auto endPrll = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> timePrll = endPrll - startPrll;

    std::cout << "Tempo de execução da soma sequencial: " << timePrll.count() << " segundos." << std::endl;

    auto startTbb = std::chrono::high_resolution_clock::now();

    auto f = [&](const tbb::blocked_range<int>& r, int sum) {
        for (int i = r.begin(); i < r.end(); ++i) {
            sum += vect[i];
        }
        return sum;
    };
    std::plus<int> g;

    int valor_inicial = 0;
    int soma_total  = 0;
    soma_total = tbb::parallel_reduce(tbb::detail::d2::range, valor_inicial, f, g);

    std::cout << soma_total << std::endl;

    auto endTbb = std::chrono::high_resolution_clock::now();

    return 0;
}
