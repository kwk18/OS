all: client server

client:
	g++ client.cpp -o client -lzmq -std=c++17

server:
	g++ server.cpp -o server -lzmq -std=c++17

clean:
	rm client server
