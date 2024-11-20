#include <stdio.h>
#include <stdbool.h>
#include "library.h"
int main() {
   GenSet_t *set = initSet("int");
   addToSet(set, 5);
   addToSet(set, 6);
   addToSet(set, 7);
   addToSet(set, 6);
   displaySet(set);
   GenSet_t *set2 = initSet("int");
   addToSet(set2, 3);
   addToSet(set2, 5);
   printf("Is Subset? %s\n", isSubsetSet(set2, set) ? "true" : "false");
   printf("Is Empty? %s\n", isEmptySet(set) ? "true" : "false");
   GenSet_t *stringset = initSet("string");
   addToSet(stringset, "ala");
   addToSet(stringset, "ma");
   addToSet(stringset, "kota");
   displaySet(stringset);
   GenSet_t *setunion = unionSet(set, set2);
   GenSet_t *setintersect = intersectSet(set, set2);
   GenSet_t *setdiff1 = diffSet(set, set2);
   GenSet_t *setdiff2 = diffSet(set2, set);
   deinitSet(set2);
   printf("\n");
   displaySet(setunion);
   printf("\n");
   displaySet(setintersect);
   printf("\n");
   displaySet(setdiff1);
   printf("\n");
   displaySet(setdiff2);
   printf("wielkosc unii: %lld\n", countSet(setunion));
   GenSet_t *stringi = initSet("string");
   addToSet(stringi, "ala");
   addToSet(stringi, "ma");
   printf("Is Subset? %s\n", isSubsetSet(stringi, stringset) ? "true" : "false");
   printf("Is Subset? %s\n", isSubsetSet(stringset, stringi) ? "true" : "false");
   GenSet_t *pusty = initSet("int");
   printf("Is Empty? %s\n", isEmptySet(pusty) ? "true" : "false");
   printf("pusty: %lld\n", countSet(pusty));
   GenSet_t *niepoprawne = unionSet(set, stringset);
   printf("koniec essa");
   return 0;
}
