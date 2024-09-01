
#include "../uniq.definitions_requirements.h"



void private_free_TextEngine(CTextEngine *self){
    if(self){
        private_free_link_replacements(self);
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

size_t private_umount_markes(const char *ptr){

    size_t num_marcadores = 0;

    while ((ptr = strstr(ptr, "{%s}")) != NULL) {
        ++num_marcadores;
        ptr += 4;
    }

    return num_marcadores;

}
/*
CTextEngine *private_CHtmlEngine_text_replacement(const char* (*func)(void), const char **substituicoes) {

    size_t num_substituicoes = private_count_replaces(substituicoes);

    size_t num_marcadores = private_umount_markes(func());

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
*/
char *private_CEngine_text_replacement_by_links_name(CTextEngine *self){

    size_t num_marcadores = private_umount_markes(self->text);
    size_t num_substituicoes = private_count_replaces(self->replacements);
    
    /*
    if (num_marcadores != num_substituicoes) {
        return NULL;
    }
    */

    size_t num_links = 0;
    LinkReplacement *current = self->link_name;

    while (current) {
        num_links++;
        current = current->next;
    }

    size_t resultado_tamanho = strlen(self->text) + 1;
    char* resultado = malloc(resultado_tamanho);
    if (!resultado){

        free(resultado);
        return NULL;
    }

    strcpy(resultado, self->text);

    for (size_t i = 0; i < num_substituicoes && i <= num_marcadores; ++i) {
        char marcador[5] = "{%s}";
        char* pos = strstr(resultado, marcador);
        if (pos) {
            size_t antes_marcador = pos - resultado;
            size_t depois_marcador = strlen(pos + 4);

            resultado = realloc(resultado, antes_marcador + strlen(self->replacements[i]) + depois_marcador + 1);

            if(!resultado){
                free(resultado);
                return NULL;
            }
    
            memmove(pos + strlen(self->replacements[i]), pos + 4, depois_marcador + 1);
            memcpy(pos, self->replacements[i], strlen(self->replacements[i]));
        }
    }


    current = self->link_name;
    while (current) {
        char marcador[256];
        snprintf(marcador, sizeof(marcador), "{{%s}}", current->name);
        char* pos = strstr(resultado, marcador);
        if (pos) {
            size_t antes_marcador = pos - resultado;
            size_t depois_marcador = strlen(pos + strlen(marcador));

            resultado = realloc(resultado, antes_marcador + strlen(current->value) + depois_marcador + 1);
            if (!resultado){
                free(resultado);
                return NULL;
            }

            memmove(pos + strlen(current->value), pos + strlen(marcador), depois_marcador + 1);
            memcpy(pos, current->value, strlen(current->value));
        }
        current = current->next;
    }


    return resultado;
}



