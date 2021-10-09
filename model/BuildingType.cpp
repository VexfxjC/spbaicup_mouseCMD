#include "BuildingType.hpp"
#include <stdexcept>

namespace model {

// Read BuildingType from input stream
BuildingType readBuildingType(InputStream& stream) {
    switch (stream.readInt()) {
        case 0 : return QUARRY;
        case 1 : return MINES;
        case 2 : return CAREER;
        case 3 : return FARM;
        case 4 : return FOUNDRY;
        case 5 : return FURNACE;
        case 6 : return BIOREACTOR;
        case 7 : return CHIP_FACTORY;
        case 8 : return ACCUM_FACTORY;
        case 9 : return REPLICATOR;
        default: throw std::runtime_error("Unexpected tag value");
    }
}

// Get string representation of BuildingType
std::string buildingTypeToString(int value) {
    switch (value) {
        case QUARRY       : return "Каменоломня";
        case MINES        : return "Шахта";
        case CAREER       : return "Карьер";
        case FARM         : return "Ферма";
        case FOUNDRY      : return "Плавильня";
        case FURNACE      : return "Печь";
        case BIOREACTOR   : return "Биореактор";
        case CHIP_FACTORY : return "ЧипЗавод";
        case ACCUM_FACTORY: return "АккумЗавод";
        case REPLICATOR   : return "Производство";
        default : return "none";
    }
}

}
