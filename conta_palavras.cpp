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

/**
 * @brief Verifica se uma palavra com hífen é válida.
 * 
 * Uma palavra com hífen é considerada válida se:
 * - O hífen está entre caracteres alfanuméricos.
 * - Não contém múltiplos hífens consecutivos.
 * 
 * @param palavra A palavra a ser validada.
 * @return true se a palavra for válida, false caso contrário.
 */
bool palavraComHifenValida(const std::string& palavra) {
    if (palavra.find("--") != std::string::npos) return false; // Evita múltiplos hífens consecutivos
    if (palavra.front() == '-' || palavra.back() == '-') return false; // Hífen no início ou fim
    return std::all_of(palavra.begin(), palavra.end(), [](char c) {
        return std::isalnum(c) || c == '-';
    });
}

/**
 * @brief Conta as palavras distintas em um texto, considerando critérios como case-insensitivity,
 * remoção de pontuação e suporte a palavras compostas com hífen.
 * 
 * @param texto O texto a ser processado.
 * @return Um mapa com as palavras e suas respectivas contagens.
 */
std::map<std::string, int> contarPalavras(const std::string& texto) {
    std::map<std::string, int> contagem;
    std::stringstream ss(texto);
    std::string palavra;

    while (ss >> palavra) {
        // Remove pontuações no início e no final da palavra
        auto inicio = palavra.begin();
        auto fim = palavra.end();
        while (inicio != fim && !std::isalnum(*inicio) && *inicio != '-') ++inicio;
        while (fim != inicio && !std::isalnum(*(fim - 1)) && *(fim - 1) != '-') --fim;
        palavra = std::string(inicio, fim);

        palavra = removerAcentos(palavra);
        std::transform(palavra.begin(), palavra.end(), palavra.begin(), ::tolower);

        if (!palavra.empty() && palavraComHifenValida(palavra)) { // Adiciona ao mapa se válido
            contagem[palavra]++;
        }
    }

    return contagem;
}





