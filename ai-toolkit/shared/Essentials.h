/*  Author: Wesley Wittekind
*   Date:   5/2/2018
*   Desc:   Generic module externing and accessing simplification macros
*   Credits: Closely modeled on a system developed by the DigiPen game team Redacted for their 
*   Junior project Outlier
*/

/*
 * The use of include guards instead of pragma once on this file is intentional
 * as it will be included in multiple projects with different include paths. 
 * This can lead to multiple defintions and errors
 */
#ifndef ESSENTIALS_H
#define ESSENTIALS_H

// Enforces interfaces to contain no implementation
#define abstract_class struct __declspec(novtable)

// exports the given function
#ifdef _WIN32
#define api_call extern "C" __declspec(dllexport)
#else
#define api_call extern "C"
#endif

// provides an access point for the given exported class
#define expose_module_ptr(interface_name) \
extern "C" { extern interface_name* volatile g_p##interface_name; }

// constructs a singleton version of the given class
#define expose_module_getter_constructor(implementation_name, interface_name) \
api_call interface_name* Get##interface_name()                                \
{                                                                             \
  static interface_name* ptr = new implementation_name();                     \
  g_p##interface_name = ptr;                                                  \
  return ptr;                                                                 \
}

// cleans up the given instance and clears the pointer
#define expose_destroy_module(implementation_name, interface_name)  \
api_call void Destroy##interface_name()                             \
{                                                                   \
  delete g_p##interface_name;                                       \
  g_p##interface_name = nullptr;                                    \
}

/* module construction
 * The last line of this macro declares the actual ptr to the module
 */
#define expose_module_implementation(implementation_name, interface_name) \
  expose_module_getter_constructor(implementation_name, interface_name)   \
  expose_destroy_module(implementation_name, interface_name)

#include "Module.h"
// macro that ensures proper module interface declaration
#define declare_module_interface(module_name) \
abstract_class module_name;                   \
abstract_class module_name : public Module

#endif
