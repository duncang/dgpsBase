

DGPS Base Station Processor

Developed by Duncan Greer <duncangreer@gmail.com>

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

The application shall log application execution information using the log4cxx framework. 


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




