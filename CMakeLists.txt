cmake_minimum_required(VERSION 3.11)

project(Civitas VERSION 1.0.0 LANGUAGES CXX)

set(SOURCES
    src/city.cpp
    src/building.cpp
    src/buildingManager.cpp
    src/resourceManager.cpp
)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_PREFIX_PATH "/home/norbert/Qt/6.8.0/gcc_64")

find_package(Qt6 REQUIRED COMPONENTS Core Quick Gui Qml)

add_executable(${PROJECT_NAME} src/main.cpp ${SOURCES} qml/qml.qrc qml/main.qml)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Quick Qt6::Core Qt6::Gui Qt6::Qml)

include_directories("/home/norbert/Qt/6.8.0/gcc_64/include")

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(${PROJECT_NAME}-ut src/tests.cpp ${SOURCES})
target_link_libraries(${PROJECT_NAME}-ut PRIVATE Qt6::Core GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}-ut)
