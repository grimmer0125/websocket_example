#include <QCoreApplication>
#include <iostream>
#include <QDebug>

#include "uWS.h"
//#include <uWS/uWS.h> not this?

#include <thread>

using namespace std;

void testWebSocket(){
    uWS::Hub h;
    h.onMessage([](uWS::WebSocket<uWS::SERVER> *ws, char *message, size_t length, uWS::OpCode opCode) {
        std::cout << "get something, echo back" << std::endl;
        ws->send(message, length, opCode);
    });
    h.listen(3003);
    h.run();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "start test websocket";
    std::cout << "get something2, echo back" << std::endl;

    thread mThread( testWebSocket );

    qDebug() << "end to test websocket";

    mThread.detach();
    return a.exec(); // will block at here since QCoreApplication's event loop
}
