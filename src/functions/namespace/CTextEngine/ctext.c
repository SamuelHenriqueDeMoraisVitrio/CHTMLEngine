
#include "../uniq.definitions_requirements.h"

CText private_new_CEngineText(){
  CText self = {0};

  self.new_CTextEngine = private_CEngine_Text_new_struct;

  self.add_link_name_by_integer = private_link_name_by_integer;
  self.add_link_name_by_string = private_link_name_by_char;
  self.add_link_name_by_float = private_link_name_by_float;
  self.add_link_name_by_bool = private_link_name_by_bool;
  self.add_replacements = private_add_replacements_in_CTextEngine;
  
  self.render_text = private_CEngine_text_replacement_by_links_name;
  self.free_CText = private_free_TextEngine;

  return self;
}

CTextEngine *private_CEngine_Text_new_struct(const char *(*func)(void)){
  CTextEngine *self = (CTextEngine *)malloc(sizeof(CTextEngine));
  
  self->text = func();
  self->size = strlen(func());
  self->link_name = NULL;
  
  return self;
}
