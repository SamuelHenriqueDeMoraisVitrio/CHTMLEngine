
#include "../engine_text.h"

#ifndef PRIVATE_TYPES_NAMESPACE_CENGINENAMESPACE
#define PRIVATE_TYPES_NAMESPACE_CENGINENAMESPACE

typedef struct CEngineNamespace{

  CTextEngine *(*new_CTextEngine)(const char *(*func)(void), const char **replaces);
  void (*add_link_replacement)(LinkReplacement **head, const char *name, const char *value);
  void (*free_CText)(CTextEngine *self);

}CEngineNamespace;

#endif // !PRIVATE_TYPES_NAMESPACE_CENGINENAMESPACE

