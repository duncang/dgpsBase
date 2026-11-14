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
    if (_serialPort.is_open())
    {
        boost::system::error_code error;
        _serialPort.close(error);
        if (error)
        {
            std::cerr << "Failed to close serial port: "
                      << error.message() << '\n';
        }
    }
}

