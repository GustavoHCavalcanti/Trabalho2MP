# Nome dos executáveis
TARGET_MAIN = testa_conta_palavras
TARGET_TEST = check_gtest

# Compiladores
CC = gcc
CXX = g++

# Flags de compilação
CFLAGS = -std=c99 -Wall -g  # Alterado para C99
CXXFLAGS = -std=c++14 -Wall -g -I./googletest/include
LDFLAGS = -L./googletest/lib -lgtest -lgtest_main -pthread

# Arquivos fonte e objeto
MAIN_SOURCES = conta_palavras.c testa_conta_palavras.c
MAIN_OBJECTS = conta_palavras.o testa_conta_palavras.o

TEST_SOURCES = check_gtest.cpp
TEST_OBJECTS = check_gtest.o

# Regras padrão
all: $(TARGET_MAIN) $(TARGET_TEST)

# Compilar e executar o programa principal
$(TARGET_MAIN): $(MAIN_OBJECTS)
	$(CXX) $(CXXFLAGS) $(MAIN_OBJECTS) -o $(TARGET_MAIN) $(LDFLAGS)  # Linkar com gtest aqui também

# Compilar e executar os testes com gtest
$(TARGET_TEST): $(TEST_OBJECTS)
	$(CXX) $(CXXFLAGS) $(TEST_OBJECTS) $(LDFLAGS) -o $(TARGET_TEST)

# Compilar arquivos objeto principais
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Compilar arquivos objeto de teste
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpeza dos arquivos gerados
clean:
	rm -f *.o $(TARGET_MAIN) $(TARGET_TEST)

# Testar com gtest
test: $(TARGET_TEST)
	./$(TARGET_TEST)

# Regras adicionais
valgrind:
	valgrind ./$(TARGET_MAIN)

cppcheck:
	cppcheck --enable=warning --language=c .

coverage: $(TARGET_MAIN)
	./$(TARGET_MAIN)
	gcov conta_palavras.c
	gcov testa_conta_palavras.c
