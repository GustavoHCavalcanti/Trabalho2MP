// Copyright 2025 Gustavo
#include "conta_palavras.hpp"
#include <sstream>
#include <cctype>
#include <algorithm>
#include <map>
#include <string>

/**
 * @brief Conta a ocorrência de palavras em um texto.
 * 
 * Esta função recebe uma string contendo um texto e conta quantas vezes 
 * cada palavra aparece no texto. A contagem é realizada sem considerar 
 * diferenças entre maiúsculas e minúsculas. Além disso, caracteres não 
 * alfanuméricos (como pontuação) são removidos antes de realizar a contagem.
 * 
 * @param texto O texto a ser analisado.
 * 
 * @return Um mapa onde as chaves são as palavras do texto e os valores 
 *         são o número de ocorrências de cada palavra.
 */
std::map<std::string, int> contarPalavras(const std::string& texto) {
    std::map<std::string, int> contagem;  ///< Mapa para armazenar as palavras e suas contagens
    std::stringstream ss(texto);  ///< StringStream para dividir o texto em palavras
    std::string palavra;  ///< Variável para armazenar a palavra atual

    // Loop para processar cada palavra do texto
    while (ss >> palavra) {
        // Remove caracteres não alfanuméricos (pontuação)
        palavra.erase(remove_if(palavra.begin(), palavra.end(),
            [](char c) { return !std::isalnum(c); }), palavra.end());

        // Converte a palavra para minúscula para garantir que a contagem não seja case-sensitive
        std::transform(palavra.begin(), palavra.end(), palavra.begin(), ::tolower);

        // Atualiza a contagem da palavra
        contagem[palavra]++;
    }

    return contagem;  ///< Retorna o mapa com a contagem das palavras
}
