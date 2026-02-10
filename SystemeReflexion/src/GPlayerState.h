#pragma once
#include "GObject.h"

class GPlayerState : public GObject
{
public:
    GENERATE_REFLECTION()

    int _Points = 0;
};
