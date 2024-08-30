#ifndef PRIVATE_CTEXTENGINE_ONE_C
#define PRIVATE_CTEXTENGINE_ONE_C

#include "definitions.c"

#endif //PRIVATE_CTEXTENGINE_ONE_C

CEngineNamespace engine;

CreateTextInEngine(home,
  <html>
    <head>
    </head>
    <body>
      <h1>{%s}</h1>
      <p>{%s}</p>
      <p>{%s}</p>
    </body>
  </html>
);

void create_html(){

  const char *replacements[] = {
    "Hello Word",
    "Bom dia",
    "Teste",
    NULL
  };

  CTextEngine *home_formated = engine.new_CTextEngine(home, replacements);

  printf("\n\tTexto:\n%s\n\n\ttamanho: %ld\n", home_formated->render_text, home_formated->size);
  printf("\n\tRequerimentos: %ld\n Quantidade_De_Opções: %ld\n", home_formated->replaces_require, home_formated->replacements);

  engine.free_CText(home_formated);

}

int main(){

  engine = new_CEngineNamespace();

  create_html();

  return 0;
}
