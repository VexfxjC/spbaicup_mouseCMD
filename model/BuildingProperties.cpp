#include "BuildingProperties.hpp"

namespace model {

std::vector<BuildingProperties> buildingProperties;

// Read BuildingProperties from input stream
void BuildingProperties::readFrom(InputStream& stream) {
    size_t buildResourcesSize = stream.readInt();
    for (size_t buildResourcesIndex = 0; buildResourcesIndex < buildResourcesSize; buildResourcesIndex++) {
        model::Resource buildResourcesKey = readResourceIndex(stream);
        resToBuild.res[buildResourcesKey] = stream.readInt();
    }
    maxHealth = stream.readInt();
    maxWorkers = stream.readInt();
    size_t workResourcesSize = stream.readInt();
    for (size_t workResourcesIndex = 0; workResourcesIndex < workResourcesSize; workResourcesIndex++) {
        model::Resource workResourcesKey = readResourceIndex(stream);
        resToCraft.res[workResourcesKey] = stream.readInt();
    }
    produceWorker = stream.readBool();
    if (stream.readBool()) {
        produceResource = readResourceIndex(stream);
    } else {
        produceResource = NO_RES;
    }
    if (produceWorker) {
        produceResource = MY_WORKER;
    }
    produceAmount = stream.readInt();
    produceScore = stream.readInt();
    harvest = stream.readBool();
    workersToOneRes = stream.readInt();
}

}
