// Copyright 2025 Gustavo
#include <gtest/gtest.h>
#include "conta_palavras.hpp"
#include <string>

/**
 * @file testa_conta_palavras.cpp
 * 
 * @brief Testes unitários para a função contarPalavras.
 * 
 * Este arquivo contém testes para a função `contarPalavras`, que conta a ocorrência
 * de cada palavra em um texto fornecido. A função deve lidar corretamente com texto
 * simples, pontuação e diferenças entre maiúsculas e minúsculas.
 */

/**
 * @brief Teste de contagem de palavras simples.
 * 
 * Este teste verifica se a função `contarPalavras` consegue contar corretamente 
 * as palavras em um texto simples. A palavra "ola" deve ser contada 2 vezes e 
 * a palavra "mundo" deve ser contada 1 vez.
 */
TEST(ContaPalavrasTest, ContaPalavrasSimples) {
    std::string texto = "ola ola mundo";
    auto resultado = contarPalavras(texto);

    // Verificar a contagem de palavras
    EXPECT_EQ(resultado["ola"], 2);
    EXPECT_EQ(resultado["mundo"], 1);
}

/**
 * @brief Teste de contagem de palavras com pontuação.
 * 
 * Este teste verifica se a função `contarPalavras` consegue contar as palavras 
 * corretamente, ignorando pontuação (como vírgulas, pontos de exclamação e pontos).
 * A palavra "ola" deve ser contada 2 vezes e a palavra "mundo" deve ser contada 1 vez.
 */
TEST(ContaPalavrasTest, ContaPalavrasComPontuacao) {
    std::string texto = "ola, ola! mundo.";
    auto resultado = contarPalavras(texto);

    // Verificar a contagem de palavras (ignorando pontuação)
    EXPECT_EQ(resultado["ola"], 2);
    EXPECT_EQ(resultado["mundo"], 1);
}

/**
 * @brief Teste de contagem de palavras insensível a maiúsculas.
 * 
 * Este teste verifica se a função `contarPalavras` não faz distinção entre 
 * maiúsculas e minúsculas. Ou seja, "Ola" e "ola" devem ser tratadas como a 
 * mesma palavra, e "Mundo" e "mundo" também devem ser contadas como uma só.
 */
TEST(ContaPalavrasTest, ContaPalavrasCaseInsensitive) {
    std::string texto = "Ola ola Mundo mundo";
    auto resultado = contarPalavras(texto);

    // Verificar a contagem de palavras (ignorando diferenças de maiúsculas/minúsculas)
    EXPECT_EQ(resultado["ola"], 2);
    EXPECT_EQ(resultado["mundo"], 2);
}



