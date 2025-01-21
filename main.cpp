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

void bubbleSort(vector<Prato> &pratos, int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            // maior prioridade ou, caso empate, menor tempo
            if (pratos[j].prioridade < pratos[j + 1].prioridade ||
                (pratos[j].prioridade == pratos[j + 1].prioridade && pratos[j].tempo > pratos[j + 1].tempo))
            {
                Prato aux = pratos[j];
                pratos[j] = pratos[j + 1];
                pratos[j + 1] = aux;
            }
        }
    }
}

int quickSort_particao(vector<Prato> &pratos, int low, int high)
{
    Prato pivot = pratos[high];
    int i = low - 1;

    for (int j = low; j < high; ++j)
    {
        if (pratos[j].prioridade > pivot.prioridade ||
            (pratos[j].prioridade == pivot.prioridade && pratos[j].tempo < pivot.tempo))
        {
            i++;
            swap(pratos[i], pratos[j]);
        }
    }
    swap(pratos[i + 1], pratos[high]);
    return i + 1;
}

void quickSort_ordena(vector<Prato> &pratos, int low, int high)
{
    if (low < high)
    {
        int pi = quickSort_particao(pratos, low, high);

        quickSort_ordena(pratos, low, pi - 1);
        quickSort_ordena(pratos, pi + 1, high);
    }
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

void printData(vector<Prato> pratos, int n){
    for (int i = 0; i < n; ++i)
    {
        cout << "Prato " << i + 1 << ": "
             << "Nome: " << pratos[i].nome << ", "
             << "Prioridade: " << pratos[i].prioridade << ", "
             << "Tempo: " << pratos[i].tempo << " minutos" << endl;
    }
}

int main()
{
    int n = 10; // aumentar depois 300000
    vector<Prato> pratos(n);

    for (int i = 0; i < n; ++i)
    {
        pratos[i].prioridade = gerarNumeroAleatorio(1, 300000); // Prioridade - 0 < k < 300k
        pratos[i].tempo = gerarNumeroAleatorio(1, 1000);        // Tempo - 0 < t < 10k
        pratos[i].nome = gerarNomePrato(i);                     // Nome no máximo 50 caracteres, sem espaço
    }

    bubbleSort(pratos, n);

    cout << "Pratos ordenados com BubbleSort:" << endl;
    printData(pratos, n);

    quickSort_ordena(pratos, 0, n - 1);
    printData(pratos, n);

    return 0;
}