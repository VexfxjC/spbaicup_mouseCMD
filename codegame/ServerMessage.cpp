#include "ServerMessage.hpp"
#include <stdexcept>

namespace codegame {

World::World(model::Game playerView, bool debugAvailable) : game(playerView), debugAvailable(debugAvailable) { }

// Read GetAction from input stream
void World::update(InputStream& stream) {
    game.update(stream);
    debugAvailable = stream.readBool();
}

DebugUpdate::DebugUpdate(model::Game playerView) : playerView(playerView) { }

// Read DebugUpdate from input stream
void DebugUpdate::readFrom(InputStream& stream) {
    playerView.update(stream);
}

}
