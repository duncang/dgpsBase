#include <boost/program_options.hpp>

#include "dgpsBase.h"

#include <exception>
#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
    namespace po = boost::program_options;

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
        po::store(po::parse_command_line(argc, argv, options), args);

        if (args.count("help"))
        {
            std::cout << options << '\n';
            return 0;
        }

        po::notify(args);
    }
    catch (const po::error& e)
    {
        std::cerr << "Argument error: " << e.what() << "\n\n"
                  << options << '\n';
        return 2;
    }

    const auto device = args["device"].as<std::string>();
    const auto baud = args["baud"].as<unsigned int>();
    if (baud == 0)
    {
        std::cerr << "Baud rate must be greater than zero.\n";
        return 2;
    }

    std::cout << "Starting dgpsBase application..." << std::endl;

    // setup logging

    // load and process configuration

    // setup signal handling

    // setup control API

    // setup ROS connection

    // setup dgpsBase Constructor and pass ROS connection
    try
    {
        dgpsBase dgpsBase(device, baud);

        // run application main thread

        // tear down and gracefully exit
        std::cout << "Exiting dgpsBase application..." << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Failed to start dgpsBase: " << e.what() << '\n';
        return 1;
    }

    return 0;
}
