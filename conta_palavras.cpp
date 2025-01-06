#include "conta_palavras.hpp"
#include <sstream>
#include <cctype>
#include <algorithm>

std::map<std::string, int> contarPalavras(const std::string& texto) {
    std::map<std::string, int> contagem;
    std::stringstream ss(texto);
    std::string palavra;

    while (ss >> palavra) {
        // Remove caracteres não alfanuméricos (pontuação)
        palavra.erase(remove_if(palavra.begin(), palavra.end(), 
            [](char c) { return !std::isalnum(c); }), palavra.end());

        // Converte a palavra para minúscula para garantir que a contagem não seja case-sensitive
        std::transform(palavra.begin(), palavra.end(), palavra.begin(), ::tolower);

        // Atualiza a contagem da palavra
        contagem[palavra]++;
    }

    return contagem;
}
