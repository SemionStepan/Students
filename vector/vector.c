#include <stdlib.h>
#include "vector.h"

Vector* initVector(uint fullLength, uint delta)
{
    Vector* pNewVector = malloc(sizeof(Vector));
    if(pNewVector)
    {
        pNewVector->_fullLength = fullLength;
        pNewVector->_usedLength = 0;
        pNewVector->_delta = delta;
        pNewVector->_pElements = malloc(sizeof(Element*) * pNewVector->_fullLength);
        if(!pNewVector->_pElements)
        {
            free(pNewVector);
            return NULL;
        }
     }
  return pNewVector;
}

void deleteVector(Vector* pVector)
{
    free(pVector->_pElements);
    free(pVector);
}

Element* appendVector(Vector* pVector, Element* pElement)
{
    if(pVector->_usedLength > pVector->_fullLength)
    {
        pVector->_fullLength += pVector->_delta;
        pVector->_pElements = realloc(pVector->_pElements, pVector->_fullLength * sizeof(Element*));
    }
    pVector->_pElements[pVector->_usedLength] = pElement;
    pVector->_usedLength++;

  return pVector->_pElements[pVector->_usedLength];
}

//Element* insertToVector(Vector*, uint, Element*)
//{

//}

Element* removeFromVector(Vector* pVector, uint number)
{
    Element* pTmpElement = pVector->_pElements[number];
    for(uint count = number; count < pVector->_usedLength; count++)
    {
        pVector->_pElements[count] = pVector->_pElements[count+1];
    }

    pVector->_usedLength--;

  return pTmpElement;
}

//Element* atVector(Vector*, uint)
//{

//}

Vector* sortVector(Vector* pVector, int (*compare)(Element* pElement1, Element* pElement2))
{
    bool changed = true;
    while(!changed)
    {
        changed = false;
        for(uint j = 0; j < pVector->_usedLength - 1; j++)
        {
            if(compare(pVector->_pElements[j], pVector->_pElements[j+1]) > 0)
            {
                swap(pVector->_pElements[j], pVector->_pElements[j+1]);
                changed = true;
            }
        }
    }
  return pVector;
}

void swap(Element* ptr1, Element* ptr2)
{
    Element* tmp = ptr1;

    *ptr1 = *ptr2;
    *ptr2 = *tmp;
}
