#include "dgpsBase.h"

dgpsBase::dgpsBase(const std::string& device, unsigned int baudRate)
    : rclcpp::Node("dgps_base"),
      _serialPort(_ioContext)
{
    RCLCPP_INFO(get_logger(), "Opening serial port %s at %u baud",
                device.c_str(), baudRate);
    _serialPort.open(device);
    _serialPort.set_option(
        boost::asio::serial_port_base::baud_rate(baudRate));
    RCLCPP_INFO(get_logger(), "Serial port opened");
}

dgpsBase::~dgpsBase()
{
    if (_serialPort.is_open())
    {
        boost::system::error_code error;
        _serialPort.close(error);
        if (error)
        {
            RCLCPP_ERROR(get_logger(), "Failed to close serial port: %s",
                         error.message().c_str());
        }
        else
        {
            RCLCPP_INFO(get_logger(), "Serial port closed");
        }
    }
}

