
#ifndef PRIVATE_TYPES_CTEXTENGINE_RENDER_TEXT
#define PRIVATE_TYPES_CTEXTENGINE_RENDER_TEXT

typedef struct CTextEngineText{

  char *render_text;
  long size;
  void (*free)(struct CTextEngineText *self);

}CTextEngineText;

#endif //PRIVATE_TYPES_CTEXTENGINE_RENDER_TEXT
