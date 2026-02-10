#pragma once
#include <string>

class CClass
{
public:
    CClass(const std::string& name, const CClass* parent): Name(name), Parent(parent) {}

    const std::string& GetName() const { return Name; }
    const CClass* GetParent() const { return Parent; }

    bool IsChildOf(const CClass* other) const
    {
        const CClass* current = this;
        while (current != nullptr)
        {
            if (current == other) return true;
            current = current->GetParent();
        }
        return false;
    }

private:
    std::string Name;
    const CClass* Parent;
    
};
