#include <QCoreApplication>
#include <iostream>
#include <QDebug>

#include "uWS.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "start test websocket";
//    std::cout << "get something, echo back" << std::endl;

    uWS::Hub h;

    h.onMessage([](uWS::WebSocket<uWS::SERVER> *ws, char *message, size_t length, uWS::OpCode opCode) {
        std::cout << "get something, echo back" << std::endl;

        ws->send(message, length, opCode);

    });

    h.listen(3003);
    h.run();

    qDebug() << "end to test websocket";

    return a.exec(); // will block at here since QCoreApplication's event loop
}
