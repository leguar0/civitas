cmake_minimum_required(VERSION 3.17)

project(Civitas VERSION 1.0.0 LANGUAGES CXX)

set(
    SOURCE
    qml/qml.qrc
    qml/main.qml
    src/city.cpp
    src/building.cpp
)

set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core Quick Qml)
qt_standard_project_setup()

qt_add_executable(${PROJECT_NAME} ${SOURCE} src/main.cpp)

#add_executable(${PROJECT_NAME} ${SOURCE} src/main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Qml Qt6::Quick Qt6::Core)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(${PROJECT_NAME}-ut src/tests.cpp ${SOURCE})
target_link_libraries(${PROJECT_NAME}-ut GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}-ut)
