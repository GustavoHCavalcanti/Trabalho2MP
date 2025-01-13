// Copyright 2025 Gustavo
#include <fstream>
#include <gtest/gtest.h>
#include "conta_palavras.hpp"
#include <string>

/**
 * @brief Testa a contagem de palavras simples.
 * 
 * Esse teste verifica se a função `contarPalavras` conta corretamente as palavras simples
 * em um arquivo de texto sem pontuação.
 */
TEST(ContaPalavrasTest, ContaPalavrasSimples) {
    std::string texto = "ola ola mundo";
    std::ofstream arquivo("teste.txt");
    arquivo << texto; // Escreve a string no arquivo
    arquivo.close();

    auto resultado = contarPalavras("teste.txt"); // Lê do arquivo

    EXPECT_EQ(resultado["ola"], 2);
    EXPECT_EQ(resultado["mundo"], 1);

    std::remove("teste.txt"); // Apaga o arquivo temporário após o teste
}

/**
 * @brief Testa a contagem de palavras com pontuação.
 * 
 * Esse teste verifica se a função `contarPalavras` ignora corretamente a pontuação 
 * e conta as palavras adequadamente.
 */
TEST(ContaPalavrasTest, ContaPalavrasComPontuacao) {
    std::string texto = "ola, ola! mundo.";
    std::ofstream arquivo("teste.txt");
    arquivo << texto;
    arquivo.close();

    auto resultado = contarPalavras("teste.txt");

    EXPECT_EQ(resultado["ola"], 2);
    EXPECT_EQ(resultado["mundo"], 1);

    std::remove("teste.txt");
}

/**
 * @brief Testa a contagem de palavras com sensibilidade a maiúsculas e minúsculas.
 * 
 * Esse teste verifica se a função `contarPalavras` é insensível a maiúsculas e minúsculas.
 */
TEST(ContaPalavrasTest, ContaPalavrasCaseInsensitive) {
    std::string texto = "Ola ola Mundo mundo";
    std::ofstream arquivo("teste.txt");
    arquivo << texto;
    arquivo.close();

    auto resultado = contarPalavras("teste.txt");

    EXPECT_EQ(resultado["ola"], 2);
    EXPECT_EQ(resultado["mundo"], 2);

    std::remove("teste.txt");
}

/**
 * @brief Testa a contagem de palavras em um texto vazio.
 * 
 * Esse teste verifica se a função `contarPalavras` retorna corretamente um mapa vazio 
 * quando o arquivo de entrada não contém palavras.
 */
TEST(ContaPalavrasTest, ContaPalavrasVazia) {
    std::string texto = "";
    std::ofstream arquivo("teste.txt");
    arquivo << texto;
    arquivo.close();

    auto resultado = contarPalavras("teste.txt");

    EXPECT_TRUE(resultado.empty());

    std::remove("teste.txt");
}

/**
 * @brief Testa a contagem de palavras com números.
 * 
 * Esse teste verifica se a função `contarPalavras` conta corretamente palavras que 
 * contêm números.
 */
TEST(ContaPalavrasTest, ContaPalavrasComNumeros) {
    std::string texto = "ano2025 ano2025";
    std::ofstream arquivo("teste.txt");
    arquivo << texto;
    arquivo.close();

    auto resultado = contarPalavras("teste.txt");

    EXPECT_EQ(resultado["ano2025"], 2);

    std::remove("teste.txt");
}

/**
 * @brief Testa a contagem de palavras com pontuação e várias ocorrências.
 * 
 * Esse teste verifica se a função `contarPalavras` lida corretamente com a pontuação 
 * e contabiliza múltiplas ocorrências de palavras.
 */
TEST(ContaPalavrasTest, ContaPalavrasMultiplaComPontuacao) {
    std::string texto = "ola, ola! mundo. mundo";
    std::ofstream arquivo("teste.txt");
    arquivo << texto;
    arquivo.close();

    auto resultado = contarPalavras("teste.txt");

    EXPECT_EQ(resultado["ola"], 2);
    EXPECT_EQ(resultado["mundo"], 2);

    std::remove("teste.txt");
}

/**
 * @brief Testa a contagem de palavras com hífen.
 * 
 * Esse teste verifica se a função `contarPalavras` lida corretamente com palavras compostas 
 * por hífen.
 */
TEST(ContaPalavrasTest, ContaPalavrasComHifen) {
    std::string texto = "meia-noite meia-noite bom-dia";
    std::ofstream arquivo("teste.txt");
    arquivo << texto;
    arquivo.close();

    auto resultado = contarPalavras("teste.txt");

    EXPECT_EQ(resultado["meia-noite"], 2);
    EXPECT_EQ(resultado["bom-dia"], 1);

    std::remove("teste.txt");
}

/**
 * @brief Testa a contagem de palavras com caracteres alfanuméricos.
 * 
 * Esse teste verifica se a função `contarPalavras` lida corretamente com palavras que 
 * contêm caracteres alfanuméricos.
 */
TEST(ContaPalavrasTest, ContaPalavrasComAlfanumericos) {
    std::string texto = "abc123 123abc abc123";
    std::ofstream arquivo("teste.txt");
    arquivo << texto;
    arquivo.close();

    auto resultado = contarPalavras("teste.txt");

    EXPECT_EQ(resultado["abc123"], 2);
    EXPECT_EQ(resultado["123abc"], 1);

    std::remove("teste.txt");
}

/**
 * @brief Testa a contagem de palavras compostas por hífen.
 * 
 * Esse teste verifica se a função `contarPalavras` lida corretamente com palavras compostas 
 * por hífen, como "meia-noite" e "bem-vindo".
 */
TEST(ContaPalavrasTest, PalavrasComHifen) {
    std::string texto = "meia-noite e um horario comum. bem-vindo ao ano 2025.";
    std::ofstream arquivo("teste.txt");
    arquivo << texto;
    arquivo.close();

    auto resultado = contarPalavras("teste.txt");

    EXPECT_EQ(resultado["meia-noite"], 1);
    EXPECT_EQ(resultado["bem-vindo"], 1);
    EXPECT_EQ(resultado["um"], 1);
    EXPECT_EQ(resultado["e"], 1);
    EXPECT_EQ(resultado["horario"], 1);
    EXPECT_EQ(resultado["comum"], 1);
    EXPECT_EQ(resultado["ao"], 1);
    EXPECT_EQ(resultado["ano"], 1);
    EXPECT_EQ(resultado["2025"], 1);

    std::remove("teste.txt");
}

/**
 * @brief Testa a contagem de palavras com pontuação.
 * 
 * Esse teste verifica se a função `contarPalavras` lida corretamente com pontuação 
 * e contabiliza corretamente as palavras.
 */
TEST(ContaPalavrasTest, PalavrasComPontos) {
    std::string texto = "com Vinicius pontos! isso? mas. legal!! Vinicius Junior,,";
    std::ofstream arquivo("teste.txt");
    arquivo << texto;
    arquivo.close();

    auto resultado = contarPalavras("teste.txt");

    EXPECT_EQ(resultado["com"], 1);
    EXPECT_EQ(resultado["pontos"], 1);
    EXPECT_EQ(resultado["isso"], 1);
    EXPECT_EQ(resultado["mas"], 1);
    EXPECT_EQ(resultado["legal"], 1);
    EXPECT_EQ(resultado["vinicius"], 2);
    EXPECT_EQ(resultado["junior"], 1);

    std::remove("teste.txt");
}

/**
 * @brief Testa a contagem de palavras com hífen e pontuação.
 * 
 * Esse teste verifica se a função `contarPalavras` lida corretamente com palavras compostas 
 * por hífen e com pontuação associada.
 */
TEST(ContaPalavrasTest, PontuacaoComHifen) {
    std::string texto = "ola, boa-tarde! como-vai voce?";
    std::ofstream arquivo("teste.txt");
    arquivo << texto;
    arquivo.close();

    auto resultado = contarPalavras("teste.txt");

    EXPECT_EQ(resultado["ola"], 1);
    EXPECT_EQ(resultado["boa-tarde"], 1);
    EXPECT_EQ(resultado["como-vai"], 1);
    EXPECT_EQ(resultado["voce"], 1);

    std::remove("teste.txt");
}

/**
 * @brief Testa a contagem de palavras compostas por hífen e pontuação.
 * 
 * Esse teste verifica se a função `contarPalavras` lida corretamente com palavras compostas 
 * por hífen e com pontuação, como "meia-noite" e "bem-vindo".
 */
TEST(ContaPalavrasTest, PalavrasComHifenEPontuacao) {
    std::string texto = "meia-noite, bem-vindo ao mundo!";
    std::ofstream arquivo("teste.txt");
    arquivo << texto;
    arquivo.close();

    auto resultado = contarPalavras("teste.txt");

    EXPECT_EQ(resultado["meia-noite"], 1);
    EXPECT_EQ(resultado["bem-vindo"], 1);
    EXPECT_EQ(resultado["ao"], 1);
    EXPECT_EQ(resultado["mundo"], 1);

    std::remove("teste.txt");
}





