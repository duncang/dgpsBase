cmake_minimum_required(VERSION 3.23)

project(DGPSBase)

add_executable(DGPSBaseStation)


target_sources(DGPSBaseStation PRIVATE
    main.cpp
    dgpsBase.h
    dgpsBase.cpp
)

