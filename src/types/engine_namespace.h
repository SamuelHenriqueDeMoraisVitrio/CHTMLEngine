#include "uniq.imports.h"

#ifndef PRIVATE_TYPES_CHTML_ENGINE
#define PRIVATE_TYPES_CHTML_ENGINE

typedef struct CHtmlEngineNamespace{

  char *(*NewTextEngine)(const char* (*func)(void), const char* substituicoes[], size_t num_substituicoes);

}CHtmlEngineNamespace;

#endif // !PRIVATE_TYPES_CHTML_ENGINE
