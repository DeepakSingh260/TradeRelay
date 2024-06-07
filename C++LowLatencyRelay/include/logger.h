    #ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <fstream>
#include <string>
#include <mutex>

class Logger {
public:
    static Logger& getInstance() {
        static Logger instance;
        return instance;
    }

    void log(const std::string& message) {
        std::lock_guard<std::mutex> guard(mutex_);
        log_file_ << message << std::endl;
    }

private:
    Logger() : log_file_("logfile.log", std::ios::app) {}
    ~Logger() { log_file_.close(); }

    std::ofstream log_file_;
    std::mutex mutex_;
};

#endif // LOGGER_H
