

DGPS Base Station Processor

Developed by Duncan Greer <duncangreer@gmail.com>

Command Line

The serial device is required via `--device`; the baud rate defaults to `9600`.
Use `--help` to list the available options.

    DGPSBaseStation --device /dev/ttyUSB1 --baud 115200

Docker Build

The Docker image uses ROS 2 Lyrical. Build it from the repository root:

    docker build -t dgps-base:lyrical .

Run the application with the serial device passed through to the container:

    docker run --rm --device=/dev/ttyUSB1 dgps-base:lyrical --device /dev/ttyUSB1 --baud 115200

For ROS 2 communication with other containers on Linux, use the same ROS
domain ID and consider adding `--network host` to the `docker run` command so
DDS discovery can reach the other ROS nodes.

Overview

This application processes raw measurements from at least one GPS reference station receivers and produces DGPS corrections.

Raw measurements are sourced from a ROS container.
Corrections are published to a ROS container ready for broadcast by a correction distribution service. 



Scope


Requirements

ROS Connections

The application shall read raw measurement data from a ROS container.

The application shall publish correction data to a ROS container.

DPGS Correction Update Rate

The application shall publish corrections at a minimum rate of 1 Hz when valid correction data is available for processing.

The application shall publish status information to a ROS container. 

The application shall publish corrections with a latency of less than 500 milliseconds from the time of validity of the raw measurement data used to generate the corrections.  

The application shall perform quality checks on correction data before publishing.

The probability of the application publishing erroneous correction data shall be less than 1e-8 per measurement.

The application shall generate all correction parameters required to broadcast correction data in accordance with RTCA DO-217A Type 1.

The application shall accept POSIX signals for shutdown control.

The application shall enable application control via a UDP socket interface (called the "control socket interface"). 

The application shall be configurable via a configuration file.

The application configuration file shall be in [TBD - JSON vs XML vs YAML format].

The application configuration shall be updatable at runtime via the application control socket interface. 

The application shall accept program arguments for selection of the configuration file.

The application shall accept program arguments for enabling of the control socket interface.

The application shall use ROS 2 logging through `rclcpp`. By default, ROS 2
writes logs to the console and `~/.ros/log`, without requiring a ROS master.
Set `ROS_LOG_DIR` to choose a different directory, or pass ROS logging options
after `--ros-args`, for example:

    ROS_LOG_DIR=/var/log/dgpsBase DGPSBaseStation --device /dev/ttyUSB1 --ros-args --log-level info


DGPS Correction Generation

The application shall generate pseudorange corrections.

The application shall generate pseodurange rate corrections.

The application shall generate valid corrections through end of week rollover events.


Multipath Detection

The application shall detect if raw measurements are affected by excessive multipath error.

Integrity Checking

The application shall perform integrity checks on raw measurement data.

The application shall perform integrity checks on broadcast ephemeris data.



Unit Testing 

Applicastion unit tests shall be generated using the cppUnit framework. 


Integration Testing




