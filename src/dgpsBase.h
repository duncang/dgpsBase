#include <boost/asio/io_context.hpp>
#include <boost/asio/serial_port.hpp>
#include <string>

class dgpsBase
{

    public:
    dgpsBase(const std::string& device, unsigned int baudRate);
    ~dgpsBase();


    private:
    boost::asio::io_context _ioContext;
    boost::asio::serial_port _serialPort;
    void mainTask();

};
