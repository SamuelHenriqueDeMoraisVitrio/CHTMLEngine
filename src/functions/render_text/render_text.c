
#include "../uniq.definitions_requirements.h"

char* substituir_marcadores(const char* (*func)(void), const char* substituicoes[], size_t num_substituicoes) {
    // Contar o número de marcadores na string HTML
    size_t num_marcadores = 0;
    const char* ptr = func();
    while ((ptr = strstr(ptr, "%s")) != NULL) {
        ++num_marcadores;
        ptr += 2; // Avançar o ponteiro após "%s"
    }

    // Verificar se o número de substituições é suficiente
    if (num_marcadores != num_substituicoes) {
        return NULL; // Erro: número de substituições não corresponde ao número de marcadores
    }

    // Alocar memória para o resultado final
    size_t resultado_tamanho = strlen(func()) + 1;
    char* resultado = malloc(resultado_tamanho);
    if (!resultado) return NULL;

    // Inicializar o resultado com a string HTML
    strcpy(resultado, func());

    // Substituir os marcadores
    for (size_t i = 0; i < num_substituicoes; ++i) {
        char marcador[3] = "%s";
        char* pos = strstr(resultado, marcador);
        if (pos) {
            size_t antes_marcador = pos - resultado;
            size_t depois_marcador = strlen(pos + 2);

                // Recriar a string resultado com o novo marcador substituído
                resultado = realloc(resultado, antes_marcador + strlen(substituicoes[i]) + depois_marcador + 1);
                if (!resultado) return NULL;
    
                memmove(pos + strlen(substituicoes[i]), pos + 2, depois_marcador + 1);
                memcpy(pos, substituicoes[i], strlen(substituicoes[i]));
        }
    }

    return resultado;
}
