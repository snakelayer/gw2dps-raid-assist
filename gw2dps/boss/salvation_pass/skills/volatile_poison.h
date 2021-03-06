#pragma once

#include <string>

#include "gw2lib.h"

#include "../../../draw/meter.h"
#include "../../../assist_drawer.h"

class VolatilePoison
{
    public:
        VolatilePoison();

        void updateState(int elapsedMilliseconds);
        void drawStatusMeter(float x, float y);

        int getElapsedMs(); // TODO: remove

    private:
        const int COOLDOWN = 25 * 1000;

        int elapsedMilliseconds;

        Meter meter;
};