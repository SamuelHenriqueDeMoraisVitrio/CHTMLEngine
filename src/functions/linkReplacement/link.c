
#include "../uniq.definitions_requirements.h"
#include <stdio.h>



void private_add_link_replacement(CTextEngine *self, const char *name, void *value, short type){
    
    LinkReplacement *new_link;

    
    switch(type) {
        case CENGINE_TYPE_BY_LINK_NAME_STRING:
            new_link = private_create_link_replacement(name, (const char *)value);
            break;

        case CENGINE_TYPE_BY_LINK_NAME_INTEGER: {
            long val = *((long *)value);
            int tamanho = snprintf(NULL, 0, "%ld", val) + 1;
            char *str_value = malloc(tamanho * sizeof(char));
            if (str_value == NULL) {
                str_value = "";    
            }
            snprintf(str_value, tamanho, "%ld", val);
            new_link = private_create_link_replacement(name, str_value);
            
            free(str_value);
            break;
        }

        case CENGINE_TYPE_BY_LINK_NAME_FLOAT: {
            double val = *((double *)value);
            long tamanho = snprintf(NULL, 0, "%.2f", val) + 1;
            char *str_value = malloc(tamanho * sizeof(char));
            if (str_value == NULL) {
                str_value = "";
            }
            snprintf(str_value, tamanho, "%.2f", val);
            new_link = private_create_link_replacement(name, str_value);

            free(str_value);
            break;
        }

        case CENGINE_TYPE_BY_LINK_NAME_BOOL:
            new_link = private_create_link_replacement(name, *((bool *)value)?"true":"false");
            break;

        default:
            new_link = private_create_link_replacement(name, (const char *)value);
    }



    LinkReplacement **head = &self->link_name;
    new_link->next = *head;
    *head = new_link;
}

void private_free_link_replacements(CTextEngine *self) {
    LinkReplacement *temp;
    while (self->link_name) {
        temp = self->link_name;
        self->link_name = self->link_name->next;
        free(temp->name);
        free(temp->value);
        free(temp);
    }
}

void private_link_name_by_char(CTextEngine *self, const char *name, const char *value){
    private_add_link_replacement(self, name, (void *)value, CENGINE_TYPE_BY_LINK_NAME_STRING);
}

void private_link_name_by_integer(CTextEngine *self, const char *name, long value){
    private_add_link_replacement(self, name, &value, CENGINE_TYPE_BY_LINK_NAME_INTEGER);
}

void private_link_name_by_float(CTextEngine *self, const char *name, double value){
    private_add_link_replacement(self, name, &value, CENGINE_TYPE_BY_LINK_NAME_FLOAT);
}

void private_link_name_by_bool(CTextEngine *self, const char *name, bool value){
    private_add_link_replacement(self, name, &value, CENGINE_TYPE_BY_LINK_NAME_BOOL);
}



