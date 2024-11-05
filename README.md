# Parallel Sum Benchmark

Um projeto em C++ para comparar o desempenho de soma de elementos em um vetor de tamanho grande (100 milhões de elementos) utilizando abordagens de processamento sequencial e paralelo. Este projeto explora o uso das bibliotecas **OpenMP** e **Intel oneTBB** para implementação paralela e inclui medições de tempo de execução, cálculo de média e desvio padrão dos tempos de execução e criação de gráficos para análise.

## Objetivo

O objetivo é desenvolver um programa que permita:

1. Realizar a soma dos elementos de um vetor de maneira sequencial e paralela.
2. Comparar o desempenho das abordagens usando as bibliotecas **OpenMP** e **Intel oneTBB**.
3. Medir o tempo de execução para cada abordagem em 30 execuções e calcular a média e o desvio padrão dos tempos.
4. Criar gráficos para visualização dos tempos de execução e análise dos resultados.

## Pré-requisitos

- **CMake** para configuração e compilação.
- **Compilador C++** com suporte a OpenMP.
- **Intel oneTBB** instalado para paralelização com TBB.

### Instalação do Intel oneTBB

- **Linux**: Execute `sudo apt-get install libtbb-dev`.
- **Windows/MacOS**: Faça o download do [Intel oneTBB](https://www.intel.com/content/www/us/en/developer/tools/oneapi/onetbb.html) e adicione as bibliotecas ao caminho do projeto.

## Estrutura do Projeto

- `main.cpp`: Código principal para a execução das abordagens sequencial e paralela.
- `CMakeLists.txt`: Arquivo de configuração para compilar o projeto com CMake.

## Como Executar

1. Clone o repositório:

   ```bash
   git clone https://github.com/seu-usuario/Parallel-Sum-Benchmark.git
   cd Parallel-Sum-Benchmark

2. Compile o projeto:

    ```bash
    mkdir build
    cd build
    cmake ..
    make
    
3. Execute o programa:
  
    ```
    ./concorrencia_proj

## Metodologia
- Implementação Sequencial: Soma realizada em um loop for simples.
- Implementação com OpenMP: Paralelização com OpenMP, utilizando a diretiva `#pragma omp parallel for`.
- Implementação com TBB: Paralelização com a biblioteca Intel oneTBB para distribuir o trabalho entre múltiplos threads.





