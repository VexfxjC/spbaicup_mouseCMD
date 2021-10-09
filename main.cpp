#ifdef bot_viz
    #include <QApplication>
    #include "widget.h"
#else
    #include "runner.h"
#endif

int main(int argc, char* argv[])
{
    std::string host = argc < 2 ? "127.0.0.1" : argv[1];
    int port = argc < 3 ? 31005 : atoi(argv[2]);
    std::string token = argc < 4 ? "0000000000000000" : argv[3];

    int byby = 0;
#ifdef bot_viz
    QApplication a(argc, argv);

    Map map(host, port, token);

    byby = QApplication::exec();
#else
    Runner runner(host, port, token);
    runner.run();
#endif
    return byby;
}
