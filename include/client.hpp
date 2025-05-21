#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <boost/asio/io_context.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <vector>
#include <memory>

class TCPClient
{
    using io_contex_p = std::unique_ptr<boost::asio::io_context>;
    using socket_p = std::unique_ptr<boost::asio::ip::tcp::socket>;

public:
    TCPClient (uint32_t host, uint16_t port);

    void send(const std::vector<uint8_t>& data);
    std::vector<uint8_t> receive();

    void close();

    ~TCPClient();

private:
    io_contex_p _io_contex;
    socket_p _socket;
};

#endif // !CLIENT_HPP