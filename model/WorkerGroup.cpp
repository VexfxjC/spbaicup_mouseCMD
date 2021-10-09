#include "WorkerGroup.hpp"

namespace model {

// Read WorkerGroup from input stream
void WorkerGroup::readFrom(InputStream& stream) {
    playerIndex = stream.readInt();
    number = stream.readInt();
}

bool WorkerGroup::operator ==(const WorkerGroup& other) const {
    return playerIndex == other.playerIndex && number == other.number;
}

}
