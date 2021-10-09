#ifndef __MODEL_CLIENT_MESSAGE_HPP__
#define __MODEL_CLIENT_MESSAGE_HPP__

#include "debugging/DebugCommand.hpp"
#include "model/Action.hpp"
#include "model/BuildingAction.hpp"
#include "model/BuildingType.hpp"
#include "model/DebugData.hpp"
#include "model/MoveAction.hpp"
#include "model/Resource.hpp"

namespace codegame {

// Ask app to perform new debug command
class DebugMessage  {
    static const int TAG = 0;
public:

    // Command to perform
    std::shared_ptr<debugging::DebugCommand> command;

    DebugMessage(std::shared_ptr<debugging::DebugCommand> command);

    // Read DebugMessage from input stream
    static DebugMessage readFrom(InputStream& stream);

    // Write DebugMessage to output stream
    void writeTo(OutputStream& stream) const;

    // Get string representation of DebugMessage
    std::string toString() const;
};

// Reply for ServerMessage::GetAction
class ActionMessage  {
    static const int TAG = 1;
public:

    // Player's action
    model::Action action;

    ActionMessage() {};
    ActionMessage(model::Action action);

    // Write ActionMessage to output stream
    void writeTo(OutputStream& stream) const;
};

// Signifies finish of the debug update
class DebugUpdateDone {
    static const int TAG = 2;
public:
    DebugUpdateDone() {}
    // Read DebugUpdateDone from input stream
    static DebugUpdateDone readFrom(InputStream&);

    // Write DebugUpdateDone to output stream
    void writeTo(OutputStream& stream) const;

    // Get string representation of DebugUpdateDone
    std::string toString() const;

    bool operator ==(const DebugUpdateDone&) const;
};

// Request debug state from the app
class RequestDebugState {
    static const int TAG = 3;
public:

    RequestDebugState();

    // Read RequestDebugState from input stream
    static RequestDebugState readFrom(InputStream&);

    // Write RequestDebugState to output stream
    void writeTo(OutputStream& stream) const;

    // Get string representation of RequestDebugState
    std::string toString() const;

    bool operator ==(const RequestDebugState&) const;
};

}

#endif
