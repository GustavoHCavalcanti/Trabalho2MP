#include <gtest/gtest.h>
#include "conta_palavras.hpp"

// Teste básico para verificar a contagem de palavras
TEST(ContaPalavrasTest, ContaPalavrasSimples) {
    std::string texto = "ola ola mundo";
    auto resultado = contarPalavras(texto);

    // Verificar a contagem de palavras
    EXPECT_EQ(resultado["ola"], 2);
    EXPECT_EQ(resultado["mundo"], 1);
}

// Teste de palavras com pontuação
TEST(ContaPalavrasTest, ContaPalavrasComPontuacao) {
    std::string texto = "ola, ola! mundo.";
    auto resultado = contarPalavras(texto);

    // Verificar a contagem de palavras (ignorando pontuação)
    EXPECT_EQ(resultado["ola"], 2);
    EXPECT_EQ(resultado["mundo"], 1);
}

// Teste de palavras com diferentes maiúsculas e minúsculas
TEST(ContaPalavrasTest, ContaPalavrasCaseInsensitive) {
    std::string texto = "Ola ola Mundo mundo";
    auto resultado = contarPalavras(texto);

    // Verificar a contagem de palavras (ignorando diferenças de maiúsculas/minúsculas)
    EXPECT_EQ(resultado["ola"], 2);
    EXPECT_EQ(resultado["mundo"], 2);
}


