
#include "../engine_text.h"

#ifndef PRIVATE_TYPES_NAMESPACE_CTEXT_H
#define PRIVATE_TYPES_NAMESPACE_CTEXT_H

typedef struct CText{

  CTextEngine *(*new_CTextEngine)(const char *(*func)(void));
  void (*add_link_name_by_string)(CTextEngine *self, const char *name, const char *value);
  void (*add_link_name_by_integer)(CTextEngine *self, const char *name, long value);
  void (*add_link_name_by_float)(CTextEngine *self, const char *name, double value);
  void (*add_link_name_by_bool)(CTextEngine *self, const char *name, bool value);
  void (*add_replacements)(CTextEngine *self, const char **replacements);
  void (*render_text)(CTextEngine *self);
  void (*free_CText)(CTextEngine *self);


}CText;


#endif // !PRIVATE_TYPES_NAMESPACE_CTEXT_H
