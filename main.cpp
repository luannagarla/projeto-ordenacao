#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <string> 
#include <sstream> 

using namespace std;

struct Prato
{
    int prioridade;
    int tempo;
    string nome;
};

void bubbleSort(vector<Prato> &pratos)
{
}

void quickSort(vector<Prato> &pratos, int low, int high)
{
}

string gerarNomePrato(int indice)
{
    static vector<string> nomes = {
        "fish-and-chips", "full-english-breakfast", "bubble-and-squeak", "scones", "steak-and-ale-pie",
        "shepherds-pie", "ploughman", "toad-in-the-hole", "black-pudding", "wellington-beef", "scotch-egg",
        "cornish-pasty", "yorkshire-pudding", "sponge-cake", "chicken-tikka-masala", "bangers-and-mash"};

    return nomes[indice % nomes.size()];
    // return nome + "-" + to_string(indice); //não tenho a biblioteca que faça isso, preciso achar
}

int gerarNumeroAleatorio(int min, int max)
{
    static mt19937 rng(time(0)); // random
    uniform_int_distribution<int> dist(min, max);
    return dist(rng);
}

int main()
{
    int n = 10; // aumentar depois 0 < k < 3 ⋅ 105
    vector<Prato> pratos(n);

    for (int i = 0; i < n; ++i)
    {
        pratos[i].prioridade = gerarNumeroAleatorio(1, 300000); // Prioridade - 0 < k < 300k
        pratos[i].tempo = gerarNumeroAleatorio(1, 1000);        // Tempo - 0 < t < 10k
        pratos[i].nome = gerarNomePrato(i);                     // Nome
    }

    cout << "Pratos gerados:" << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << "Prato " << i + 1 << ": "
             << "Nome: " << pratos[i].nome << ", "
             << "Prioridade: " << pratos[i].prioridade << ", "
             << "Tempo: " << pratos[i].tempo << " minutos" << endl;
    }

    /*Ordene em ordem decrescente de acordo com a prioridade, se a prioridade for a mesma,
o de menor tempo deverá ser priorizado. Nenhum prato tem a mesma prioridade e tempo de
preparo.

A prioridade é um inteiro 0 < p < 3 ⋅ 105, o tempo de preparo (em minutos) é um inteiro 0 <
t < 103, o nome é uma string de no máximo 50 caracteres, sem espaço.*/

    return 0;
}

// Compare os métodos de ordenação e faça uma breve explicação sobre a escolha de pivôs no Quicksort.