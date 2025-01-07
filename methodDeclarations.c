#ifndef ASSINGMENT2_LIBRARY_H
#define ASSINGMENT2_LIBRARY_H
#include <stddef.h>
#include <stdbool.h>


typedef struct {//defining a new data type - GenSet_t that has the following elements:
   void **elements;//array to store set elements
   bool type;//encoded type of the set: if false then set contains integers, if true then set contains strings;
   long long size;//current size of the set
} GenSet_t;


GenSet_t* initSet(char *typename);//function initializing a new, empty set of the given type ("int" or "string")


void deinitSet(GenSet_t *set);//function destroying an existing given set and freeing memory space


void addToSet(GenSet_t *set, void* element);//function adding given element to the given set


void displaySet(GenSet_t *set);//function displaing all elements of the given set


GenSet_t* unionSet(GenSet_t *set1, GenSet_t *set2);//function creating a new set - union of two given sets


GenSet_t* intersectSet(GenSet_t *set1, GenSet_t *set2);//function creating a new set - intersection of two given sets


GenSet_t* diffSet(GenSet_t *set1, GenSet_t *set2);//function creating a new set - difference of two given sets (set1 \ set2)


long long countSet(GenSet_t *set);//function returning number of elements in the given set


bool isSubsetSet(GenSet_t *set1, GenSet_t *set2);//function returning if the first given set is a subset of the second given set


bool isEmptySet(GenSet_t *set);//function returning if the given set is empty


#endif //ASSINGMENT2_LIBRARY_H
