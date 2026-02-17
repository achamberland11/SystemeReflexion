#pragma once
#include <iostream>
#include <ostream>

#include "GAnimal.h"

class GCat : public GAnimal
{
public:
    GENERATE_REFLECTION()

    void Meow() { std::cout << "Meow" << std::endl; }
};
