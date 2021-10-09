#ifndef __MODEL_FLYING_WORKER_GROUP_HPP__
#define __MODEL_FLYING_WORKER_GROUP_HPP__

#include "model/Resource.hpp"

namespace model {

class FlyingWorkerGroup;
extern std::vector<FlyingWorkerGroup> v_flyingWorkerGroup;

class FlyingWorkerGroup {
public:
    int playerIndex { 0 };
    int number { 0 };
    int departureTick { 0 };
    int fromPlanet { 0 };
    int nextPlanetArrivalTick { 0 };
    int nextPlanet { 0 };
    int targetPlanet { 0 };
    Resource resource { NO_RES };

#ifdef bot_viz
    int x { 0 };
    int y { 0 };

    QString info(int index) const {
        QString str_info;

        str_info.append(str_FG.arg(index)
                        .arg(playerIndex == _gs.myIndex ? "my" : "en")
                        .arg(number)
                        .arg(resourceToString(resource).data())
                        .arg(nextPlanet)
                        .arg(targetPlanet)
                        );
        return str_info;
    }

#endif

    FlyingWorkerGroup() {}
    FlyingWorkerGroup(int playerIndex, int number, int departureTick, int fromPlanet, int nextPlanetArrivalTick, int nextPlanet, int targetPlanet, Resource resource);

    // Read FlyingWorkerGroup from input stream
    void readFrom(InputStream& stream);
};

}

#endif
