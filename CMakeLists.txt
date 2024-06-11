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
    ui_param//paramwin_anglesensor.cpp ui_param/paramwin_anglesensor.h ui_param/paramwin_anglesensor.ui
    ui_param/paramwin_angleencoder.cpp ui_param/paramwin_angleencoder.h ui_param/paramwin_angleencoder.ui
    ui_param/paramwin_proximityswitch.cpp ui_param/paramwin_proximityswitch.h ui_param/paramwin_proximityswitch.ui
    ui_param/paramwin_pressuresensor.cpp ui_param/paramwin_pressuresensor.h ui_param/paramwin_pressuresensor.ui

    ui_show/showwin_measureresis.cpp ui_show/showwin_measureresis.h ui_show/showwin_measureresis.ui

    data_acquire/dataacquireai.cpp data_acquire/dataacquireai.h
    data_acquire/dataacquiredi.cpp data_acquire/dataacquiredi.h
    data_acquire/dataacquireci.cpp data_acquire/dataacquireci.h
    data_acquire/lowpassfilter.cpp data_acquire/lowpassfilter.h

    tools/NIDAQmx.h
    tools/qcustomplot.h tools/qcustomplot.cpp
    tools/simpleQtLogger.h tools/simpleQtLogger.cpp

    sensors/anglesensor.cpp sensors/anglesensor.h

    assist_func/assist.cpp assist_func/assist.h

    tele_com/modbus.cpp tele_com/modbus.h
    tele_com/serialportcom.cpp tele_com/serialportcom.h  
)

target_include_directories(Proj_Sensor PRIVATE
   ./data_acquire
   ./tools
   ./assist_func
   ./tele_com
   ./ui_param
   ./ui_show
)

target_link_libraries(Proj_Sensor PRIVATE Qt5::Widgets
    Qt5::PrintSupport
    Qt5::SerialPort
    Qt5::SerialBus
    ${CMAKE_CURRENT_SOURCE_DIR}/tools/NIDAQmx.lib)

