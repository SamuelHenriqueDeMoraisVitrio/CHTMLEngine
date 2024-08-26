
#ifndef PRIVATE_TYPES_CTEXTENGINE_RENDER_TEXT
#define PRIVATE_TYPES_CTEXTENGINE_RENDER_TEXT

typedef struct CTextEngine{

  char *render_text;
  long size;
  void (*free)(struct CTextEngine *self);

}CTextEngine;

#endif //PRIVATE_TYPES_CTEXTENGINE_RENDER_TEXT
