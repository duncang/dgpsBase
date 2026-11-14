#include <boost/program_options.hpp>

#include "dgpsBase.h"

#include <rclcpp/utilities.hpp>

#include <exception>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

int main(int argc, char* argv[])
{
    namespace po = boost::program_options;

    rclcpp::init(argc, argv);
    const auto logger = rclcpp::get_logger("dgps_base");

    po::options_description options("Options");
    options.add_options()
        ("help,h", "show this help message")
        ("device,d", po::value<std::string>()->required(),
         "serial port device file")
        ("baud,b", po::value<unsigned int>()->default_value(9600),
         "serial port baud rate");

    po::variables_map args;
    try
    {
        const auto unfiltered_args = rclcpp::remove_ros_arguments(argc, argv);
        std::vector<std::string> app_args;
        if (unfiltered_args.size() > 1)
        {
            app_args.assign(unfiltered_args.begin() + 1, unfiltered_args.end());
        }
        po::store(po::command_line_parser(app_args).options(options).run(),
                  args);

        if (args.count("help"))
        {
            std::cout << options << '\n';
            rclcpp::shutdown();
            return 0;
        }

        po::notify(args);
    }
    catch (const po::error& e)
    {
        RCLCPP_ERROR(logger, "Argument error: %s", e.what());
        std::cerr << options << '\n';
        rclcpp::shutdown();
        return 2;
    }

    const auto device = args["device"].as<std::string>();
    const auto baud = args["baud"].as<unsigned int>();
    if (baud == 0)
    {
        RCLCPP_ERROR(logger, "Baud rate must be greater than zero");
        rclcpp::shutdown();
        return 2;
    }

    RCLCPP_INFO(logger, "Starting DGPS base station");
    try
    {
        auto node = std::make_shared<dgpsBase>(device, baud);
        rclcpp::spin(node);
        RCLCPP_INFO(node->get_logger(), "Shutting down DGPS base station");
    }
    catch (const std::exception& e)
    {
        RCLCPP_FATAL(logger, "DGPS base station failed: %s", e.what());
        rclcpp::shutdown();
        return 1;
    }

    rclcpp::shutdown();
    return 0;
}
