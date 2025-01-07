#include "conta_palavras.hpp"
#include <sstream>
#include <cctype>
#include <algorithm>
#include <map>
#include <string>
#include <locale>
#include <codecvt>

/**
 * @brief Remove acentos de uma string usando std::wstring e std::locale.
 * 
 * @param palavra A palavra a ser normalizada.
 * @return A palavra sem acentos.
 */
std::string removerAcentos(const std::string& palavra) {
    std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;
    std::wstring wide_palavra = converter.from_bytes(palavra);
    std::wstring resultado;

    std::locale loc("en_US.UTF-8");
    for (wchar_t c : wide_palavra) {
        if (std::isalnum(c, loc)) { // Preserva caracteres alfanuméricos (letras e números)
            resultado += c;
        }
    }

    return converter.to_bytes(resultado);
}

std::map<std::string, int> contarPalavras(const std::string& texto) {
    std::map<std::string, int> contagem;
    std::stringstream ss(texto);
    std::string palavra;

    while (ss >> palavra) {
        // Remove pontuações no início e no final da palavra, mas preserva palavras alfanuméricas
        palavra.erase(std::remove_if(palavra.begin(), palavra.end(),
            [](char c) { return !std::isalnum(c) && !std::isspace(c); }), palavra.end());

        palavra = removerAcentos(palavra);
        std::transform(palavra.begin(), palavra.end(), palavra.begin(), ::tolower);
        if (!palavra.empty()) { // Adiciona ao mapa somente se não estiver vazia
            contagem[palavra]++;
        }
    }

    return contagem;
}




