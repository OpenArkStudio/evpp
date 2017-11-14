evpp for ArkGame
---

This project is forked from [Qihoo360/evpp](https://github.com/Qihoo360/evpp) for ArkGame, changed the compiling step and dependencies.

For more informations, please visit the original repository [Qihoo360/evpp](https://github.com/Qihoo360/evpp)

Thanks for this excellent project.

# Compiling step

## Windows
```
git clone evpp
cd path/to/evpp
md build
cd build
cmake -G "Visual Studio 14 Win64" -DLIBEVENT_DIR=path/to/libevent/ -DLIBEVENT_LIB_DIR=path/to/libevent/library/dir ..
start evpp.sln
```

## Linux
```
git clone evpp
cd path/to/evpp
mkdir build && cd build
cmake -G "Unix Makefiles" -DLIBEVENT_DIR=path/to/libevent/ -DLIBEVENT_LIB_DIR=path/to/libevent/library/dir ..
make
```

# Plan
**Will add [concurrent queue](https://github.com/cameron314/concurrentqueue) for evpp.**

# Examples

## An echo TCP server

```cpp
#include <evpp/tcp_server.h>
#include <evpp/buffer.h>
#include <evpp/tcp_conn.h>

int main(int argc, char* argv[]) {
    std::string addr = "0.0.0.0:9099";
    int thread_num = 4;
    evpp::EventLoop loop;
    evpp::TCPServer server(&loop, addr, "TCPEchoServer", thread_num);
    server.SetMessageCallback([](const evpp::TCPConnPtr& conn,
                                 evpp::Buffer* msg,
                                 evpp::Timestamp ts) {
        conn->Send(msg);
    });
    server.SetConnectionCallback([](const evpp::TCPConnPtr& conn) {
        if (conn->IsConnected()) {
            LOG_INFO << "A new connection from " << conn->remote_addr();
        } else {
            LOG_INFO << "Lost the connection from " << conn->remote_addr();
        }
    });
    server.Init();
    server.Start();
    loop.Run();
    return 0;
}
```

### An echo HTTP server

```cpp
#include <evpp/http/http_server.h>

int main(int argc, char* argv[]) {
    std::vector<int> ports = { 9009, 23456, 23457 };
    int thread_num = 2;
    evpp::http::Server server(thread_num);
    server.RegisterHandler("/echo",
                           [](evpp::EventLoop* loop,
                              const evpp::http::ContextPtr& ctx,
                              const evpp::http::HTTPSendResponseCallback& cb) {
        cb(ctx->body().ToString()); }
    );
    server.Init(ports);
    server.Start();
    while (!server.IsStopped()) {
        usleep(1);
    }
    return 0;
}

```


### An echo UDP server

```cpp
#include <evpp/udp/udp_server.h>
#include <evpp/udp/udp_message.h>

int main(int argc, char* argv[]) {
    std::vector<int> ports = { 1053, 5353 };
    evpp::udp::Server server;
    server.SetMessageHandler([](evpp::EventLoop* loop, evpp::udp::MessagePtr& msg) {
        evpp::udp::SendMessage(msg);
    });
    server.Init(ports);
    server.Start();

    while (!server.IsStopped()) {
        usleep(1);
    }
    return 0;
}
```

### More examples

Please see the source code in [`examples`](https://github.com/Qihoo360/evpp/tree/master/examples).