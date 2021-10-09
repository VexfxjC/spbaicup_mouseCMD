#include "Resource.hpp"

namespace model {

// Read Resource from input stream
Resource readResourceIndex(InputStream& stream) {
    switch (stream.readInt()) {
        case 0 : return STONE;
        case 1 : return ORE;
        case 2 : return SAND;
        case 3 : return ORGANICS;
        case 4 : return METAL;
        case 5 : return SILICON;
        case 6 : return PLASTIC;
        case 7 : return CHIP;
        case 8 : return ACCUM;
        default : throw std::runtime_error("Unexpected tag value");
    }
}
// Get string representation of Resource
std::string resourceToString(int value) {
    switch (value) {
        case STONE    : return "🧱";
        case ORE      : return "Руда";
        case SAND     : return "Песок";
        case ORGANICS : return "🦠";
        case METAL    : return "Металл";
        case SILICON  : return "Кремний";
        case PLASTIC  : return "Пластик";
        case CHIP     : return "Чипы";
        case ACCUM    : return "🔋";
        case MY_WORKER: return "👼";
        case EN_WORKER: return "🤖";
        default       : return "NO_RES"  ;
    }
}
}
