# Install script for directory: /home/carlos/Instaladores/ParadisEO-2.0/moeo/src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xlibrariesx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64" TYPE STATIC_LIBRARY FILES "/home/carlos/Instaladores/ParadisEO-2.0/build/moeo/lib/libmoeo.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xheadersx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/paradiseo/moeo" TYPE FILE FILES "/home/carlos/Instaladores/ParadisEO-2.0/moeo/src/moeo")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xheadersx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/paradiseo/moeo" TYPE DIRECTORY FILES
    "/home/carlos/Instaladores/ParadisEO-2.0/moeo/src/acceptCrit"
    "/home/carlos/Instaladores/ParadisEO-2.0/moeo/src/algo"
    "/home/carlos/Instaladores/ParadisEO-2.0/moeo/src/archive"
    "/home/carlos/Instaladores/ParadisEO-2.0/moeo/src/comparator"
    "/home/carlos/Instaladores/ParadisEO-2.0/moeo/src/core"
    "/home/carlos/Instaladores/ParadisEO-2.0/moeo/src/distance"
    "/home/carlos/Instaladores/ParadisEO-2.0/moeo/src/diversity"
    "/home/carlos/Instaladores/ParadisEO-2.0/moeo/src/do"
    "/home/carlos/Instaladores/ParadisEO-2.0/moeo/src/explorer"
    "/home/carlos/Instaladores/ParadisEO-2.0/moeo/src/fitness"
    "/home/carlos/Instaladores/ParadisEO-2.0/moeo/src/hybridization"
    "/home/carlos/Instaladores/ParadisEO-2.0/moeo/src/metric"
    "/home/carlos/Instaladores/ParadisEO-2.0/moeo/src/replacement"
    "/home/carlos/Instaladores/ParadisEO-2.0/moeo/src/scalarStuffs"
    "/home/carlos/Instaladores/ParadisEO-2.0/moeo/src/selection"
    "/home/carlos/Instaladores/ParadisEO-2.0/moeo/src/utils"
    FILES_MATCHING REGEX "/[^/]*\\.h$")
endif()

