cmake_minimum_required(VERSION 3.25)
project(Internet_bar_charge_management_system)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Internet_bar_charge_management_system
        BillingManagement.cpp
        BillingStandardManagement.cpp
        CardManagement.cpp
        CostManagement.cpp
        main.cpp
        operate.cpp
        operate.h
        QueryStatistics.cpp
        RightsManagement.cpp
        System.cpp)
