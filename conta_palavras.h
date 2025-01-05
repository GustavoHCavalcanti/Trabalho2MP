#include "conta_palavras.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Função para contar as palavras diferentes em um arquivo e armazenar na estrutura Palavra.
int conta_palavras(const char *nome_arquivo, Palavra **resultado) {
    if (!nome_arquivo || !resultado) {
        return 0; // Entrada inválida
    }

    FILE *arquivo = fopen(nome_arquivo, "r");
    if (!arquivo) {
        return 0; // Falha ao abrir o arquivo
    }

    Palavra *palavras = NULL;
    size_t quantidade = 0;
    char buffer[256]; // Para leitura de palavras individuais

    while (fscanf(arquivo, " %255s", buffer) == 1) {
        // Diferencia maiúsculas e minúsculas e verifica duplicatas
        int encontrado = 0;
        for (size_t i = 0; i < quantidade; i++) {
            if (strcmp(palavras[i].palavra, buffer) == 0) {
                palavras[i].ocorrencias++;
                encontrado = 1;
                break;
            }
        }

        // Adiciona nova palavra se não encontrada
        if (!encontrado) {
            Palavra *temp = realloc(palavras, (quantidade + 1) * sizeof(Palavra));
            if (!temp) {
                fclose(arquivo);
                free(palavras);
                return 0; // Falha de memória
            }
            palavras = temp;
            palavras[quantidade].palavra = strdup(buffer);
            palavras[quantidade].ocorrencias = 1;
            quantidade++;
        }
    }

    fclose(arquivo);

    // Ordena alfabeticamente
    for (size_t i = 0; i < quantidade - 1; i++) {
        for (size_t j = i + 1; j < quantidade; j++) {
            if (strcmp(palavras[i].palavra, palavras[j].palavra) > 0) {
                Palavra temp = palavras[i];
                palavras[i] = palavras[j];
                palavras[j] = temp;
            }
        }
    }

    *resultado = palavras;
    return quantidade;
}

// Libera memória alocada para a lista de palavras
void libera_palavras(Palavra *palavras, size_t quantidade) {
    if (!palavras) {
        return;
    }

    for (size_t i = 0; i < quantidade; i++) {
        free(palavras[i].palavra);
    }
    free(palavras);
}
