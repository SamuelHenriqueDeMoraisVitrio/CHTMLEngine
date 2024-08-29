
#include "../uniq.definitions_requirements.h"

CEngineNamespace new_CEngineNamespace(){
  CEngineNamespace self = {0};

  self.new_CTextEngine = private_CHtmlEngine_text_replacement;
  self.free_CText = private_free_TextEngine;

  return self;
}

