
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para armazenar substituições baseadas em nomes
typedef struct LinkReplacement {
    char *name;
    char *value;
  struct LinkReplacement *next;
} LinkReplacement;

// Estrutura para armazenar o texto formatado
typedef struct CTextEngine {
    char *render_text;
    size_t size;
    long replaces_require;
    long replacements;
} CTextEngine;

// Função para criar uma nova substituição baseada em nome
LinkReplacement *create_link_replacement(const char *name, const char *value) {
    LinkReplacement *new_link = (LinkReplacement *)malloc(sizeof(LinkReplacement));
    new_link->name = strdup(name);
    new_link->value = strdup(value);
    new_link->next = NULL;
    return new_link;
}

// Função para adicionar uma nova substituição à lista
void add_link_replacement(LinkReplacement **head, const char *name, const char *value) {
    LinkReplacement *new_link = create_link_replacement(name, value);
    new_link->next = *head;
    *head = new_link;
}

// Função para liberar a memória da lista de substituições
void free_link_replacements(LinkReplacement *head) {
    LinkReplacement *temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp->name);
        free(temp->value);
        free(temp);
    }
}

// Função para contar o número de substituições esperadas
size_t private_count_replaces(const char **substituicoes) {
    size_t count = 0;
    while (substituicoes[count] != NULL) {
        count++;
    }
    return count;
}

// Função para substituir marcadores e substituições baseadas em nomes
CTextEngine *private_CHtmlEngine_text_replacement(const char* (*func)(void), LinkReplacement *links) {
    CTextEngine *self = (CTextEngine *)malloc(sizeof(CTextEngine));

    size_t num_substituicoes = 0;
    const char* ptr = func();
    while ((ptr = strstr(ptr, "{%s}")) != NULL) {
        ++num_substituicoes;
        ptr += 4;
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

    // Substituições baseadas em nome
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

    self->render_text = resultado;
    self->size = strlen(resultado);
    self->replaces_require = (long)num_substituicoes;
    self->replacements = (long)num_links;

    return self;
}

// Macro para criar funções de texto
#define CreateTextInEngine(name, ...) \
    const char* name(void) { \
        return #__VA_ARGS__; \
    }

// Função para criar uma nova instância de CTextEngine
CTextEngine *new_CTextEngine(const char* (*func)(void), LinkReplacement *links) {
    return private_CHtmlEngine_text_replacement(func, links);
}

// Função para liberar a memória do CTextEngine
void free_CTextEngine(CTextEngine *engine) {
    if (engine) {
        free(engine->render_text);
        free(engine);
    }
}

// Exemplo de função de texto usando a macro
CreateTextInEngine(home,
    <html>
      <head></head>
      <body>
        <h1>{{nome}}</h1>
      </body>
    </html>
);

int main() {
    // Cria substituições baseadas em nomes
    LinkReplacement *links = NULL;
    add_link_replacement(&links, "nome", "Samuel");

    // Cria o engine com substituições baseadas em nomes
    CTextEngine *home_formated = new_CTextEngine(home, links);

    if (home_formated) {
        printf("%s\n", home_formated->render_text);
        printf("Tamanho: %zu\n", home_formated->size);
        printf("Requerimentos: %ld\nQuantidade_De_Opções: %ld\n", home_formated->replaces_require, home_formated->replacements);

        free_CTextEngine(home_formated);
    } else {
        printf("Erro ao criar CTextEngine.\n");
    }

    free_link_replacements(links);

    return 0;
}
