# Atividade de ordenação - bubbleSort e quickSort

**:dart: Objetivos** 

- [X]   Recepção de 0 < k < 3 ⋅ 10^5 pratos (300k);
- [X]   O tempo de preparo (em minutos) é um inteiro 0 < t < 10^3 (1k);
- [X]   Nenhum prato tem a mesma prioridade e tempo de preparo;
- [X]   Implementação do método de ordenação BubbleSort;
- [X]   Implementação do método de ordenação QuickSort;
- [X]   Comparação entre os métodos de ordenação e breve explicação sobre a escolha de pivôs no Quicksort.

---
**:question: Comparações dos códigos** 
![alt text](image.png)

Os meus testes de comparação foram baseados no tempo de execução dos códigos com n = 100k, utilizando a biblioteca ctime para realizar a contagem. A partir dos resultados, é possível observar uma diferença significativa entre o desempenho das duas operações.

Isso ocorre porque o Bubble Sort é um algoritmo ineficiente para grandes volumes de dados. Com complexidade quadrática, ele se torna inviável em entradas grandes, já que o número de iterações necessárias e as trocas de elementos aumentam exponencialmente, resultando em um tempo de execução extremamente longo.

Já o Quick Sort, que utiliza a estratégia de dividir o problema em partes menores, é mais eficiente tanto em termos de tempo quanto de memória. Sua implementação recursiva e a estratégia de partição permitem que o algoritmo lide de maneira mais eficaz com conjuntos de dados grandes, superando o desempenho do Bubble Sort em termos de velocidade. No entanto, o Quick Sort se sai melhor em listas grandes, enquanto em listas pequenas ele pode não ter uma vantagem tão expressiva.

---
**:question: Escolha do pivô** 
O pivô foi escolhido como o último elemento da lista devido aos seguintes motivos:

* Eficiência em casos aleatórios: Como os dados são distribuídos de forma aleatória, selecionar o último elemento como pivô tende a produzir divisões razoavelmente equilibradas;
* Simplicidade na implementação: A escolha do último elemento é simples e direta, pois ele pode ser acessado diretamente pelo índice high na main;
* Baixo custo computacional: Essa abordagem não exige cálculos adicionais, como determinar o pivô mediano, o que torna a implementação mais eficiente e menos complexa.