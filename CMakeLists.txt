# cmake .. -DCMAKE_BUILD_TYPE=Release
# cmake --build .
# cmake --install .

cmake_minimum_required(VERSION 3.10)

# definition of the library name
set(PROJECT_NAME WinSpeak)
set(PROJECT_VERSION 1.1.0)

project(${PROJECT_NAME} VERSION ${PROJECT_VERSION} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Force a default build type if not defined
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()

set(SOURCES
    src/WinSpeak.cpp
    src/AudioDeviceManager.cpp

)

set(HEADERS
    include/${PROJECT_NAME}/WinSpeak.hpp
    include/${PROJECT_NAME}/AudioDeviceManager.hpp
    include/${PROJECT_NAME}/IAudioProvider.hpp
    include/${PROJECT_NAME}/IMuteControl.hpp
    include/${PROJECT_NAME}/IVolumeControl.hpp

)

# Create the static library
add_library(${PROJECT_NAME} STATIC ${SOURCES} ${HEADERS})

# Add compilation options (e.g. to enable optimizations)
target_compile_options(${PROJECT_NAME} PRIVATE     
    $<$<CONFIG:Debug>:-g>
    $<$<CONFIG:Debug>:-Wall>
    $<$<CONFIG:Debug>:-Wextra>
    $<$<CONFIG:Release>:-std=c++20>
    $<$<CONFIG:Release>:-O2>
    $<$<CONFIG:Release>:-Wall>
    $<$<CONFIG:Release>:-Wextra>
)

# Link options when compiling the static library
# Oleaut32
target_link_libraries(${PROJECT_NAME} PRIVATE 
    ole32   
    uuid 
)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)


# Set the output directory for the compiled library
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Set the installation location
set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/${PROJECT_NAME})

# Add a folder for header files
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_PREFIX}/include)

# Install the library in the lib/ folder
install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)

# part of the unit test

enable_testing()
add_subdirectory(tests)
