
#include "../uniq.definitions_requirements.h"

CTextEngine *private_CEngine_Refactor_text_self(char *result, long num_replaceents, long num_marcadores){
    struct CTextEngine *self = (struct CTextEngine *)malloc(sizeof(CTextEngine));
    
    self->render_text = result;
    self->size = strlen(result);
    self->replaces_require = (long)num_replaceents;
    self->replacements = (long)num_marcadores;
    
    return self;
}



