#include "client.hpp"

TCPClient::TCPClient(uint32_t host, uint16_t port)
    :   _io_contex(std::make_unique<boost::asio::io_context>()),
        _socket(std::make_unique<boost::asio::ip::tcp::socket>(*_io_contex))
{
    boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::address_v4(host), port);
    _socket->connect(endpoint);
}

void TCPClient::send(const std::vector<uint8_t>& data)
{
    _socket->write_some(boost::asio::buffer(data));
}

std::vector<uint8_t> TCPClient::receive()
{
    std::vector<uint8_t> data;
    data.resize(1024);
    _socket->read_some(boost::asio::buffer(data));
    return data;
}

void TCPClient::close()
{
    _socket->close();
}

TCPClient::~TCPClient()
{
    close();
}
