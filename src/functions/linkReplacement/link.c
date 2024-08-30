
#include "../uniq.definitions_requirements.h"




void add_link_replacement(LinkReplacement **head, const char *name, const char *value) {
    LinkReplacement *new_link = create_link_replacement(name, value);
    new_link->next = *head;
    *head = new_link;
}

void free_link_replacements(LinkReplacement *head) {
    LinkReplacement *temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp->name);
        free(temp->value);
        free(temp);
    }
}



