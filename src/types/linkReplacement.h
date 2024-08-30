
#ifndef PRIVATE_TYPES_LINKREPLACEMENTS_H
#define PRIVATE_TYPES_LINKREPLACEMENTS_H

typedef struct LinkReplacement {
    char *name;
    char *value;
    struct LinkReplacement *next;
} LinkReplacement;

#endif
