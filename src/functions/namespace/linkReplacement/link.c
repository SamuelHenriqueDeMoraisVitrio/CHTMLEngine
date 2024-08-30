
#include "../uniq.definitions_requirements.h"

LinkReplacement *private_create_link_replacement(const char *name, const char *value) {
    LinkReplacement *new_link = (LinkReplacement *)malloc(sizeof(LinkReplacement));
    new_link->name = strdup(name);
    new_link->value = strdup(value);
    new_link->next = NULL;
    return new_link;
}



