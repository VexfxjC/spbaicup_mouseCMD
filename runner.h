#ifndef RUNNER_H
#define RUNNER_H

#include "TcpStream.hpp"
#include "codegame/ServerMessage.hpp"
#include "codegame/ClientMessage.hpp"

class Runner {
    TcpStream tcpStream;
public:
    Runner(const std::string& host, int port, const std::string& token): tcpStream(host, port)
    {
        tcpStream.write(token);
        tcpStream.write(int(0));
        tcpStream.write(int(3));
        tcpStream.write(int(0));
        tcpStream.flush();
    }
    int msg_type;
    codegame::World world;
    codegame::Finish finish;
    codegame::DebugUpdate debugUpdate;
    codegame::DebugUpdateDone debugUpdateDone;
    bool isRun { true };
    void listen() {
        msg_type = tcpStream.readInt();
        switch (msg_type) {
            case 0 : {
                world.update(tcpStream);
            } break;
            case 1 : {
                return;
            } break;
            case 2 : {
                debugUpdate.readFrom(tcpStream);
                debugUpdateDone.writeTo(tcpStream);
                listen();
            } break;
            default :
                throw std::runtime_error("Unexpected tag value");
        }
    }
    void send(const model::Action &actions) {
        if (_gs.currentTick == _gs.maxTickCount)
            return;

        actions.writeTo(tcpStream);

        listen();
    }
};

#endif // RUNNER_H
