//
//  main.cpp
//  ws_example
//
//  Created by Grimmer Kang on 2017/7/4.
//  Copyright © 2017年 Grimmer Kang. All rights reserved.
//

//#include <iostream>
//
//int main(int argc, const char * argv[]) {
//    // insert code here...
//    std::cout << "Hello, World!\n";
//    return 0;
//}

#include <uWS/uWS.h>
#include <iostream>


int main() {
//    uWS::Hub h;
//    
//    h.onMessage([](uWS::WebSocket<uWS::SERVER> *ws, char *message, size_t length, uWS::OpCode opCode) {
//        ws->send(message, length, opCode);
//    });
//    
//    h.onHttpRequest([](uWS::HttpResponse *res, uWS::HttpRequest req, char *data, size_t length, size_t remainingBytes) {
//        res->end();
////        res->end(const char *, size_t);
//    });
//    
//    h.listen(3003);
//    h.run();
    
    
    uWS::Hub h;
    
    h.onMessage([](uWS::WebSocket<uWS::SERVER> *ws, char *message, size_t length, uWS::OpCode opCode) {
        std::cout << "get something, echo back" << std::endl;

        ws->send(message, length, opCode);
        
    });
    
    h.listen(3003);
    h.run();
}
