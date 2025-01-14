#include "library.h"//implementing GenSet library and other libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


GenSet_t* initSet(char *typename) {//function initializing a new set that takes name of the type of the set ("int" or "string") as an argument
   GenSet_t *set = (GenSet_t*) malloc(sizeof(GenSet_t));//allocating memory for the set
   set->elements = (void*)malloc(sizeof(void*));
   set->size = 0;//setting size of the set to 0, because it's a new, empty set;
   if(strcmp(typename, "int") == 0) set->type = false;//setting type of the set to 0 if it is a set of integers and to 1 if it is a set of strings
   else if(strcmp(typename, "string") == 0) set->type = true;
   return set;//returning a new set ready to use
}
void deinitSet(GenSet_t *set) {//function destroying a given set by freeing the set's memory space
   free(set->elements);//freeing memory
   free(set);
}
void addToSet(GenSet_t *set, void* element) {//function adding a new given element to the given set
   for(int i = 0; i < set->size; i++) {//checking if new element is not repeated
       if((set->type == false && set->elements[i] == element) || (set->type == true && strcmp(set->elements[i], element) == 0)) return 0;
   }
   set->size++;//enlarging size of the set
   set->elements = realloc(set->elements, set->size * sizeof(void *));//allocating additional memory space
   set->elements[set->size - 1] = malloc(set->type == 0 ? sizeof(int) : sizeof(char[64]));
   set->elements[set->size - 1] = element;//assings given value to the empty element of the set
}
void displaySet(GenSet_t *set) {//function displaying all elements of a given set
   if(set->type == false) {//checking weather it is an integer or a string set
       for(int i = 0; i < set->size; i++) {//iterating and printing elements of the set
           printf("%d\n", set->elements[i]);
       }
   } else if(set->type == true) {//here previous operations are repeated
       for(int i = 0; i < set->size; i++) {
           printf("%s\n", set->elements[i]);
       }
   }
}
GenSet_t* unionSet(GenSet_t *set1, GenSet_t *set2) {//function making a new set - a union of two given sets
   if(set1->type != set2->type) {//checking if the data types of the sets align
       printf("operation impossible, different data types\n");
       return 0;
   }
   GenSet_t *unionn = initSet(set1->type == false ? "int" : "string");//initializing new set
   for(int i = 0; i < set1->size; i++) {//adding to the new set all elements of the first of the given sets
       addToSet(unionn, set1->elements[i]);
   }
   bool ifrepeat;
   for(int i = 0; i < set2->size; i++) {//adding to the new set all elements of the second of the given sets that are not repeated in the first set by iteration on every pair of elements
       ifrepeat = false;
       for(int j = 0; j < set1->size; j++) {
           if( (set1->type == false && set2->elements[i] == set1->elements[j]) || (set1->type == true && strcmp(set1->elements[j], set2->elements[i]) == 0) ) {
               ifrepeat = true;
               break;
           }
       }
       if (!ifrepeat) addToSet(unionn, set2->elements[i]);


   }
   return unionn;//returning a newly created union of two sets
}
GenSet_t* intersectSet(GenSet_t *set1, GenSet_t *set2) {//function making a new set - an intersection of two given sets
   if(set1->type != set2->type) {//checking if the data types of the sets align
       printf("operation impossible, different data types\n");
       return 0;
   }
   GenSet_t *intersection = initSet(set1->type == false ? "int" : "string");//initializing new set
   for(int i = 0; i < set1->size; i++) {//iterating on every pair of elements - if two elements are the same, adding them to the new set
       for(int j = 0; j < set2->size; j++) {
           if( (set1->type == false && set1->elements[i] == set2->elements[j]) || (set1->type == true && strcmp(set1->elements[i], set2->elements[j]) == 0)) {
               addToSet(intersection, set1->elements[i]);
               break;
           }
       }
   }
   return intersection;//returning a newly created intersection of two sets
}
GenSet_t* diffSet(GenSet_t *set1, GenSet_t *set2) {//function making a new set - a difference of two given sets
   if(set1->type != set2->type) {//checking if the data types of the sets align
       printf("operation impossible, different data types\n");
       return 0;
   }
   GenSet_t *difference = initSet(set1->type == false ? "int" : "string");//initializing new set
   bool ifin1;
   for(int i = 0; i < set1->size; i++) {//iterating on every pair of elements - when there are no repetitions of a certain element, adding it to the new set
       ifin1 = false;
       for(int j = 0; j < set2->size; j++) {
           if( (set1->type == false && set1->elements[i] == set2->elements[j]) || (set1->type == true && strcmp(set1->elements[i], set2->elements[j]) == 0) ) {
               ifin1 = true;
               break;
           }
       }
       if (!ifin1) addToSet(difference, set1->elements[i]);


   }
   return difference;//returning a newly created difference of two sets
}
long long countSet(GenSet_t *set) {//function returning number of elements of the given set
   return set->size;
}
bool isSubsetSet(GenSet_t *set1, GenSet_t *set2) {//function returing if the first given set is a subset of the second given set
   bool result;
   for(int i = 0; i < set1->size; i++) {//iterating on every pair of elements to check if there are any elements in the first set that do not match with elements in the second set
       result = false;
       for(int j = 0; j < set2->size; j++) {
           if(set1->elements[i] == set2->elements[j]) {
               result = true;
               break;
           }
       }
       if(!result) return false;//returning false if there is an element in the first set that does not match with the element in the second set
   }
   return true;//returning true if there are no elements in the first set that do not match with the elements in the second set
}
bool isEmptySet(GenSet_t *set) {//function returning if the given set is empty or not by checking its size
   if(set->size == 0) return true;//returning false if there are no elements in the set
   else return false;//returning false if there are some elements in the set
}
