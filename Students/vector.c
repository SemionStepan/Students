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
        pNewVector->_pElements = malloc(pNewVector->_fullLength * sizeof(Element*));
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

Element* appendToVector(Vector* pVector, Element* pElement)
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

Element* insertToVector(Vector* pVector, uint number, Element* pElement)
{
    if(number > pVector->_usedLength)
    {
        return NULL;
    }

    if(pVector->_usedLength >= pVector->_fullLength)
    {
        pVector->_fullLength += pVector->_delta;
        pVector->_pElements = realloc(pVector->_pElements, pVector->_fullLength * sizeof(Element*));
    }
    pVector->_usedLength++;

    uint count = pVector->_usedLength;
    for(; count > number; count--)
    {
        pVector->_pElements[count] = pVector->_pElements[count - 1];
    }

    pVector->_pElements[count] = pElement;

  return pElement;
}

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

Element* atFromVector(Vector* pVector, uint number)
{
    if(number > pVector->_usedLength)
    {
        return NULL;
    }
    else
    {
        return pVector->_pElements[number];
    }
}

Vector* sortVector(Vector* pVector, int (*compare)(Element* pElement1, Element* pElement2))
{
    _bool changed = _true;
    while(!changed)
    {
        changed = _false;
        for(uint j = 0; j < pVector->_usedLength - 1; j++)
        {
            if(compare(pVector->_pElements[j], pVector->_pElements[j+1]) > 0)
            {
                Element *p = pVector->_pElements[j];
                pVector->_pElements[j] = pVector->_pElements[j+1];
                pVector->_pElements[j+1] = p;
                changed = _true;
            }
        }
    }
  return pVector;
}

uint lengthVector(Vector* pVector)
{
  return pVector->_usedLength;
}

Vector* plusVector(Vector* vector1, Vector* vector2)
{
    vector1->_fullLength = vector1->_usedLength + vector2->_usedLength + vector1->_delta;
    if(!(vector1->_pElements = realloc(vector1->_pElements, vector1->_fullLength * sizeof(Element*))))
    {
        return NULL;
    }

    for(uint count = 0; count < vector2->_usedLength; count++)
    {
        vector1->_pElements[vector1->_usedLength++] = vector2->_pElements[count];
    }
  return vector1;
}

