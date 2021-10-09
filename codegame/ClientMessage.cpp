#include "ClientMessage.hpp"
#include <stdexcept>

namespace codegame {

DebugMessage::DebugMessage(std::shared_ptr<debugging::DebugCommand> command) : command(command) { }

// Read DebugMessage from input stream
DebugMessage DebugMessage::readFrom(InputStream& stream) {
    std::shared_ptr<debugging::DebugCommand> command = debugging::DebugCommand::readFrom(stream);
    return DebugMessage(command);
}

// Write DebugMessage to output stream
void DebugMessage::writeTo(OutputStream& stream) const {
    stream.write(TAG);
    command->writeTo(stream);
}

// Get string representation of DebugMessage
std::string DebugMessage::toString() const {
    std::stringstream ss;
    ss << "ClientMessage::DebugMessage { ";
    ss << "command: ";
    ss << command->toString();
    ss << " }";
    return ss.str();
}

ActionMessage::ActionMessage(model::Action action) : action(action) { }

// Write ActionMessage to output stream
void ActionMessage::writeTo(OutputStream& stream) const {
    stream.write(TAG);
    action.writeTo(stream);
}

// Read DebugUpdateDone from input stream
DebugUpdateDone DebugUpdateDone::readFrom(InputStream& ) {
    return DebugUpdateDone();
}

// Write DebugUpdateDone to output stream
void DebugUpdateDone::writeTo(OutputStream& stream) const {
    stream.write(TAG);
    stream.flush();
}

// Get string representation of DebugUpdateDone
std::string DebugUpdateDone::toString() const {
    std::stringstream ss;
    ss << "ClientMessage::DebugUpdateDone { ";
    ss << " }";
    return ss.str();
}

bool DebugUpdateDone::operator ==(const DebugUpdateDone& ) const {
    return true;
}

RequestDebugState::RequestDebugState() { }

// Read RequestDebugState from input stream
RequestDebugState RequestDebugState::readFrom(InputStream& ) {
    return RequestDebugState();
}

// Write RequestDebugState to output stream
void RequestDebugState::writeTo(OutputStream& stream) const {
    stream.write(TAG);
}

// Get string representation of RequestDebugState
std::string RequestDebugState::toString() const {
    std::stringstream ss;
    ss << "ClientMessage::RequestDebugState { ";
    ss << " }";
    return ss.str();
}

bool RequestDebugState::operator ==(const RequestDebugState& ) const {
    return true;
}

//// Read ClientMessage from input stream
//std::shared_ptr<ClientMessage> ClientMessage::readFrom(InputStream& stream) {
//    switch (stream.readInt()) {
//    case 0:
//        return std::shared_ptr<ClientMessage::DebugMessage>(new ClientMessage::DebugMessage(ClientMessage::DebugMessage::readFrom(stream)));
//    case 1:
//        return std::shared_ptr<ClientMessage::ActionMessage>(new ClientMessage::ActionMessage(ClientMessage::ActionMessage::readFrom(stream)));
//    case 2:
//        return std::shared_ptr<ClientMessage::DebugUpdateDone>(new ClientMessage::DebugUpdateDone(ClientMessage::DebugUpdateDone::readFrom(stream)));
//    case 3:
//        return std::shared_ptr<ClientMessage::RequestDebugState>(new ClientMessage::RequestDebugState(ClientMessage::RequestDebugState::readFrom(stream)));
//    default:
//        throw std::runtime_error("Unexpected tag value");
//    }
//}

}
