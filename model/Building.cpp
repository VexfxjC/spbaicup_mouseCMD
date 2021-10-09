#include "Building.hpp"

namespace model {

// Read Building from input stream
void Building::readFrom(InputStream& stream) {
    type = readBuildingType(stream);
    health = stream.readInt();
    workDone = stream.readInt();
}

// Write Building to output stream
void Building::writeTo(OutputStream& stream) const {
    stream.write((int)(type));
    stream.write(health);
    stream.write(workDone);
}

// Get string representation of Building
std::string Building::toString() const {
    std::stringstream ss;
    ss << "Building { buildingType: ";
    ss << buildingTypeToString(type);
    ss << ", health: ";
    ss << health;
    ss << ", workDone: ";
    ss << workDone;
    ss << " }";
    return ss.str();
}

bool Building::operator ==(const Building& other) const {
    return type == other.type && health == other.health && workDone == other.workDone;
}

}
