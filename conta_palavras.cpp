// Copyright 2025 Gustavo
#include "conta_palavras.hpp"
#include <sstream>
#include <cctype>
#include <algorithm>
#include <map>
#include <string>
#include <locale>
#include <unordered_map>

/**
 * @brief Remove acentos de uma string.
 * 
 * Esta função converte caracteres acentuados (como "á", "é", etc.) para seus
 * equivalentes não acentuados (como "a", "e", etc.), utilizando um mapa para
 * realizar a substituição.
 * 
 * @param palavra A palavra a ser normalizada.
 * @return A palavra sem acentos.
 */
std::string removerAcentos(const std::string& palavra) {
    // Mapa de caracteres com acento para os respectivos sem acento
    std::unordered_map<char, char> acentos = {
        {'á', 'a'}, {'à', 'a'}, {'ã', 'a'}, {'â', 'a'}, {'ä', 'a'},
        {'é', 'e'}, {'è', 'e'}, {'ê', 'e'}, {'ë', 'e'},
        {'í', 'i'}, {'ì', 'i'}, {'î', 'i'}, {'ï', 'i'},
        {'ó', 'o'}, {'ò', 'o'}, {'õ', 'o'}, {'ô', 'o'}, {'ö', 'o'},
        {'ú', 'u'}, {'ù', 'u'}, {'û', 'u'}, {'ü', 'u'},
        {'ç', 'c'}, {'Á', 'A'}, {'À', 'A'}, {'Ã', 'A'}, {'Â', 'A'}, {'Ä', 'A'},
        {'É', 'E'}, {'È', 'E'}, {'Ê', 'E'}, {'Ë', 'E'},
        {'Í', 'I'}, {'Ì', 'I'}, {'Î', 'I'}, {'Ï', 'I'},
        {'Ó', 'O'}, {'Ò', 'O'}, {'Õ', 'O'}, {'Ô', 'O'}, {'Ö', 'O'},
        {'Ú', 'U'}, {'Ù', 'U'}, {'Û', 'U'}, {'Ü', 'U'},
        {'Ç', 'C'}
    };

    std::string resultado = palavra;
    for (char& c : resultado) {
        auto it = acentos.find(c);
        if (it != acentos.end()) {
            c = it->second;  // Substitui o caractere com acento pelo sem acento
        }
    }
    return resultado;
}

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
        // Remove caracteres não alfanuméricos (pontuação) que não sejam letras ou números
        palavra.erase(std::remove_if(palavra.begin(), palavra.end(),
            [](char c) { return !std::isalnum(c) && c != '-'; }), palavra.end());

        // Remove acentos das palavras
        palavra = removerAcentos(palavra);

        // Converte a palavra para minúscula para garantir que a contagem não seja case-sensitive
        std::transform(palavra.begin(), palavra.end(), palavra.begin(), ::tolower);

        // Atualiza a contagem da palavra
        contagem[palavra]++;
    }

    return contagem;  ///< Retorna o mapa com a contagem das palavras
}



