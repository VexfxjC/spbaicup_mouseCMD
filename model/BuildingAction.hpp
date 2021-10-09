#ifndef __MODEL_BUILDING_ACTION_HPP__
#define __MODEL_BUILDING_ACTION_HPP__

#include "model/BuildingType.hpp"

namespace model {

class BuildingAction {
public:
    int planet;
    BuildingType buildingType;

    BuildingAction() {}
    BuildingAction(int planet, BuildingType buildingType);

    // Write BuildingAction to output stream
    void writeTo(OutputStream& stream) const;
};

}

#endif
