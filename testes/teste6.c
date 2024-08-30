
#include "dependencies/lib_engine.h"

CEngineNamespace engine;

CreateTextInEngine(home,
    <html>
    <head>
    </head>
    <body>
      <h1>{{nome}}</h1>
    </body>
    </html>
);

int main() {


    engine = new_CEngineNamespace();

    const char *meuNome = "Samuel";
    
    CTextEngine *home_formated = engine.new_CTextEngine(home, NULL);

    home_formated->new_link("nome", meuNome);
    //ou
    engine.new_link(home_formated, "nome", meuNome);

    printf("%s\n", home_formated->render_text());

    engine.free_text(home_formated);

    return 0;
}

Saida:

<html> <head> </head> <body> <h1>Samuel</h1> </body> </html>


