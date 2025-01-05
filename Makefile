# Nome dos arquivos principais
TARGET = conta_palavras
TEST_TARGET = testa_conta_palavras

# Compilador e flags
CC = g++
CFLAGS = -Wall -Wextra -pedantic -std=c++17 -g
COVERAGE_FLAGS = -fprofile-arcs -ftest-coverage
LDFLAGS = -lgcov

# Diretórios
SRC_DIR = src
TEST_DIR = tests
BUILD_DIR = build

# Arquivos do projeto
SRC_FILES = $(SRC_DIR)/conta_palavras.cpp
TEST_FILES = $(TEST_DIR)/testa_conta_palavras.cpp
OBJ_FILES = $(BUILD_DIR)/conta_palavras.o
TEST_OBJ_FILES = $(BUILD_DIR)/testa_conta_palavras.o

# Framework de testes (substitua "gtest" por "catch" se usar outro framework)
GTEST_FLAGS = -lgtest -lgtest_main -pthread

# Regras padrão
all: $(TARGET) $(TEST_TARGET)

# Compilação do programa principal
$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $(BUILD_DIR)/$(TARGET)

# Compilação do programa de testes
$(TEST_TARGET): $(OBJ_FILES) $(TEST_OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) $(TEST_OBJ_FILES) $(GTEST_FLAGS) -o $(BUILD_DIR)/$(TEST_TARGET)

# Geração de arquivos .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(COVERAGE_FLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(TEST_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(COVERAGE_FLAGS) -c $< -o $@

# Testes
test: $(TEST_TARGET)
	./$(BUILD_DIR)/$(TEST_TARGET)

# Cobertura
coverage: test
	gcov -o $(BUILD_DIR) $(SRC_FILES) $(TEST_FILES)

# Limpeza
clean:
	rm -rf $(BUILD_DIR) *.gcno *.gcda *.gcov

# Verificadores estáticos e dinâmicos
lint:
	cpplint $(SRC_FILES) $(TEST_FILES)

check:
	cppcheck --enable=all $(SRC_FILES) $(TEST_FILES)

memcheck: $(TEST_TARGET)
	valgrind --leak-check=full ./$(BUILD_DIR)/$(TEST_TARGET)

# Documentação
doc:
	doxygen Doxyfile

.PHONY: all test coverage clean lint check memcheck doc
