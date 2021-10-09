#include "Action.hpp"

namespace model {

Action::Action(std::vector<MoveAction> moves, std::vector<BuildingAction> buildings) : moves(moves), buildings(buildings) { }

// Write Action to output stream
void Action::writeTo(OutputStream& stream) const {
/// TAG of Action message
    stream.write(1);

//    stream.write((int)0);
    stream.write((int)(moves.size()));
    for (const MoveAction& movesElement : moves) {
        movesElement.writeTo(stream);
    }
//    stream.write((int)0);
    stream.write((int)(buildings.size()));
    for (const BuildingAction& buildingsElement : buildings) {
        buildingsElement.writeTo(stream);
    }
    stream.flush();
}

}
