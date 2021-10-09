#ifndef __MODEL_WORKER_GROUP_HPP__
#define __MODEL_WORKER_GROUP_HPP__

#include "Stream.hpp"

namespace model {

class WorkerGroup {
public:
    int playerIndex { 0 };
    int number { 0 };

    WorkerGroup() {  };

    // Read WorkerGroup from input stream
    void readFrom(InputStream& stream);

    bool operator ==(const WorkerGroup& other) const;
};

}

#endif
