#include <stddef.h> // Para size_t
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Macro para definir o bloco de código HTML com marcadores
#define TRANSFORMACAO(name, ...) \
    const char* name(void) { \
        return #__VA_ARGS__; \
    }

// Função para substituir os marcadores na string HTML
char* substituir_marcadores(const char*(*func)(void), const char* substituicoes[], size_t num_substituicoes);

// Função para substituir marcadores (%s) na string HTML
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

#define sla 1

// Usar a macro TRANSFORMACAO para definir o bloco de HTML
TRANSFORMACAO(HTML_ENGINE,
    <html>
    <body>
        <h1>"Hello, World!"</h1>
        %s
        %s
        %s
    </body>
    </html>

    %s
);

TRANSFORMACAO(HTML_TESTE, 
    <html>
    <body>
              <h1>Hello Word</h1>
              <h2>Bem vindo</h2>
    </body>
    </html>
);

int main() {
    // Definir os conteúdos para substituir os marcadores
    const char* substituicoes[] = {
        "<h2>Hello, from the first new content!</h2>",
        "<p>Hello, from the second new content!</p>",
        "<div>Hello, from the third new content!</div>",
        HTML_TESTE()
    };
    
    size_t num_substituicoes = sizeof(substituicoes) / sizeof(substituicoes[0]);

    // Construir e imprimir o HTML final
    char* html_string = substituir_marcadores(HTML_ENGINE, substituicoes, num_substituicoes);
    char *html_string2 = substituir_marcadores(HTML_TESTE, NULL, 0);
    if (html_string) {
        printf("%s", html_string);
        free(html_string2);
        free(html_string);
    } else {
        printf("Erro ao alocar memória para a construção do HTML ou número de substituições incorreto.\n");
    }

    return 0;
}


