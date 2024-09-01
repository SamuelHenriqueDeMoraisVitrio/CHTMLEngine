
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void private_return_sem_free(char *str, char *new_str_cpy){
  if (str == NULL) {
      return;
  }

  char new_str[strlen(str) + 1];
  strcpy(new_str, str);
  strcpy(new_str_cpy, new_str);

  free(str);

}

int main(){

  char *string = (char*)malloc(100);
  strcpy(string, "Exemplo de string");

  char *sla;
  private_return_sem_free(string, sla);

  printf("\n\t%s\n\n", sla);

  return 0;
}
