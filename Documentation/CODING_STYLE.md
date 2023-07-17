# Coding Standards For Riff.

### **Riff Uses Our Own Coding Style To Maintain The Code Base And It Will Help Upcoming Developers To Get Adopt To Our Environment**

## **Writing an header**:
- Right ✔️
```cpp
#pragma once

#include <somekindaheader.h>

namespace SomeKindaProgram 
{
    class SomeKinda
    {
    public:
        ~SomeKinda();
    private:
        bool m_status { true };
        int buffer_flow { 0 };
    }
}

using SomeKindaProgram::SomeKinda; // if your gonna use this compoenet globally better call it on the bottom of the file.
```

- Wrong ⨉
```cpp
#ifndef _YOUR_SOMEKINDA_HEADER_H
#define _YOUR_SOMEKINDA_HEADER_H

namespace SomeKindaProgram {
class SomeKinda {
public:
    ~SomeKinda();
    bool m_status { true };

protected:
    int buffer_flow { 0 };
}
}

#endif // _YOUR_SOMEKINDA_HEADER_H
```

## **Writing An C++ Program**:
- Right ✔️
```cpp
#include <somekindaprogram.h>

namespace SomeKindaProgram 
{
    auto myCore(SomeKinda kinda) 
    {  
        kinda.m_status();
    }
}
```

- Wrong ⨉
```cpp
#include "somekindaprogram.h"

auto myCore(SomeKinda kinda) {
kinda.m_status();
}
```