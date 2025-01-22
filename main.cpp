#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <string>

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
            Prato aux = pratos[i];
            pratos[i] = pratos[j];
            pratos[j] = aux;
        }
    }

    Prato aux = pratos[i + 1];
    pratos[i + 1] = pratos[high];
    pratos[high] = aux;

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
}

int gerarNumeroAleatorio(int min, int max)
{
    static mt19937 rng(time(0));
    uniform_int_distribution<int> dist(min, max);
    return dist(rng);
}

void printData(const vector<Prato> &pratos, int n)
{
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
    int n = 10; // mudar pra 300000

    vector<Prato> pratos(n);

    // Gerar dados aleatórios
    for (int i = 0; i < n; ++i)
    {
        pratos[i].prioridade = gerarNumeroAleatorio(1, 300000); // Prioridade - 0 < k < 300k
        pratos[i].tempo = gerarNumeroAleatorio(1, 1000);        // Tempo - 0 < t < 10k
        pratos[i].nome = gerarNomePrato(i);                     // Nome no máximo 50 caracteres, sem espaço
    }

    vector<Prato> pratosParaBubble = pratos;
    vector<Prato> pratosParaQuick = pratos;

    // Bubble Sort
    clock_t start = clock();
    bubbleSort(pratosParaBubble, n);
    clock_t end = clock();
    double bubbleTime = double(end - start) / CLOCKS_PER_SEC;
    cout << "Tempo de execução do Bubble Sort: " << bubbleTime << " segundos" << endl;

    cout << "\nPratos ordenados com Bubble Sort:" << endl;
    printData(pratosParaBubble, n);

    // Quick Sort
    start = clock();
    quickSort_ordena(pratosParaQuick, 0, n - 1);
    end = clock();
    double quickTime = double(end - start) / CLOCKS_PER_SEC;
    cout << "Tempo de execução do Quick Sort: " << quickTime << " segundos" << endl;

    cout << "\nPratos ordenados com Quick Sort:" << endl;
    printData(pratosParaQuick, n);

    return 0;
}