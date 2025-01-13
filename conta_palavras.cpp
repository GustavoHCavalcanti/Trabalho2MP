// Copyright 2025 Gustavo
// conta_palavras.cpp
#include "conta_palavras.hpp"
#include <sstream>
#include <cctype>
#include <algorithm>
#include <map>
#include <string>
#include <locale>
#include <iterator>
#include <fstream>
#include <stdexcept>
#include <iostream>
#include <clocale> // Para usar setlocale

/**
 * @brief Configura a localidade para garantir o correto tratamento de acentuação.
 * 
 * Esta função configura a localidade para o idioma português (Brasil) no formato UTF-8, 
 * permitindo que caracteres acentuados sejam corretamente processados no sistema.
 */
void configurarLocalidade() {
    std::setlocale(LC_ALL, "pt_BR.UTF-8"); // Defina conforme a localidade adequada
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
 * Esta função remove qualquer caractere que não seja alfanumérico, espaço ou hífen, 
 * garantindo que apenas as palavras sejam processadas.
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
 * Esta função processa um texto, removendo pontuação e convertendo para minúsculas, 
 * enquanto mantém palavras compostas com hífens válidas.
 * 
 * @param texto O texto a ser processado.
 * @return Um mapa com as palavras e suas respectivas contagens.
 */
std::map<std::string, int> processarTexto(const std::string& texto) {
    std::map<std::string, int> contagem;
    std::string textoSemPontuacao = removerPontuacao(texto); // Remove toda a pontuação
    std::stringstream ss(textoSemPontuacao);
    std::string palavra;

    while (ss >> palavra) {
        // Aqui garantimos que a palavra será convertida para minúscula, mas sem perder acentuação
        std::string palavraSemAcento = palavra;
        std::transform(palavra.begin(), palavra.end(), palavraSemAcento.begin(), ::tolower); 

        if (!palavra.empty() && palavraComHifenValida(palavra)) { // Adiciona ao mapa se válido
            contagem[palavraSemAcento]++; // Contabiliza a palavra ignorando case
        }
    }

    return contagem;
}

/**
 * @brief Conta palavras distintas em um arquivo de texto.
 * 
 * Esta função abre um arquivo de texto e processa cada linha, utilizando a função
 * @ref processarTexto para contar as palavras distintas em cada linha.
 * 
 * @param nomeArquivo O nome do arquivo a ser lido.
 * @return Um mapa com as palavras e suas respectivas contagens.
 * @throws std::runtime_error Se ocorrer um erro ao abrir o arquivo.
 */
std::map<std::string, int> contarPalavras(const std::string& nomeArquivo) {
    std::ifstream arquivo(nomeArquivo);

    if (!arquivo.is_open()) {
        throw std::runtime_error("Erro ao abrir o arquivo: " + nomeArquivo);
    }

    std::string linha;
    std::map<std::string, int> contagemTotal;

    while (std::getline(arquivo, linha)) {
        auto contagemLinha = processarTexto(linha);
        for (const auto& [palavra, quantidade] : contagemLinha) {
            contagemTotal[palavra] += quantidade;
        }
    }

    arquivo.close();
    return contagemTotal;
}

/**
 * @brief Exibe as palavras e suas contagens em ordem alfabética.
 * 
 * Esta função imprime no console as palavras do mapa, juntamente com suas contagens, 
 * ordenadas em ordem alfabética.
 * 
 * @param palavras O mapa de palavras e contagens.
 */
void exibirPalavrasOrdenadas(const std::map<std::string, int>& palavras) {
    for (const auto& par : palavras) {
        std::cout << par.first << ": " << par.second << std::endl;
    }
}







