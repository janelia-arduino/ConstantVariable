// ----------------------------------------------------------------------------
// ConstantVariable.cpp
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#include "ConstantVariable.h"

#ifdef __AVR__

#else

size_t ConstantString::length() const
{
  return str_.length();
}

char *ConstantString::copy(char *to, int size, int offset) const
{
  if (size == -1)
  {
    // to account for seemingly flawed behavior in substring method
    if (str_.length() > 0)
    {
      str_.substring(offset).toCharArray(to,(str_.length() + 1 - offset));
    }
    else
    {
      str_.toCharArray(to,(str_.length() + 1 - offset));
    }
  }
  else
  {
    // to account for seemingly flawed behavior in substring method
    if (str_.length() > 0)
    {
      str_.substring(offset).toCharArray(to,size);
    }
    else
    {
      str_.toCharArray(to,size);
    }
  }
  return to;
}

char ConstantString::operator[](int index) const
{
  return str_.charAt(index);
}

void ConstantString::print(Print &stream) const
{
  stream.print(str_);
}

#endif
