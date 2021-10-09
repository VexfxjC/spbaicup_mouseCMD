#include "Player.hpp"

namespace model {

Player::Player(int score) : score(score) { }

// Read Player from input stream
void Player::readFrom(InputStream& stream) {
    score = stream.readInt();
}


bool Player::operator ==(const Player& other) const {
    return score == other.score;
}

}

size_t std::hash<model::Player>::operator ()(const model::Player& value) const {
    size_t result = 0;
    result ^= std::hash<int>{}(value.score) + 0x9e3779b9 + (result << 6) + (result >> 2);
    return result;
}
