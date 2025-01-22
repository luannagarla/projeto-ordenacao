# Atividade de ordenação - bubbleSort e quickSort

Joãozinho está planejando abrir um restaurante especializado em comida britânica e pediu sua ajuda para priorizar os pratos do cardápio. Como seu prato favorito tem a palavra “Bubble” no nome, ele acredita que o algoritmo Bubble Sort seria o mais adequado para essa tarefa. No entanto, como você conhece algoritmos mais eficientes, pretende implementar outro para demonstrar uma solução mais otimizada.

---

**:dart: Objetivos** 

- [X]   Recepção de 0 < k < 3 ⋅ 10^5 pratos (300k);
- [X]   Implementação do método de ordenação Quicksort;
- [X]   Implementação do método de ordenação Quicksort;
- [X]   Nenhum prato tem a mesma prioridade e tempo de preparo;
- [X]  A prioridade é um inteiro 0 < p < 3 ⋅ 10^5, o tempo de preparo (em minutos) é um inteiro 0 < t < 10^3 (1k);
- [X]   Compare os métodos de ordenação e faça uma breve explicação sobre a escolha de pivôs no Quicksort.

---
**:question: Comparações dos códigos** 


---
**:question: Escolha do pivô** 
O pivô foi escolhido como o último elemento da lista devido aos seguintes motivos:

* Eficiência em casos aleatórios: Como os dados são distribuídos de forma aleatória, selecionar o último elemento como pivô tende a produzir divisões razoavelmente equilibradas;
* Simplicidade na implementação: A escolha do último elemento é simples e direta, pois ele pode ser acessado diretamente pelo índice high na main;
* Baixo custo computacional: Essa abordagem não exige cálculos adicionais, como determinar o pivô mediano, o que torna a implementação mais eficiente e menos complexa.