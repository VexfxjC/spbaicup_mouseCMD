#ifndef __MODEL_MOVE_ACTION_HPP__
#define __MODEL_MOVE_ACTION_HPP__

#include "model/Resource.hpp"

namespace model {

class MoveAction {
public:
    int startPlanet { 0 };
    int targetPlanet { 0 };
    int workerNumber { 0 };
    Resource takeResource { NO_RES };
    int dist { 0 };

    MoveAction() {};
    MoveAction(int startPlanet, int targetPlanet, int workerNumber, Resource takeResource)
        : startPlanet(startPlanet), targetPlanet(targetPlanet), workerNumber(workerNumber), takeResource(takeResource)
    { }

    // Write MoveAction to output stream
    void writeTo(OutputStream& stream) const {
        stream.write(startPlanet);
        stream.write(targetPlanet);
        stream.write(workerNumber);
        switch (takeResource) {
            case NO_RES :
            case MY_WORKER :
                stream.write(false);
            break;
            default :
                stream.write(true);
                stream.write((int)takeResource);
            break;
        }
    }
};

}

#endif
