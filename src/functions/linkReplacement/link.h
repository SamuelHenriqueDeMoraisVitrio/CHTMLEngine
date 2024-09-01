
#include "../uniq.declarations_requirements.h"
#include <stdbool.h>

void private_add_link_replacement(CTextEngine *self, const char *name, void *value, short type);

void private_free_link_replacements(CTextEngine *self);

void private_link_name_by_char(CTextEngine *self, const char *name, const char *value);

void private_link_name_by_integer(CTextEngine *self, const char *name, long value);

void private_link_name_by_float(CTextEngine *self, const char *name, double value);

void private_link_name_by_bool(CTextEngine *self, const char *name, bool value);
