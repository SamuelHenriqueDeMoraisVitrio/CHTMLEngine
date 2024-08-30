
#ifndef PRIVATE_TYPES_CTEXTENGINE_RENDER_TEXT
#define PRIVATE_TYPES_CTEXTENGINE_RENDER_TEXT

#include "linkReplacement.h"
typedef struct CTextEngine{

  char *render_text;
  long size;
  long replaces_require;
  long replacements;
  LinkReplacement *self_link_by_name;

}CTextEngine;

#endif //PRIVATE_TYPES_CTEXTENGINE_RENDER_TEXT
