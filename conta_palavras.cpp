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
        if (std::isalnum(c, loc) || c == L'-') { // Preserva caracteres alfanuméricos e hífens
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
        // Remove pontuações no início e no final da palavra, preservando hífens internos
        auto inicio = palavra.begin();
        auto fim = palavra.end();
        while (inicio != fim && !std::isalnum(*inicio) && *inicio != '-') ++inicio;
        while (fim != inicio && !std::isalnum(*(fim - 1)) && *(fim - 1) != '-') --fim;
        palavra = std::string(inicio, fim);

        palavra = removerAcentos(palavra);
        std::transform(palavra.begin(), palavra.end(), palavra.begin(), ::tolower);
        if (!palavra.empty() && palavra.find("--") == std::string::npos) { // Adiciona ao mapa se válido
            contagem[palavra]++;
        }
    }

    return contagem;
}





