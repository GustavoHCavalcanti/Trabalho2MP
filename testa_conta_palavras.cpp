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

/**
 * @brief Teste de contagem em texto vazio.
 * 
 * Este teste verifica se a função `contarPalavras` retorna um mapa vazio 
 * quando o texto de entrada é vazio.
 */
TEST(ContaPalavrasTest, ContaPalavrasVazia) {
    std::string texto = "";
    auto resultado = contarPalavras(texto);

    // Verificar que o mapa está vazio
    EXPECT_TRUE(resultado.empty());
}

/**
 * @brief Teste de contagem de palavras com números.
 * 
 * Este teste verifica se a função `contarPalavras` lida corretamente com 
 * palavras que contêm números. A palavra "ano2025" deve ser contada 1 vez.
 */
TEST(ContaPalavrasTest, ContaPalavrasComNumeros) {
    std::string texto = "ano2025 ano2025";
    auto resultado = contarPalavras(texto);

    // Verificar a contagem da palavra com números
    EXPECT_EQ(resultado["ano2025"], 2);
}

/**
 * @brief Teste de contagem de palavras com múltiplas ocorrências e pontuação.
 * 
 * Este teste verifica se a função `contarPalavras` consegue contar corretamente 
 * palavras com múltiplas ocorrências e pontuação misturada, como vírgulas e pontos.
 * A palavra "olá" deve ser contada 3 vezes e a palavra "mundo" deve ser contada 2 vezes.
 */
TEST(ContaPalavrasTest, ContaPalavrasMultiplaComPontuacao) {
    std::string texto = "ola, ola! mundo. mundo";
    auto resultado = contarPalavras(texto);

    EXPECT_EQ(resultado["ola"], 2);  // "olá" aparece 2 vezes, removendo acentos e pontuação
    EXPECT_EQ(resultado["mundo"], 2);  // "mundo" aparece 2 vezes
}

/**
 * @brief Testa se a função lida corretamente com palavras contendo hífens.
 * 
 * Este teste verifica se palavras compostas por hífens são tratadas como únicas,
 * sem serem divididas.
 */
TEST(ContaPalavrasTest, ContaPalavrasComHifen) {
    std::string texto = "meia-noite meia-noite bom-dia";
    auto resultado = contarPalavras(texto);

    // "meia-noite" deve aparecer 2 vezes e "bom-dia" deve aparecer 1 vez
    EXPECT_EQ(resultado["meia-noite"], 2);
    EXPECT_EQ(resultado["bom-dia"], 1);
}

/**
 * @brief Testa se a função lida corretamente com palavras alfanuméricas.
 * 
 * Este teste verifica se palavras que contêm combinações de letras e números
 * são processadas adequadamente.
 */
TEST(ContaPalavrasTest, ContaPalavrasComAlfanumericos) {
    std::string texto = "abc123 123abc abc123";
    auto resultado = contarPalavras(texto);

    // "abc123" deve aparecer 2 vezes e "123abc" deve aparecer 1 vez
    EXPECT_EQ(resultado["abc123"], 2);
    EXPECT_EQ(resultado["123abc"], 1);
}

/**
 * @brief Testa palavras compostas com hífen.
 * 
 * Este teste verifica se a função contarPalavras processa corretamente palavras compostas
 * que contêm hífen, como "meia-noite" ou "bem-vindo".
 */
TEST(ContaPalavrasTest, PalavrasComHifen) {
    std::string texto = "meia-noite e um horario comum. bem-vindo ao ano 2025.";
    auto resultado = contarPalavras(texto);
    EXPECT_EQ(resultado["meia-noite"], 1);
    EXPECT_EQ(resultado["bem-vindo"], 1);
    EXPECT_EQ(resultado["um"], 1);
    EXPECT_EQ(resultado["e"], 1);
    EXPECT_EQ(resultado["horario"], 1);
    EXPECT_EQ(resultado["comum"], 1);
    EXPECT_EQ(resultado["ao"], 1);
    EXPECT_EQ(resultado["ano"], 1);
    EXPECT_EQ(resultado["2025"], 1);
}

/**
 * @brief Testa palavras com pontuação.
 * 
 * Este teste verifica se a função contarPalavras processa corretamente palavras com
 * pontuação no final, como "com", "pontuação!" e "isso?".
 */
TEST(ContaPalavrasTest, PalavrasComPontos) {
    std::string texto = "com Vinicius pontos! isso? mas. legal!! Vinicius Junior,,";
    auto resultado = contarPalavras(texto);
    EXPECT_EQ(resultado["com"], 1);
    EXPECT_EQ(resultado["pontos"], 1);
    EXPECT_EQ(resultado["isso"], 1);
    EXPECT_EQ(resultado["mas"], 1);
    EXPECT_EQ(resultado["legal"], 1);
    EXPECT_EQ(resultado["vinicius"], 2);
    EXPECT_EQ(resultado["junior"], 1);
}

/**
 * @brief Testa a remoção de pontuação ao redor de palavras compostas com hífen.
 * 
 * Este teste verifica se a pontuação ao redor de palavras compostas com hífen é
 * corretamente removida, e se as palavras são contadas sem alterações indesejadas.
 */
TEST(ContaPalavrasTest, PontuacaoComHifen) {
    std::string texto = "ola, boa-tarde! como-vai voce?";
    auto resultado = contarPalavras(texto);
    
    EXPECT_EQ(resultado["ola"], 1);          // Palavra simples
    EXPECT_EQ(resultado["boa-tarde"], 1);    // Palavra composta com hífen
    EXPECT_EQ(resultado["como-vai"], 1);     // Palavra composta com hífen
    EXPECT_EQ(resultado["voce"], 1);         // Palavra simples
}





