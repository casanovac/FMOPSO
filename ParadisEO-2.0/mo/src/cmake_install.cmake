# Install script for directory: /home/carlos/Instaladores/ParadisEO-2.0/mo/src

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

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xheadersx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/paradiseo/mo" TYPE FILE FILES
    "/home/carlos/Instaladores/ParadisEO-2.0/mo/src/mo.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/mo/src/mo"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xheadersx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/paradiseo/mo" TYPE DIRECTORY FILES
    "/home/carlos/Instaladores/ParadisEO-2.0/mo/src/acceptCrit"
    "/home/carlos/Instaladores/ParadisEO-2.0/mo/src/algo"
    "/home/carlos/Instaladores/ParadisEO-2.0/mo/src/comparator"
    "/home/carlos/Instaladores/ParadisEO-2.0/mo/src/continuator"
    "/home/carlos/Instaladores/ParadisEO-2.0/mo/src/coolingSchedule"
    "/home/carlos/Instaladores/ParadisEO-2.0/mo/src/eval"
    "/home/carlos/Instaladores/ParadisEO-2.0/mo/src/explorer"
    "/home/carlos/Instaladores/ParadisEO-2.0/mo/src/memory"
    "/home/carlos/Instaladores/ParadisEO-2.0/mo/src/neighborhood"
    "/home/carlos/Instaladores/ParadisEO-2.0/mo/src/perturb"
    "/home/carlos/Instaladores/ParadisEO-2.0/mo/src/problems"
    "/home/carlos/Instaladores/ParadisEO-2.0/mo/src/sampling"
    FILES_MATCHING REGEX "/[^/]*\\.h$")
endif()

