// Copyright 2025 Gustavo
#ifndef CONTA_PALAVRAS_HPP
#define CONTA_PALAVRAS_HPP

#include <map>
#include <string>

/**
 * @file conta_palavras.hpp
 * 
 * @brief Declaração da função para contar as palavras em um texto.
 * 
 * Este arquivo contém a declaração da função `contarPalavras`, que é 
 * responsável por contar a frequência de ocorrência de cada palavra em um 
 * texto. Ele utiliza um mapa para armazenar as palavras e suas respectivas 
 * contagens.
 */

/**
 * @brief Conta a ocorrência de palavras em um texto.
 * 
 * A função `contarPalavras` recebe uma string contendo um texto e retorna 
 * um mapa onde as chaves são as palavras do texto e os valores são o número 
 * de vezes que cada palavra aparece. Caracteres não alfanuméricos são 
 * removidos das palavras e a contagem é feita de forma insensível a maiúsculas 
 * e minúsculas.
 * 
 * @param texto A string que contém o texto a ser analisado.
 * 
 * @return Um mapa de palavras (chaves) e suas contagens (valores).
 */
std::map<std::string, int> contarPalavras(const std::string& texto);

#endif
