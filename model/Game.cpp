#include "Game.hpp"

namespace model {

// Read Game from input stream
void Game::update(InputStream& stream) {
    static int index;

    _gs.myIndex = stream.readInt();
    _gs.currentTick = stream.readInt();
    _gs.maxTickCount = stream.readInt();
    int playersSize = stream.readInt();
    if (_gs.currentTick == 0)
        players.resize(playersSize);
    for (index = 0; index < playersSize; ++index) {
        players[index].readFrom(stream);
    }
    _gs.planetsSize = stream.readInt();
    if (_gs.currentTick == 0)
        v_planets.resize(_gs.planetsSize);
    for (index = 0; index < _gs.planetsSize; ++index) {
        v_planets[index].update(stream);
    }
    int flyingWorkerGroupsSize = stream.readInt();
    for (index = 0; index < flyingWorkerGroupsSize; ++index) {
        v_flyingWorkerGroup[index].readFrom(stream);
    }
    for (; index < _gs.maxFlyingWorkerGroups*2; ++index) {
        if (!v_flyingWorkerGroup[index].number)
            break;
        v_flyingWorkerGroup[index].number = 0;
    }
    _gs.maxFlyingWorkerGroups = stream.readInt();
    if (_gs.currentTick == 0)
        v_flyingWorkerGroup.resize(_gs.maxFlyingWorkerGroups*2);
    _gs.maxTravelDistance = stream.readInt();
    _gs.maxBuilders = stream.readInt();

    size_t buildingPropertiesSize = stream.readInt();
    for (size_t buildingPropertiesIndex = 0; buildingPropertiesIndex < buildingPropertiesSize; ++buildingPropertiesIndex) {
        model::BuildingType buildingPropertiesKey = readBuildingType(stream);
        buildingProperties[buildingPropertiesKey].readFrom(stream);
    }

    /// заполняем работников, как ресурс на планете
    for (auto &p : v_planets) {
        for (auto &wg : p.workerGroups) {
            if (wg.playerIndex == _gs.myIndex) {
                p.res[MY_WORKER] += wg.number;
            } else {
                p.res[EN_WORKER] += wg.number;
            }
        }
    }
}

}
