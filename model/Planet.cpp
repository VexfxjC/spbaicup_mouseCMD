#include "Planet.hpp"

namespace model {

std::vector<Planet> v_planets;

// Read Planet from input stream
void Planet::update(InputStream& stream) {
    id = stream.readInt();
    x = stream.readInt();
    y = stream.readInt();
    if (stream.readBool()) {
        harvestableResource = readResourceIndex(stream);
    } else {
        harvestableResource = Resource::NO_RES;
    }
    size_t workerGroupsSize = stream.readInt();
    memset(&workerGroups[0], 0, sizeof(WorkerGroup)*2);
    for (size_t workerGroupsIndex = 0; workerGroupsIndex < workerGroupsSize; ++workerGroupsIndex) {
        workerGroups[workerGroupsIndex].readFrom(stream);
    }
    size_t resourcesSize = stream.readInt();
    res.fill0();
    for (size_t resourcesIndex = 0; resourcesIndex < resourcesSize; resourcesIndex++) {
        model::Resource resourcesKey = readResourceIndex(stream);
        res[resourcesKey] = stream.readInt();
    }
    if (stream.readBool())
        building.readFrom(stream);
    else
        building.type = NO_BUILDING;
}

#ifdef bot_viz
    QString Planet::info() const {
        QString str_info;

        str_info.append(str_i_x_y.arg(id).arg(x).arg(y));
        str_info.append(str_1arg.arg(resourceToString(harvestableResource).data()));
        str_info.append(str_1arg.arg(buildingTypeToString(building.type).data()));

        str_info.append(str_1arg.arg("\nРесурсы :"));
        for (int r = 0; r < RES_SIZE; ++r) {
            if (res.res[r]) {
                str_info.append(str_res.arg(resourceToString(r).data()).arg(res.res[r]));
            }
        }

        str_info.append(str_1arg.arg("\nЗапрос :"));
        str_info.append(str_1arg.arg(buildingTypeToString(need.toBuild).data()));
        for (int r = 0; r < RES_SIZE; ++r) {
            if (need.res.res[r]) {
                str_info.append(str_res.arg(resourceToString(r).data()).arg(need.res.res[r]));
            }
        }

        return str_info;
    }
#endif


}
