#define _TIMESPEC_DEFINED
#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <string>
#include <sstream>
#include <time.h>

#include <algorithm> 
#include <random>   

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
        bool trocou = false;

        for (int j = 0; j < n - i - 1; ++j)
        {
            if (pratos[j].prioridade < pratos[j + 1].prioridade ||
                (pratos[j].prioridade == pratos[j + 1].prioridade && pratos[j].tempo > pratos[j + 1].tempo))
            {

                Prato aux = pratos[j];
                pratos[j] = pratos[j + 1];
                pratos[j + 1] = aux;

                trocou = true;
            }
        }
        if (!trocou)
        {
            break;
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

    string nome = nomes[indice % nomes.size()];

    ostringstream oss;
    oss << indice;

    return nome + "_v" + oss.str();
}

int gerarNumero(int min, int max)
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

vector<Prato> gerarPratos(int n)
{
    vector<Prato> pratos(n);

    for (int i = 0; i < n; ++i)
    {
        pratos[i].prioridade = i;               // Prioridade - 0 < k < 300k
        pratos[i].tempo = gerarNumero(1, 1000); // Tempo - 0 < t < 1k
        pratos[i].nome = gerarNomePrato(i);     // Nome no máximo 50 caracteres, sem espaço
    }

    /*Atribui "i" para prioridade para atender ao requisito "Nenhum prato tem a mesma prioridade e tempo de preparo.", porém,
    dessa maneira, a lista já fica numa certa ordem*/

    // Então fui atrás de um algoritmo para embaralhar a lista, para conseguir testar melhor a ordenação
    random_device rd;
    mt19937 g(rd());
    shuffle(pratos.begin(), pratos.end(), g);

    // printData(pratos, n);
    return pratos;
}

int main()
{
    int n = 300000;

    vector<Prato> pratos = gerarPratos(n);

    vector<Prato> pratosParaBubble = pratos;
    vector<Prato> pratosParaQuick = pratos;

    clock_t startBubble = clock();
    bubbleSort(pratosParaBubble, n);
    clock_t endBubble = clock();
    double bubbleTime = double(endBubble - startBubble) / CLOCKS_PER_SEC;

    // não recomendo que este trecho seja descomentado se o "n" for muito grande
    // cout << "\nPratos ordenados com Bubble Sort:" << endl;
    // printData(pratosParaBubble, n);

    clock_t startQuick = clock();
    quickSort_ordena(pratosParaQuick, 0, n - 1);
    clock_t endQuick = clock();
    double quickTime = double(endQuick - startQuick) / CLOCKS_PER_SEC;

    // não recomendo que este trecho seja descomentado se o "n" for muito grande
    // cout << "\nPratos ordenados com Quick Sort:" << endl;
    // printData(pratosParaQuick, n);

    cout << "Tempo de execução do Bubble Sort: " << bubbleTime << " segundos" << endl;
    cout << "Tempo de execução do Quick Sort: " << quickTime << " segundos" << endl;

    return 0;
}