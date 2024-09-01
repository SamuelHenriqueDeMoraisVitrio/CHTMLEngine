#ifndef PRIVATE_CTEXTENGINE_ONE_C
#define PRIVATE_CTEXTENGINE_ONE_C

#include "definitions.c"

#endif //PRIVATE_CTEXTENGINE_ONE_C

/*
CEngineNamespace engine;

CreateTextInEngine(HOME,
  <html>
    <head>
    </head>
    <body>
      <h1>{%s}</h1>
      <p>{%s}</p>
      <p>{%s}</p>
      <p>{{name}}</p>
    </body>
  </html>
);

void create_html(){

  const char *replacements[] = {
    "Hello Word",
    "Bom dia",
    NULL
  };
  
  CTextEngine *home = engine.CText.new_CTextEngine(HOME);

  engine.CText.add_replacements(home, replacements);

  engine.CText.add_link_name_by_string(home, "name", "Samuel");

  engine.CText.render_text(home);

  printf("\n\t%s\n\n", home->text_rederized);
  
  engine.CText.free_CText(home);
}

int main(){

  engine = new_CEngineNamespace();

  create_html();

  return 0;
}

*/
