#include "magic_storm.h"

using namespace boost;
using namespace GW2LIB;
using namespace std;

MagicStorm::MagicStorm() : state(MS::PENDING) {
    timer.stop();
}

MS::State MagicStorm::getState() {
    if ((state == MS::RECHARGING) && !timer.is_stopped() && (getCooldown() <= 0.0f)) {
        timer.stop();
        state = MS::READY;
    }
    return state;
}

void MagicStorm::setState(MS::State state) {
    this->state = state;
    if (state == MS::RECHARGING) {
        timer.start();
    }
    else if (!timer.is_stopped()) {
        timer.stop();
    }
}

void MagicStorm::drawStatusMeter(float x, float y, float percent) {
    if (getState() == MS::READY) {
        meter.drawAtPercent(x, y, AssistDrawer::BREAKBAR_FULL, 1.0f);
    }
    else if (getState() == MS::ACTIVE) {
        string text = str(format("%d") % int(percent * 100));
        meter.drawAtPercent(x, y, AssistDrawer::BREAKBAR_DEPLETING, text, percent);
    }
    else if (getState() == MS::RECHARGING) {
        float remainingCooldown = getCooldown();
        float percent = (1.0f - (remainingCooldown / COOLDOWN));

        meter.drawAtPercent(x, y, AssistDrawer::BREAKBAR_RECHARGING, remainingCooldown, percent);
    }
}

float MagicStorm::getCooldown() {
    float secondsElapsed = float(timer.elapsed().wall / 1e9);
    return COOLDOWN - secondsElapsed;
}
