
#include "../uniq.definitions_requirements.h"
#include <stdio.h>

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

    for (size_t i = 0; i < num_substituicoes && i <= num_marcadores; ++i) {
        char marcador[5] = "{%s}";
        char* pos = strstr(resultado, marcador);
        if (pos) {
            size_t antes_marcador = pos - resultado;
            size_t depois_marcador = strlen(pos + 4);

            resultado = realloc(resultado, antes_marcador + strlen(substituicoes[i]) + depois_marcador + 1);

            if(!resultado){return NULL;}
    
            memmove(pos + strlen(substituicoes[i]), pos + 4, depois_marcador + 1);
            memcpy(pos, substituicoes[i], strlen(substituicoes[i]));
        }
    }

        return private_CEngine_Refactor_text_self(resultado, num_substituicoes, num_marcadores);
}

CTextEngine *private_CEngine_text_replacement_by_links_name(const char* (*func)(void), LinkReplacement *links, const char **replacements){

    size_t num_marcadores = 0;
    size_t num_substituicoes = private_count_replaces(replacements);
    const char* ptr = func();
    while ((ptr = strstr(ptr, "{%s}")) != NULL) {
        ++num_marcadores;
        ptr += 4;
    }
    
    if (num_marcadores != num_substituicoes) {
        return NULL;
    }
    
    size_t num_links = 0;
    LinkReplacement *current = links;

    while (current) {
        num_links++;
        current = current->next;
    }

    size_t resultado_tamanho = strlen(func()) + 1;
    char* resultado = malloc(resultado_tamanho);
    if (!resultado) return NULL;

    strcpy(resultado, func());

    for (size_t i = 0; i < num_substituicoes && i <= num_marcadores; ++i) {
        char marcador[5] = "{%s}";
        char* pos = strstr(resultado, marcador);
        if (pos) {
            size_t antes_marcador = pos - resultado;
            size_t depois_marcador = strlen(pos + 4);

            resultado = realloc(resultado, antes_marcador + strlen(replacements[i]) + depois_marcador + 1);

            if(!resultado){return NULL;}
    
            memmove(pos + strlen(replacements[i]), pos + 4, depois_marcador + 1);
            memcpy(pos, replacements[i], strlen(replacements[i]));
        }
    }


    current = links;
    while (current) {
        char marcador[256];
        snprintf(marcador, sizeof(marcador), "{{%s}}", current->name);
        char* pos = strstr(resultado, marcador);
        if (pos) {
            size_t antes_marcador = pos - resultado;
            size_t depois_marcador = strlen(pos + strlen(marcador));

            resultado = realloc(resultado, antes_marcador + strlen(current->value) + depois_marcador + 1);
            if (!resultado) return NULL;

            memmove(pos + strlen(current->value), pos + strlen(marcador), depois_marcador + 1);
            memcpy(pos, current->value, strlen(current->value));
        }
        current = current->next;
    }

    return NULL;
}



