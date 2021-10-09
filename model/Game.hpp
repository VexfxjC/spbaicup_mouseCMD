#ifndef __MODEL_GAME_HPP__
#define __MODEL_GAME_HPP__

#include "model/Planet.hpp"
#include "model/Player.hpp"
#include "model/FlyingWorkerGroup.hpp"
#include "model/BuildingProperties.hpp"
#include "model/Action.hpp"

#include <list>

namespace model {

class Game {
public:
    std::vector<Player> players;

    Game() {
        buildingProperties.resize(BUILDING_SIZE);
    };

    // Read Game from input stream
    void update(InputStream& stream);
};

}

#endif
