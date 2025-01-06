#include <gtest/gtest.h>

// Teste trivial que sempre passa
TEST(GoogleTestCheck, SimpleTest) {
    EXPECT_EQ(1, 1);  // Teste que sempre passa
}

// Função principal que executa os testes
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();  // Executa todos os testes
}
