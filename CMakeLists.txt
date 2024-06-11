cmake_minimum_required(VERSION 3.5)

project(Proj_Sensor VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 REQUIRED COMPONENTS Widgets PrintSupport SerialPort SerialBus)

add_executable(Proj_Sensor
    main.cpp
    widget.cpp widget.h widget.ui
    mainwindow.cpp mainwindow.h mainwindow.ui
    ui/paramwin_anglesensor.cpp ui/paramwin_anglesensor.h ui/paramwin_anglesensor.ui
    ui/paramwin_angleencoder.cpp ui/paramwin_angleencoder.h ui/paramwin_angleencoder.ui
    ui/paramwin_proximityswitch.cpp ui/paramwin_proximityswitch.h ui/paramwin_proximityswitch.ui
    ui/paramwin_pressuresensor.cpp ui/paramwin_pressuresensor.h ui/paramwin_pressuresensor.ui


    data_acquire/dataacquireai.cpp data_acquire/dataacquireai.h
    data_acquire/dataacquiredi.cpp data_acquire/dataacquiredi.h
    data_acquire/dataacquireci.cpp data_acquire/dataacquireci.h
    data_acquire/lowpassfilter.cpp data_acquire/lowpassfilter.h

    tools/NIDAQmx.h
    tools/qcustomplot.h tools/qcustomplot.cpp
    tools/simpleQtLogger.h tools/simpleQtLogger.cpp

    assist_func/assist.cpp assist_func/assist.h

    tele_com/modbus.cpp tele_com/modbus.h
    tele_com/serialportcom.cpp tele_com/serialportcom.h  
)

target_include_directories(Proj_Sensor PRIVATE
   ./data_acquire
   ./tools
   ./assist_func
   ./tele_com
   ./ui
)

target_link_libraries(Proj_Sensor PRIVATE Qt5::Widgets
    Qt5::PrintSupport
    Qt5::SerialPort
    Qt5::SerialBus
    ${CMAKE_CURRENT_SOURCE_DIR}/tools/NIDAQmx.lib)

