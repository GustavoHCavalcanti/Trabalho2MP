#include "conta_palavras.hpp"
#include <sstream>
#include <cctype>
#include <algorithm>
#include <map>
#include <string>
#include <locale>
#include <codecvt>
#include <iterator>

/**
 * @brief Remove acentos de uma string, substituindo caracteres acentuados por seus equivalentes sem acento.
 * 
 * @param palavra A palavra a ser normalizada.
 * @return A palavra sem acentos.
 */
std::string removerAcentos(const std::string& palavra) {
    std::string resultado;
    for (char c : palavra) {
        switch (c) {
            case 'á': case 'à': case 'ã': case 'â': case 'ä':
                resultado += 'a';
                break;
            case 'é': case 'è': case 'ê': case 'ë':
                resultado += 'e';
                break;
            case 'í': case 'ì': case 'î': case 'ï':
                resultado += 'i';
                break;
            case 'ó': case 'ò': case 'ô': case 'õ': case 'ö':
                resultado += 'o';
                break;
            case 'ú': case 'ù': case 'û': case 'ü':
                resultado += 'u';
                break;
            case 'ç':
                resultado += 'c';
                break;
            case 'ñ':
                resultado += 'n';
                break;
            default:
                resultado += c;
        }
    }
    return resultado;
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
 * @brief Remove toda a pontuação de uma string, mantendo apenas letras, números e espaços.
 * 
 * @param texto O texto a ser processado.
 * @return O texto sem pontuação.
 */
std::string removerPontuacao(const std::string& texto) {
    std::string resultado;
    for (char c : texto) {
        if (std::isalnum(c) || std::isspace(c) || c == '-') { // Mantém letras, números, espaços e hífens
            resultado += c;
        }
    }
    return resultado;
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
    std::string textoSemPontuacao = removerPontuacao(texto); // Remove toda a pontuação
    std::stringstream ss(textoSemPontuacao);
    std::string palavra;

    while (ss >> palavra) {
        palavra = removerAcentos(palavra); // Remove acentos da palavra
        std::transform(palavra.begin(), palavra.end(), palavra.begin(), ::tolower); // Converte para minúsculas

        if (!palavra.empty() && palavraComHifenValida(palavra)) { // Adiciona ao mapa se válido
            contagem[palavra]++;
        }
    }

    return contagem;
}






