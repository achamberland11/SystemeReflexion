#include "GDog.h"

CClass GDog::sClass = CClass {
    "Dog",
    &GAnimal::sClass
};