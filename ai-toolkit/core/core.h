#pragma once
#include "../shared/Essentials.h"

declare_module_interface(Core)
{
  virtual void Required() = 0;

};

expose_module_ptr(Core)

