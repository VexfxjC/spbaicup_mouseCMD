#ifndef __MODEL_BUILDING_TYPE_HPP__
#define __MODEL_BUILDING_TYPE_HPP__

#include "Stream.hpp"

namespace model {

enum BuildingType : int {
    NO_BUILDING   =-1,
    QUARRY        = 0, //!< Каменоломня
    MINES         = 1, //!< Шахта
    CAREER        = 2, //!< Карьер
    FARM          = 3, //!< Ферма
    FOUNDRY       = 4, //!< Плавильня
    FURNACE       = 5, //!< Печь
    BIOREACTOR    = 6, //!< Биореактор
    CHIP_FACTORY  = 7, //!< ФабрикаЧипов
    ACCUM_FACTORY = 8, //!< АккумЗавод
    REPLICATOR    = 9, //!< Репликатор
    BUILDING_SIZE
};

// Read BuildingType from input stream
BuildingType readBuildingType(InputStream& stream);

// Get string representation of BuildingType
std::string buildingTypeToString(int value);

}

#endif
