#include "FlyingWorkerGroup.hpp"

namespace model {

std::vector<FlyingWorkerGroup> v_flyingWorkerGroup;

FlyingWorkerGroup::FlyingWorkerGroup(int playerIndex, int number, int departureTick, int departurePlanet, int nextPlanetArrivalTick, int nextPlanet, int targetPlanet, Resource resource)
    : playerIndex(playerIndex), number(number), departureTick(departureTick), fromPlanet(departurePlanet), nextPlanetArrivalTick(nextPlanetArrivalTick), nextPlanet(nextPlanet), targetPlanet(targetPlanet), resource(resource)
{ }

// Read FlyingWorkerGroup from input stream
void FlyingWorkerGroup::readFrom(InputStream& stream) {
    playerIndex = stream.readInt();
    number = stream.readInt();
    departureTick = stream.readInt();
    fromPlanet = stream.readInt();
    nextPlanetArrivalTick = stream.readInt();
    nextPlanet = stream.readInt();
    targetPlanet = stream.readInt();
    if (stream.readBool()) {
        resource = readResourceIndex(stream);
    } else {
        resource = NO_RES;
    }
}

}
