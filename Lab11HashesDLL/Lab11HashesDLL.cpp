// Lab11HashesDLL.cpp : Defines the exported functions for the DLL.
//

#include "framework.h"
#include "Lab11HashesDLL.h"


// This is an example of an exported variable
LAB11HASHESDLL_API int nLab11HashesDLL=0;

// This is an example of an exported function.
LAB11HASHESDLL_API int fnLab11HashesDLL(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
CLab11HashesDLL::CLab11HashesDLL()
{
    return;
}
