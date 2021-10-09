#ifndef __MODEL_SERVER_MESSAGE_HPP__
#define __MODEL_SERVER_MESSAGE_HPP__

#include "model/Game.hpp"

namespace codegame {

// Get action for next tick
class World {
    static const int TAG = 0;
public:
    // Player's view
    model::Game game;
    // Whether app is running with debug interface available
    bool debugAvailable;

    World() {};
    World(model::Game game, bool debugAvailable);

    // Read GetAction from input stream
    void update(InputStream& stream);
};

// Signifies end of the game
class Finish {
    static const int TAG = 1;
public:
    Finish() {};
//    void writeTo(OutputStream& stream) const;
};

// Debug update
class DebugUpdate {
    static const int TAG = 2;
public:

    // Player's view
    model::Game playerView;

    DebugUpdate() {  };
    DebugUpdate(model::Game playerView);

    // Read DebugUpdate from input stream
    void readFrom(InputStream& stream);

//    // Write DebugUpdate to output stream
//    void writeTo(OutputStream& stream) const;

//    // Get string representation of DebugUpdate
//    std::string toString() const;
};

}

#endif
