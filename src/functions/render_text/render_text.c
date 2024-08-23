
#include "../uniq.definitions_requirements.h"

void private_CTextEngineText_free(CTextEngineText *self) {
    if (self) {
        if (self->render_text) {
            free(self->render_text);
        }
        free(self);
    }
}

CTextEngineText *CTextEngine_render_text(const char* (*func)(void), const char* substituicoes[], size_t num_substituicoes) {
    CTextEngineText *self = {0};

    size_t num_marcadores = 0;
    const char* ptr = func();
    while ((ptr = strstr(ptr, "%s")) != NULL) {
        ++num_marcadores;
        ptr += 2;
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

    return self;
}

