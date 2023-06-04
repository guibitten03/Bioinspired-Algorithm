# Bioinspired-Algorithm

Um algoritmo bioinspirado para resolver o Problema do Caixeiro Viajante

## Como usar

1. Compile o código com o comando:
    ```
    make
    ```

2. Execute o arquivo gerado com o comando:
    ```
    ./bioinsp <filePath> <fileType> <populationSize> <platô> <mutation>
    ```

    2.1 filePath: Arquivo onde se encontra as informações das cidades. 

    2.2 fileType: Indica qual a estrutura o arquivo usa para organizar as cidades.

    * `sgb` para base da sgb, 
    * `lau` para base da lau, 
    * `crt` Para bases que dao as cidades como pontos

    2.3 populationSize: Tamanho da população utilizada no algoritmo. 

    2.4 platô: Número de gerações sem mudança no melhor indivíduo para o algoritmo terminar.

    2.5 mutation: Mutação considerada no algoritmo, variando de `0` a `100`.

Trabalho realizado por Guilherme Fonseca, Guilherme Bittencourt e Yan Andrade.
