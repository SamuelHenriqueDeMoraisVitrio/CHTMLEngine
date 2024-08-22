#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Macro para definir o bloco de código
#define TRANSFORMACAO(name, ...) \
    const char* name(void) { \
        return #__VA_ARGS__; \
    }

// Função para renderizar o código em uma string
char* render_in_char(const char* (*func)(void)) {
    // Obter a string retornada pela função
    const char* str = func();
    
    // Alocar memória para a string (incluindo o terminador nulo)
    char* result = (char*)malloc(strlen(str) + 1);
    if (!result) {
        return NULL; // Falha na alocação de memória
    }
    
    // Copiar a string para o buffer
    strcpy(result, str);
    
    return result;
}
    // Usar a macro TRANSFORMACAO para definir o bloco de HTML
    TRANSFORMACAO(HTML_ENGINE,
        <html>
        <body>
            <h1>Hello, World!</h1>
        </body>
        </html>
    );
int main() {


    // Renderizar e imprimir o bloco de código
    char* html_string = render_in_char(HTML_ENGINE);
    if (html_string) {
        printf("%s", html_string);
        free(html_string);
    } else {
        printf("Erro ao alocar memória para a renderização.\n");
    }

    return 0;
}

