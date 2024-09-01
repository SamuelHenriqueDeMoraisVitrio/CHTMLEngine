
#include "../uniq.definitions_requirements.h"

CEngineNamespace new_CEngineNamespace(){
  CEngineNamespace self = {0};
 
  self.CText = private_new_CEngineText();

  return self;
}

