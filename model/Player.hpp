#ifndef __MODEL_PLAYER_HPP__
#define __MODEL_PLAYER_HPP__

#include "Stream.hpp"
#include <sstream>
#include <string>

namespace model {

class Player {
public:
    int score { 0 };

    Player() {  }
    Player(int score);

    // Read Player from input stream
    void readFrom(InputStream& stream);

    bool operator ==(const Player& other) const;
};

}

namespace std {
    template<>
    struct hash<model::Player> {
        size_t operator ()(const model::Player& value) const;
    };
}

#endif
