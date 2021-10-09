#include "BuildingAction.hpp"

namespace model {

BuildingAction::BuildingAction(int planet, BuildingType buildingType) : planet(planet), buildingType(buildingType) { }

// Write BuildingAction to output stream
void BuildingAction::writeTo(OutputStream& stream) const {
    stream.write(planet);
    if (buildingType == NO_BUILDING) {
        stream.write(false);
    } else {
        stream.write(true);
        stream.write((int)(buildingType));
    }
}
}
