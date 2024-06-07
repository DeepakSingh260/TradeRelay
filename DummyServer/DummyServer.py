import socket
import time
import random

def generate_stock_data():
    stocks = ["AAPL", "GOOGL", "MSFT", "AMZN", "TSLA"]
    stock = random.choice(stocks)
    price = round(random.uniform(100, 1500), 2)
    return f"{stock}: ${price}"

def start_source_server(host, port):
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as server_socket:
        server_socket.bind((host, port))
        server_socket.listen()
        print(f"Source server listening on {host}:{port}")
        
        while True:
            conn, addr = server_socket.accept()
            with conn:
                print(f"Connected by {addr}")
                while True:
                    stock_data = generate_stock_data()
                    conn.sendall(stock_data.encode())
                    print(f"Sent: {stock_data}")
                    time.sleep(1)  # Wait for a second before sending the next data

if __name__ == "__main__":
    start_source_server("127.0.0.1", 8888)
