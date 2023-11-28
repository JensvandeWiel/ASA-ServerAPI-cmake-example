# Set the minimum required CMake version
cmake_minimum_required(VERSION 3.28)

# Set up the project
project(ASAApi_example)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Source files organization
set(Header_Files

)
source_group("Header Files" FILES ${Header_Files})

set(Source_Files

)
source_group("Source Files" FILES ${Source_Files})

set(Source_Files__Helpers

)
source_group("Source Files\\Helpers" FILES ${Source_Files__Helpers})

set(Source_Files__Plugin
        Plugin/main.cpp

)
source_group("Source Files\\Plugin" FILES ${Source_Files__Plugin})

# Target: Create a shared library
add_library(${PROJECT_NAME} SHARED ${Header_Files}
        ${Source_Files}
        ${Source_Files__Helpers}
        ${Source_Files__Plugin})

# Include directories
target_include_directories(${PROJECT_NAME} PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/ServerAPI/AsaApi/Core/Public;"
        "${CMAKE_CURRENT_SOURCE_DIR}/ServerAPI/AsaApi/Core/Public/API;"
        "${CMAKE_CURRENT_SOURCE_DIR}/ServerAPI/AsaApi/Core/Public/API/ARK;"
        "${CMAKE_CURRENT_SOURCE_DIR}/ServerAPI/AsaApi/Core/Public/API/UE;"
        "${CMAKE_CURRENT_SOURCE_DIR}/ServerAPI/AsaApi/Core/Public/Logger;"
        "${CMAKE_CURRENT_SOURCE_DIR}/ServerAPI/AsaApi/vcpkg_installed/x64-windows-static-md/x64-windows-static-md/include"
        "${CMAKE_CURRENT_SOURCE_DIR}/.;"
        "${CMAKE_CURRENT_SOURCE_DIR}/Plugin;"
        "${CMAKE_CURRENT_SOURCE_DIR}/Helpers"
)

# Compile definitions
target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:Debug>:DEBUG_PLUGIN>"
        "NDEBUG;"
        "${PROJECT_NAME}_EXPORTS;"
        "_WINDOWS;"
        "_USRDLL;"
        "UNICODE;"
        "_UNICODE"
)

# Link directories
target_link_directories(${PROJECT_NAME} PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/libs"
)

# Link libs
target_link_libraries(${PROJECT_NAME} PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/ServerAPI/out_lib/AsaApi.lib"
)