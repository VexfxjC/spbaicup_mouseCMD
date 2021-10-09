#ifndef __STREAM_HPP__
#define __STREAM_HPP__

#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stdexcept>
#include <sstream>

///VEX
#include <iostream>

#ifdef bot_viz
    #include <QString>

    const QString str_i_x_y = "#%1 %2 %3\n";
    const QString str_1arg = "%1\n";
    const QString str_res = "\n%1 : %2";

    const QString str_FG = "#%1 %2 %3\n%4\n%5 %6";

#endif

struct GameSettings {
    int myIndex { 0 };
    int currentTick { 0 };
    int maxTickCount { 2 };
    int planetsSize { 0 };
    int maxFlyingWorkerGroups { 0 };
    int maxTravelDistance { 0 };
    int maxBuilders { 0 };

    std::vector<int> v_need_buildings; //!< need to build
    std::vector<int> v_my_buildings; //!< buildings done

    std::vector<std::vector<int>> distToNearPlanet;
    std::vector<std::vector<int>> distToEachPlanet;
};
extern GameSettings _gs;

#define MAX2(a, b) ((a > b) ? a : b)
#define MAX3(a, b, c) MAX2(a, MAX2(b, c))
#define MIN2(a, b) ((a < b) ? a : b)
#define MIN3(a, b, c) MIN2(a, MIN2(b, c))

// Input stream interface
class InputStream {
public:
    // Read exactly byteCount bytes into buffer
    virtual void readBytes(char* buffer, size_t byteCount) = 0;
    // Read a bool from this stream
    bool readBool();
    // Read an int from this stream
    int readInt();
    // Read a long long from this stream
    long long readLongLong();
    // Read a float from this stream
    float readFloat();
    // Read a double from this stream
    double readDouble();
    // Read a string from this stream
    std::string readString();
};

// Output stream interface
class OutputStream {
public:
    // Write byte buffer into this stream
    virtual void writeBytes(const char* buffer, size_t byteCount) = 0;
    // Flush this stream
    virtual void flush() = 0;
    // Write a bool into this stream
    void write(bool value);
    // Write an int into this stream
    void write(int value);
    // Write a long long into this stream
    void write(long long value);
    // Write a float into this stream
    void write(float value);
    // Write a double into this stream
    void write(double value);
    // Write a string into this stream
    void write(const std::string& value);
};

#endif
