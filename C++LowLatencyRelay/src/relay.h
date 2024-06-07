#ifndef RELAY_H
#define RELAY_H

#include <string>

class TradeRelay {
public:
    TradeRelay(const std::string& source_ip, int source_port, const std::string& target_ip, int target_port);
    void start();

private:
    void relay_loop();

    std::string source_ip_;
    int source_port_;
    std::string target_ip_;
    int target_port_;
};

#endif // RELAY_H