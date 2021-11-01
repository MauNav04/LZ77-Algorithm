cmake_minimum_required(VERSION 3.20)

project(LZ77-Tool VERSION 0.1)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_PREFIX_PATH $ENV{HOME}/Qt/6.2.0/gcc_64/lib/cmake)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Gui Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Gui Widgets REQUIRED)

set(PROJECT_SOURCES
        src/main.cpp
        src/ui/mainscreen.cpp
        src/ui/mainscreen.h
        src/ui/mainscreen.ui)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(LZ77-Tool
            MANUAL_FINALIZATION
            ${PROJECT_SOURCES}
            )
else()
    if(ANDROID)
        add_library(LZ77-Tool SHARED
                ${PROJECT_SOURCES}
                )
    else()
        add_executable(LZ77-Tool
                ${PROJECT_SOURCES}
                )
    endif()
endif()

target_link_libraries(LZ77-Tool PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Gui Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(LZ77-Tool PROPERTIES
        MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
        MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
        MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
        )

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(LZ77-Tool)
endif()