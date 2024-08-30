#include <stdio.h>

#define CreateTextInEngine(name, content) \
    const char* name(void) { \
        static const char* result; \
        result = content; \
        return result; \
    }

#define TEXT_BLOCK(...) #__VA_ARGS__

#define VAR(name) name
#define IF(condition, true_branch, false_branch) ((condition) ? true_branch : false_branch)

CreateTextInEngine(home, TEXT_BLOCK(
    <html>
    <head>
    </head>
    <body>
      <h1>{VAR(nome)}</h1>
      <p>{VAR(sobrenome)}</p>
      <p>{{IF(VAR(nome) == VAR(sobrenome), VAR(nome), "Nome e sobrenome diferentes")}}</p>
    </body>
    </html>
));

int main() {
    const char *nome = "Samuel";
    const char *sobrenome = "Henrique";
    const char *outro_nome = "vitrio";

    // Aqui, você usaria home() para obter o template com as substituições aplicadas.
    printf("%s\n", home());

    return 0;
}
