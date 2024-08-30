
#include "../uniq.declarations_requirements.h"

void private_free_TextEngine(CTextEngine *self);
size_t private_count_replaces(const char **substituicoes);
CTextEngine *private_CHtmlEngine_text_replacement(const char* (*func)(void), const char **substituicoes);
CTextEngine *private_CEngine_text_replacement_by_links_name(const char* (*func)(void), LinkReplacement *links, const char **replacements);




