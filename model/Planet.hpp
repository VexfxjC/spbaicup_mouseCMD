#ifndef __MODEL_PLANET_HPP__
#define __MODEL_PLANET_HPP__

#include "model/Building.hpp"
#include "model/Resource.hpp"
#include "model/WorkerGroup.hpp"
#include "model/BuildingProperties.hpp"
#include "MoveAction.hpp"
#include "BuildingAction.hpp"

namespace model {

struct Quest {
    BuildingType toBuild { NO_BUILDING };
    Resources res;
    Quest() {  }

    int& operator[](int val) { if (val < RES_SIZE) return res[val]; else exit(0); }
};

class Planet;
extern std::vector<Planet> v_planets;

class Planet {
    int vsp_int { 0 };
public:
    int id { 0 };
    int x { 0 };
    int y { 0 };
    Resources res;
    Resource harvestableResource { NO_RES };
    std::vector<WorkerGroup> workerGroups;
    Building building;

    Planet() {
        workerGroups.resize(2);
        v_moveAction.clear();
    }
    // Read Planet from input stream
    void update(InputStream& stream);
#ifdef bot_viz
    QString info() const;
#endif

    int distanceTo(Planet a) const { return abs(x - a.x) + abs(y - a.y); }

    Quest need;
    void needBuildHarvest() {
    }
    void needBuild(BuildingType type) {
    }
    void defend_planet(int def) {
    }
    void zapretToTakeRes() {
    }
    void needResToCraft() {
    }

    /// запрещает учитывать работников, которые нужны для работы
    /// и вызов рабочих для работ если их мало
    void lockWorkersToWork() {
    }
    void lock(int val) {
    }

    std::vector<MoveAction> v_moveAction;
    bool sendToPlanet(Planet &p) {
        return v_moveAction.size();
    }
    void sendWorkersTo(Planet &p) {
    }

    BuildingAction buildAction;
    bool isCanBuild() {
        return true;
    }
};

}

#endif
