# Nome dos executáveis
TARGET_MAIN = testa_conta_palavras
TARGET_TEST = testa_conta_palavras  # Usando o mesmo nome para o programa de teste

# Compiladores
CC = gcc
CXX = g++

# Flags de compilação
CFLAGS = -std=c99 -Wall -g  # Usando C99
CXXFLAGS = -std=c++14 -Wall -g -I./googletest/include  # Diretório correto para o gtest
LDFLAGS = -L./googletest/lib -L/usr/lib -lgtest -lgtest_main -pthread  # Diretórios e flags para o gtest

# Arquivos fonte e objeto
MAIN_SOURCES = conta_palavras.cpp testa_conta_palavras.cpp  # Arquivos de código fonte
MAIN_OBJECTS = conta_palavras.o testa_conta_palavras.o    # Arquivos objeto

# Regras padrão
all: $(TARGET_MAIN) $(TARGET_TEST)

# Compilar e executar o programa principal
$(TARGET_MAIN): $(MAIN_OBJECTS)
	$(CXX) $(CXXFLAGS) $(MAIN_OBJECTS) -o $(TARGET_MAIN) $(LDFLAGS)  # Linkando com gtest

# Compilar arquivos objeto principais
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
	gcov conta_palavras.cpp
	gcov testa_conta_palavras.cpp

