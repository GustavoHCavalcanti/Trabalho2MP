# Definir o compilador C++
CXX = g++
CXXFLAGS = -std=c++14 -g -Wall -I./googletest/include
LDFLAGS = -lgtest -lgtest_main -pthread  # Flags para linkar as bibliotecas do Google Test

# Diretórios
INCDIR = ./googletest/include  # Diretório de include do Google Test
LIBDIR = ./googletest/lib      # Diretório de bibliotecas do Google Test

# Nome do arquivo de saída
TARGET = check_gtest

# Objetos
OBJ = check_gtest.o

# Regra principal
all: $(TARGET)

# Regra para compilar o programa de teste
$(TARGET): $(OBJ)
	$(CXX) -o $(TARGET) $(OBJ) $(LDFLAGS)

# Regra para compilar o arquivo .cpp de teste
check_gtest.o: check_gtest.cpp
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c check_gtest.cpp -o check_gtest.o

# Limpeza dos arquivos gerados
clean:
	rm -f $(OBJ) $(TARGET)


