#include <cstdio>

#include "src/GAnimal.h"
#include "src/GCat.h"
#include "src/GDog.h"
#include "src/GPlayerState.h"

void ExampleGameplayFunction(GObject* InMysteriousObjA, GObject* InMysteriousObjB)
{
    if (InMysteriousObjA->IsA(GPlayerState::StaticClass()))
    {
        printf("Object A is of a type GPlayerState or a type that inherits from GPlayerState.\n");
    }

    if (InMysteriousObjB->IsA(GAnimal::StaticClass()))
    {
        printf("Object B is of a type GAnimal or a type that inherits from GAnimal.\n");
    }

    GAnimal* animal = Cast<GAnimal>(InMysteriousObjB);

    if (animal != nullptr)
    {
        printf("Object B is a GAnimal.\n");

        GCat* cat = Cast<GCat>(animal);
        if (cat != nullptr)
        {
            printf("Object B is a GCat.\n");
            cat->Meow();
        }

        GDog* dog = Cast<GDog>(animal);
        if (dog != nullptr)
        {
            printf("Object B is a GDog.\n");
            dog->Bark();
        }
    }
}

int main()
{
    printf("Call 1 : \n");
    ExampleGameplayFunction(new GPlayerState(), new GCat());

    printf("Call 2 : \n");
    ExampleGameplayFunction(new GPlayerState(), new GDog());
    
   return 0;
}
