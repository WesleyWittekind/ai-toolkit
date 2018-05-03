#include "pch.h"
#include "../shared/Essentials.h"


// Forward declare modules
#define declare_module(module, module_interface) class module_interface;
#include "../shared/ModuleList.hxx"
#undef declare_module

// TODO: Implment equivelent of Loader.cpp and Loader.h in all.sln

// Declare singleton pointers
#define declare_module(module, module_interface) \
extern "C" { module_interface * volatile g_p##module_interface = nullptr; }
#include "../shared/ModuleList.hxx"
#undef declare_module


// Declare global loading function
api_call void g_fLoadAllModules
(
// create an argument for each module
#define declare_module(module, module_interface) module_interface* p_##module_interface,
#include "../shared/ModuleList.hxx"
void*
)
{
#undef declare_module
// initialize each
#define declare_module(module, module_interface) g_p##module_interface = p_##module_interface;
#include "../shared/ModuleList.hxx"
#undef declare_module
}


// Declare swapping functions
#define declare_module(module, module_interface)              \
                                                              \
api_call void g_fSwap##module_interface(module_interface* p_s) \
{                                                             \
  g_p##module_interface = p_s;                                \
}

#include "../shared/ModuleList.hxx"
#undef declare_module
