#include "dgpsBase.h"

#include <iostream>


dgpsBase::dgpsBase()
{
    std::cout << "dgpsBase constructor called." << std::endl;    


    try
    {        
        // initialise serial port
        _ioContext = new boost::asio::io_context();
        _serialPort = new boost::asio::serial_port(*_ioContext, "/dev/ttyUSB0"); 
    } 
    catch (std::exception& e)
    {
        std::cerr << "Exception in dgpsBase constructor: " << e.what() << std::endl;
    }
}

dgpsBase::~dgpsBase()
{
    std::cout << "dgpsBase destructor called." << std::endl;    
}

