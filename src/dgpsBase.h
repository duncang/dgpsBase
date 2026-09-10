#include <boost/asio/serial_port.hpp>

class dgpsBase
{

    public:
    dgpsBase ();
    ~dgpsBase();


    private:
    boost::asio::io_context *_ioContext;
    boost::asio::serial_port *_serialPort;
    void mainTask();

};
