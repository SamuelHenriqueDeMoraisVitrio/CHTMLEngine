
#include "../uniq.definitions_requirements.h"

void private_free_TextEngine(CTextEngine *self){
    if(self){
        if(self->render_text){
            free(self->render_text);
        }
        free(self);
    }
}

size_t private_count_replaces(const char **substituicoes) {
    size_t count = 0;

    // Conta até encontrar um ponteiro NULL
    while (substituicoes[count] != NULL) {
        count++;
    }

    return count;
}

CTextEngine *private_CHtmlEngine_text_replacement(const char* (*func)(void), const char **substituicoes) {
    struct CTextEngine *self = (struct CTextEngine *)malloc(sizeof(CTextEngine));

    size_t num_marcadores = 0;
    size_t num_substituicoes = private_count_replaces(substituicoes);
    const char* ptr = func();
    while ((ptr = strstr(ptr, "{%s}")) != NULL) {
        ++num_marcadores;
        ptr += 4;
    }

    if (num_marcadores != num_substituicoes) {
        return NULL;
    }

    size_t resultado_tamanho = strlen(func()) + 1;
    char* resultado = malloc(resultado_tamanho);
    if (!resultado) return NULL;

    strcpy(resultado, func());

    for (size_t i = 0; i < num_substituicoes; ++i) {
        char marcador[3] = "%s";
        char* pos = strstr(resultado, marcador);
        if (pos) {
            size_t antes_marcador = pos - resultado;
            size_t depois_marcador = strlen(pos + 2);

                resultado = realloc(resultado, antes_marcador + strlen(substituicoes[i]) + depois_marcador + 1);
                if (!resultado) return NULL;
    
                memmove(pos + strlen(substituicoes[i]), pos + 2, depois_marcador + 1);
                memcpy(pos, substituicoes[i], strlen(substituicoes[i]));
        }
    }

    self->render_text = resultado;
    self->size = sizeof(resultado);
    self->replaces_require = (long)num_substituicoes;
    self->replacements = (long)num_marcadores;

    return self;
}

