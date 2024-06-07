#include "relay.h"
#include <iostream>
#include <thread>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

TradeRelay::TradeRelay(const std::string& source_ip, int source_port, const std::string& target_ip, int target_port)
    : source_ip_(source_ip), source_port_(source_port), target_ip_(target_ip), target_port_(target_port) {}

void TradeRelay::start() {
    std::thread relay_thread( &TradeRelay::relay_loop, this );
    relay_thread.join();
}

void TradeRelay::relay_loop() {
    try {
        boost::asio::io_context io_context;

        tcp::socket source_socket(io_context);
        tcp::resolver resolver(io_context);
        boost::asio::connect(source_socket, resolver.resolve(source_ip_, std::to_string(source_port_)));

        tcp::socket target_socket(io_context);
        boost::asio::connect(target_socket, resolver.resolve(target_ip_, std::to_string(target_port_)));

        char data[1024];
        for (;;) {
            std::size_t length = source_socket.read_some(boost::asio::buffer(data));
            boost::asio::write(target_socket, boost::asio::buffer(data, length));
        }
    } catch (std::exception& e) {
        std::cerr << "Exception in relay loop: " << e.what() << std::endl;
    }
}
