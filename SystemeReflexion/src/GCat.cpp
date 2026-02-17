#include "GCat.h"

CClass GCat::sClass = CClass {
    "Cat",
    &GAnimal::sClass
};