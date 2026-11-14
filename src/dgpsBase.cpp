#include "dgpsBase.h"

#include <iostream>


dgpsBase::dgpsBase(const std::string& device, unsigned int baudRate)
    : _serialPort(_ioContext)
{
    std::cout << "dgpsBase constructor called." << std::endl;
    _serialPort.open(device);
    _serialPort.set_option(
        boost::asio::serial_port_base::baud_rate(baudRate));
}

dgpsBase::~dgpsBase()
{
    std::cout << "dgpsBase destructor called." << std::endl;
}

