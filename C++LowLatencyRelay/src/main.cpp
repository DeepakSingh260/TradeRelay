#include <iostream>
#include <thread>
#include "relay.h"

int main() {
    std::cout << "Starting Trade Relay Application" << std::endl;
    
    TradeRelay relay("127.0.0.1", 8888, "127.0.0.1", 9999);
    relay.start();

    return 0;
}
