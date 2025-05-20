#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <boost/asio.hpp>
#include <vector>

class TCPClient
{
public:
    TCPClient(boost::asio::io_contex& _io_contex, uint32_t host, uint16_t port);

    void send(const std::vecotr<uint8_t>& data);
    std::vecotr<uint8_t> receive();

    void close();

    ~TCPClient();
private:
    boost::asio::io_contex& _io_contex;
    tcp::socket _socket;
};

#endif // !CLIENT_HPP