#ifndef __MODEL_BUILDING_HPP__
#define __MODEL_BUILDING_HPP__

#include "model/BuildingType.hpp"

namespace model {

class Building {
public:
    BuildingType type { NO_BUILDING };
    int health { 0 };
    int workDone { 0 };

    Building() {  }

    // Read Building from input stream
    void readFrom(InputStream& stream);

    // Write Building to output stream
    void writeTo(OutputStream& stream) const;

    // Get string representation of Building
    std::string toString() const;

    bool operator ==(const Building& other) const;
};

}

#endif
