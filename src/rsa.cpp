#include "includes/rsa.hpp"

RSAObject RSAObject(mpz_class data[])
{
    for (int i = 0; i < 8; ++i) 
    { 
        pArray[i]->data = data[i];
        pArray[i]->letter = cVarChars[i];
        pArray[i]->name = cVarNames[i];
    }
}