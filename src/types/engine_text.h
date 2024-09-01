
#ifndef PRIVATE_TYPES_CTEXTENGINE_RENDER_TEXT
#define PRIVATE_TYPES_CTEXTENGINE_RENDER_TEXT

#include "linkReplacement.h"
typedef struct CTextEngine{

  long size;
  const char *text;
  LinkReplacement *link_name;
  const char **replacements;

}CTextEngine;

#endif //PRIVATE_TYPES_CTEXTENGINE_RENDER_TEXT
