
#include "engine.h"

CEngineNamespace eng;


AssembleEngine(texto_html, 
<html>
               <head>
               </head>
               <body>
                <h1>slaslasla</h1>
                #if 10 == 10
                  <h2>10 == 10</h2>
                #endif
                %s
               </body>
</html>
);

void cria(){
  const char *slaslaslasla[] = {"</Resto do html>"};
  CTextEngine *texto = eng.newCTextEngine(texto_html, slaslaslasla);
  char *html_formatado = texto.render_text();
  texto.free(texto);
}

int main(){
  
  eng = newCEngineNamespace();

  return 0;
}
