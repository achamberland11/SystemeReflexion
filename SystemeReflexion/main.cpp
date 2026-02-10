#include <cstdio>
#include <vector>

#include "src/GAnimal.h"
#include "src/GCat.h"
#include "src/GDog.h"
#include "src/GPlayerState.h"

// Exemple de la fonction du TP
void ExampleGameplayFunction(GObject* InMysteriousObjA, GObject* InMysteriousObjB)
{
    if (InMysteriousObjA->IsA(GPlayerState::StaticClass()))
    {
        printf("Object A is of a type GPlayerState or a type that inherits from GPlayerState.\n");
    }
}

int main()
{
    // --- Test IsA ---
    GPlayerState playerState;
    GCat cat;
    GDog dog;

    printf("=== IsA Tests ===\n");
    ExampleGameplayFunction(&playerState, &cat);

    printf("cat IsA GAnimal? %s\n", cat.IsA(GAnimal::StaticClass()) ? "true" : "false");   // true
    printf("cat IsA GCat?    %s\n", cat.IsA(GCat::StaticClass()) ? "true" : "false");       // true
    printf("cat IsA GDog?    %s\n", cat.IsA(GDog::StaticClass()) ? "true" : "false");       // false
    printf("dog IsA GAnimal? %s\n", dog.IsA(GAnimal::StaticClass()) ? "true" : "false");    // true

    // --- Test Cast avec un vecteur de GAnimal* ---
    printf("\n=== Cast Tests ===\n");
    std::vector<GAnimal*> animals;
    animals.push_back(new GCat());
    animals.push_back(new GDog());
    animals.push_back(new GCat());
    animals.push_back(new GDog());

    for (GAnimal* animal : animals)
    {
        if (GCat* asCat = Cast<GCat>(animal))
        {
            printf("Found a cat! (class: %s)\n", asCat->GetClass()->GetName().c_str());
        }
        else if (GDog* asDog = Cast<GDog>(animal))
        {
            printf("Found a dog! (class: %s)\n", asDog->GetClass()->GetName().c_str());
        }
    }

    // Cleanup
    for (GAnimal* animal : animals)
        delete animal;

    return 0;
}
