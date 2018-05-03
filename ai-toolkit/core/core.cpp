#include "pch.h"
#include "core.h"
#include <iostream>

class DefaultCore : public Core
{
public:
  ~DefaultCore() override = default;
  virtual void Required() override;;
};

void DefaultCore::Required()
{

  std::cout << "Made it work?" << std::endl;
}

expose_module_implementation(DefaultCore, Core);
