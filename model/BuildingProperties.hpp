#ifndef __MODEL_BUILDING_PROPERTIES_HPP__
#define __MODEL_BUILDING_PROPERTIES_HPP__

#include "model/Resource.hpp"

namespace model {

class BuildingProperties {
public:
    Resources resToBuild; //!<
    int maxHealth; //!<
    int maxWorkers; //!<
    Resources resToCraft; //!< ресы для выработки 1 единицы
    bool produceWorker; //!< новый робот ? (только для Репликатора)
    Resource produceResource; //!< получаемый ресурс
    int produceAmount; //!< кол-во единиц за 1 работу
    int produceScore; //!< очки за 1 единицу
    bool harvest; //!< добывающее из планеты
    int workersToOneRes; //!< количество роботов для вырвботки 1 единицы ресурса

    BuildingProperties() {  };

    // Read BuildingProperties from input stream
    void readFrom(InputStream& stream);
};

extern std::vector<BuildingProperties> buildingProperties;

}

#endif
