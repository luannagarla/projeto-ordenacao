#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <ctime>

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
    
}

int gerarNumeroAleatorio(int min, int max)
{
    
}

int main()
{
    int n = 10; // aumentar depois 0 < k < 3 ⋅ 105
    vector<Prato> pratos(n);

    for (int i = 0; i < n; ++i)
    {
       //criar pratos
    }

    /*Ordene em ordem decrescente de acordo com a prioridade, se a prioridade for a mesma,
o de menor tempo deverá ser priorizado. Nenhum prato tem a mesma prioridade e tempo de
preparo.

A prioridade é um inteiro 0 < p < 3 ⋅ 105, o tempo de preparo (em minutos) é um inteiro 0 <
t < 103, o nome é uma string de no máximo 50 caracteres, sem espaço.*/

    return 0;
}

//Compare os métodos de ordenação e faça uma breve explicação sobre a escolha de pivôs no Quicksort.