#pragma once

#include "GameData.h"

class SquadMember {
    private:
        static const float WALK_SPEED;
        static const float RUN_SPEED;
        static const float COMBAT_RUN_SPEED;
        static const float DODGE_SPEED;
        static const float GLIDE_SPEED;
        static const float SWIFTNESS_SPEED;
        static const float COMBAT_SWIFTNESS_SPEED;
        static const float SUPERSPEED;

        std::string name;
        int dodgeCount;
        int superspeedCount;
        int heavyHitsTaken;
        float heavyDamageTaken;
        float totalDamageTaken;
        int downedCount;

        float lastSpeed;
        float secondLastSpeed;
        bool isAlive;
        float lastHealth;
        float lastHealthDelta;

        void updateLastHealthDelta(GW2LIB::Character &character);
        void updateDamageTaken();
        void updateMovementStats(GW2LIB::Character &character);

        SquadMember() = delete;

    public:
        SquadMember(GW2LIB::Character character);
        void updateStats(GW2LIB::Character &character);

        std::string getName() { return name; }
        int getDodgeCount() { return dodgeCount; }
        int getSuperspeedCount() { return superspeedCount; }
        float getLastHealthDelta() { return lastHealthDelta; }
        int getHeavyHitsTaken() { return heavyHitsTaken; }
        float getHeavyDamageTaken() { return heavyDamageTaken; }
        float getTotalDamageTaken() { return totalDamageTaken; }
        int getDownedCount() { return downedCount; }

        void takeHeavyHit();
};
