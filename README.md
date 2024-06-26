

# Low Latency Trade Relay Application

## Overview

This project is a Low Latency Trade Relay application written in C++ using the Boost.Asio library for asynchronous I/O operations. The application is designed to relay trade data between two servers with minimal latency, making it suitable for real-time trading systems.

## Features

- **Asynchronous I/O**: Utilizes Boost.Asio for non-blocking, asynchronous network operations.
- **Concurrent Connections**: Handles multiple source-target pairs concurrently.
- **Python Integration**: Includes Python-based dummy servers for testing the relay functionality.
- **Robust and Scalable**: Designed to handle continuous streams of stock data efficiently.

## Directory Structure

```
.
├── CMakeLists.txt
├── README.md
├── src
│   ├── main.cpp
│   ├── relay.cpp
│   ├── relay.h
├── test
│   ├── server_source.py
│   └── server_target.py
```

## Getting Started

### Prerequisites

- **C++17** or later
- **CMake** 3.12 or later
- **Boost** library (installed via vcpkg or other methods)
- **Python** 3.x (for running the dummy servers)

### Building the Project

1. **Install Boost using vcpkg**:

    ```bash
    git clone https://github.com/microsoft/vcpkg.git
    cd vcpkg
    ./bootstrap-vcpkg.bat
    ./vcpkg integrate install
    ./vcpkg install boost-asio
    ```

2. **Clone the Project**:

    ```bash
    git clone https://github.com/yourusername/LowLatencyTradeRelay.git
    cd LowLatencyTradeRelay
    ```

3. **Build the Project**:

    ```bash
    mkdir build
    cd build
    cmake -DCMAKE_TOOLCHAIN_FILE=C:/path/to/vcpkg/scripts/buildsystems/vcpkg.cmake ..
    cmake --build .
    ```

### Running the Dummy Servers

1. **Source Server**:

    ```bash
    python test/server_source.py
    ```

2. **Target Server**:

    ```bash
    python test/server_target.py
    ```

### Running the Trade Relay

```bash
./LowLatencyTradeRelayExecutable
```

## Code Explanation

### `relay.h`

Defines the `TradeRelay` class, which encapsulates the logic for relaying trade data between source and target servers.

### `relay.cpp`

Implements the `TradeRelay` class:

- **Constructor**: Initializes the source and target IP addresses and ports.
- **start()**: Sets up asynchronous connections and starts the event loop.
- **async_read()**: Initiates an asynchronous read operation.
- **async_write()**: Initiates an asynchronous write operation.
- **handle_read()**: Handles the completion of a read operation and starts the write operation.
- **handle_write()**: Handles the completion of a write operation and starts the next read operation.

### `main.cpp`

Creates instances of `TradeRelay` and starts them in separate threads.

### `server_source.py`

A simple Python server that sends continuous streams of dummy stock data to clients.

### `server_target.py`

A simple Python server that receives data from the relay and prints it to the console.

## What I Learned

- **Network Programming**: Gained proficiency in asynchronous I/O operations using Boost.Asio.
- **Concurrency**: Implemented concurrent data handling using threads and asynchronous mechanisms.
- **System Design**: Designed and implemented a robust and scalable system for real-time data relay.
- **Python Integration**: Used Python for testing and simulating real-world scenarios.

## Future Enhancements

- **Error Handling**: Improve error handling and robustness.
- **Unit Testing**: Add unit tests for the C++ code.
- **Performance Metrics**: Measure and optimize performance (e.g., latency, throughput).
- **Advanced Features**: Implement features like load balancing, encryption for data transmission, or dynamic relay configuration.

## Conclusion

This project demonstrates a strong understanding of network programming, concurrency, and real-time data processing. It provides a solid foundation for building more complex and high-performance trading systems.

Feel free to reach out if you have any questions or suggestions!


