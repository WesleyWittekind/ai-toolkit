/*  Author: Wesley Wittekind
 *  Date:   5/1/2018
 *  Desc:   General purpose allocator that manages memory and
 *  gives back handles to the allocated memory
 */

class Handle;

class I_Allocator
{
public:
  virtual ~I_Allocator() = default;



};

#pragma once
class DefaultAllocator : public I_Allocator
{
public:
  DefaultAllocator();
  virtual ~DefaultAllocator();


private:

};

