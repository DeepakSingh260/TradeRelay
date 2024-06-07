#ifndef TRADE_DATA_H
#define TRADE_DATA_H

#include <string>

struct TradeData {
    std::string symbol;
    double price;
    int volume;
};

#endif // TRADE_DATA_H
