cmake_minimum_required(VERSION 3.23)

project(DGPSBase)
if(POLICY CMP0167)
    cmake_policy(SET CMP0167 NEW)
endif()

find_package(Boost REQUIRED COMPONENTS program_options)
find_package(rclcpp REQUIRED)

add_executable(DGPSBaseStation)


target_sources(DGPSBaseStation PRIVATE
    main.cpp
    dgpsBase.h
    dgpsBase.cpp
)

target_link_libraries(DGPSBaseStation PRIVATE
    Boost::program_options
    rclcpp::rclcpp
)
