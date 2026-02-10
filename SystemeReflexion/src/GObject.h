#pragma once
#include "Class.h"

// Macro à placer dans chaque classe dérivée supportant la réflexion.
// Elle déclare :
//   - une instance statique CClass (_StaticClass)
//   - une méthode statique StaticClass() pour y accéder
//   - l'override de GetClass() qui retourne le CClass de l'instance
#define GENERATE_REFLECTION()                                       \
public:                                                             \
    static const CClass* StaticClass() { return &_StaticClass; }    \
    virtual const CClass* GetClass() const override { return &_StaticClass; } \
private:                                                            \
    static CClass _StaticClass;                                     \
public:



class GObject
{
public:
    virtual ~GObject() = default;

    virtual const CClass* GetClass() const = 0;

    bool IsA(const CClass* InClass) const
    {
        return GetClass()->IsChildOf(InClass);
    }
};

template <class T>
T* Cast(GObject* InObject)
{
    if (InObject != nullptr && InObject->IsA(T::StaticClass()))
    {
        return static_cast<T*>(InObject);
    }
    return nullptr;
}
