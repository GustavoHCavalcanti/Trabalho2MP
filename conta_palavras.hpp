// Copyright 2025 Gustavo
#ifndef CONTA_PALAVRAS_HPP
#define CONTA_PALAVRAS_HPP

#include <string>
#include <map>

/**
 * @brief Tipo para armazenar a contagem de palavras.
 * 
 * Este tipo é um alias para um `std::map` onde a chave é uma palavra do texto 
 * e o valor é o número de vezes que essa palavra aparece.
 */
typedef std::map<std::string, int> PalavraContagem;

/**
 * @brief Conta palavras distintas em um arquivo de texto.
 * 
 * Esta função recebe o nome de um arquivo e processa seu conteúdo para contar a 
 * quantidade de ocorrências de cada palavra distinta, considerando pontuação e acentuação.
 * 
 * @param nomeArquivo O nome do arquivo a ser lido.
 * @return Um mapa com as palavras e suas respectivas contagens.
 * @throws std::runtime_error Se ocorrer um erro ao abrir o arquivo.
 */
PalavraContagem contarPalavras(const std::string& nomeArquivo);

/**
 * @brief Exibe as palavras e suas contagens em ordem alfabética.
 * 
 * Esta função exibe no console as palavras de um mapa, juntamente com suas contagens, 
 * ordenadas em ordem alfabética.
 * 
 * @param palavras O mapa de palavras e contagens a ser exibido.
 */
void exibirPalavrasOrdenadas(const PalavraContagem& palavras);

#endif

