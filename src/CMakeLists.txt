cmake_minimum_required(VERSION 3.23)

project(DGPSBase)
cmake_policy(SET CMP0167 NEW)

find_package(Boost REQUIRED COMPONENTS system asio program_options)

add_executable(DGPSBaseStation)


target_sources(DGPSBaseStation PRIVATE
    main.cpp
    dgpsBase.h
    dgpsBase.cpp
)

target_link_libraries(DGPSBaseStation PRIVATE
    Boost::system
    Boost::asio
    Boost::program_options
)
