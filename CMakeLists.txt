cmake_minimum_required(VERSION 3.10)
project(shooter)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_PREFIX_PATH "C:\\Users\\joach\\programming\\SFML\\lib\\cmake\\SFML")

find_package(SFML 2.6 REQUIRED COMPONENTS graphics window system)
include_directories(include)

set(SOURCES
    main.cpp
    entities/Entity.cpp
    utility/InputHandler.cpp
    entities/Bullet.cpp
    entities/Player.cpp
    entities/Enemy.cpp
    utility/TrajectoryCalculator.cpp
    entities/Healthbar.cpp
)

set(HEADERS
    include/Entity.h
    include/InputHandler.h
    include/Directions.h
    include/Bullet.h
    include/Player.h
    include/Enemy.h
    include/TrajectoryCalculator.h
    include/TrajectoryData.h
    include/Healthbar.h
    )

add_executable(shooter ${SOURCES} ${HEADERS})

target_link_libraries(shooter sfml-graphics sfml-window sfml-system)

add_custom_command(TARGET shooter POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/resources $<TARGET_FILE_DIR:shooter>/resources)
