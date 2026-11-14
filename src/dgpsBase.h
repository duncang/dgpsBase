#include <boost/asio/io_context.hpp>
#include <boost/asio/serial_port.hpp>
#include <rclcpp/rclcpp.hpp>
#include <string>

class dgpsBase : public rclcpp::Node
{

    public:
    dgpsBase(const std::string& device, unsigned int baudRate);
    ~dgpsBase();


    private:
    boost::asio::io_context _ioContext;
    boost::asio::serial_port _serialPort;
    void mainTask();

};
