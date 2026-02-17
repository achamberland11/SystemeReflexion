#pragma once
#include <iostream>
#include <ostream>

#include "GAnimal.h"

class GDog : public GAnimal
{
public:
    GENERATE_REFLECTION()

    void Bark() { std::cout << "Woof" << std::endl; }
};
