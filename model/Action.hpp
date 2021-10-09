#ifndef __MODEL_ACTION_HPP__
#define __MODEL_ACTION_HPP__

#include "Stream.hpp"
#include "model/BuildingAction.hpp"
#include "model/BuildingType.hpp"
#include "model/MoveAction.hpp"
#include "model/Resource.hpp"

namespace model {

class Action {
public:
    std::vector<MoveAction> moves;
    std::vector<BuildingAction> buildings;

    Action() {};
    Action(std::vector<MoveAction> moves, std::vector<BuildingAction> buildings);

    // Write Action to output stream
    void writeTo(OutputStream& stream) const;
};

}

#endif
