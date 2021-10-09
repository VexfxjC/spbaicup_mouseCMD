#include "DebugData.hpp"

namespace model {

DebugData::DebugData() { }

// Read DebugData from input stream
DebugData DebugData::readFrom(InputStream& ) {
    return DebugData();
}

// Write DebugData to output stream
void DebugData::writeTo(OutputStream& ) const {
}

// Get string representation of DebugData
std::string DebugData::toString() const {
    std::stringstream ss;
    ss << "DebugData { ";
    ss << " }";
    return ss.str();
}

bool DebugData::operator ==(const DebugData& ) const {
    return true;
}

}

size_t std::hash<model::DebugData>::operator ()(const model::DebugData& ) const {
    size_t result = 0;
    return result;
}
