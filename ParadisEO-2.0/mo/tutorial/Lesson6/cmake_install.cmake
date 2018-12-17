# Install script for directory: /home/carlos/Instaladores/ParadisEO-2.0/mo/tutorial/Lesson6

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

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xexamplesx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/share/paradiseo/mo/tutorial/Lesson6/adaptiveWalks" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/share/paradiseo/mo/tutorial/Lesson6/adaptiveWalks")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/share/paradiseo/mo/tutorial/Lesson6/adaptiveWalks"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/share/paradiseo/mo/tutorial/Lesson6/adaptiveWalks")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/share/paradiseo/mo/tutorial/Lesson6" TYPE EXECUTABLE FILES "/home/carlos/Instaladores/ParadisEO-2.0/build/mo/tutorial/Lesson6/adaptiveWalks")
  if(EXISTS "$ENV{DESTDIR}/share/paradiseo/mo/tutorial/Lesson6/adaptiveWalks" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/share/paradiseo/mo/tutorial/Lesson6/adaptiveWalks")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/share/paradiseo/mo/tutorial/Lesson6/adaptiveWalks")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xexamplesx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/share/paradiseo/mo/tutorial/Lesson6/autocorrelation" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/share/paradiseo/mo/tutorial/Lesson6/autocorrelation")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/share/paradiseo/mo/tutorial/Lesson6/autocorrelation"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/share/paradiseo/mo/tutorial/Lesson6/autocorrelation")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/share/paradiseo/mo/tutorial/Lesson6" TYPE EXECUTABLE FILES "/home/carlos/Instaladores/ParadisEO-2.0/build/mo/tutorial/Lesson6/autocorrelation")
  if(EXISTS "$ENV{DESTDIR}/share/paradiseo/mo/tutorial/Lesson6/autocorrelation" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/share/paradiseo/mo/tutorial/Lesson6/autocorrelation")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/share/paradiseo/mo/tutorial/Lesson6/autocorrelation")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xexamplesx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/share/paradiseo/mo/tutorial/Lesson6/densityOfStates" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/share/paradiseo/mo/tutorial/Lesson6/densityOfStates")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/share/paradiseo/mo/tutorial/Lesson6/densityOfStates"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/share/paradiseo/mo/tutorial/Lesson6/densityOfStates")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/share/paradiseo/mo/tutorial/Lesson6" TYPE EXECUTABLE FILES "/home/carlos/Instaladores/ParadisEO-2.0/build/mo/tutorial/Lesson6/densityOfStates")
  if(EXISTS "$ENV{DESTDIR}/share/paradiseo/mo/tutorial/Lesson6/densityOfStates" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/share/paradiseo/mo/tutorial/Lesson6/densityOfStates")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/share/paradiseo/mo/tutorial/Lesson6/densityOfStates")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xexamplesx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/share/paradiseo/mo/tutorial/Lesson6/fdc" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/share/paradiseo/mo/tutorial/Lesson6/fdc")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/share/paradiseo/mo/tutorial/Lesson6/fdc"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/share/paradiseo/mo/tutorial/Lesson6/fdc")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/share/paradiseo/mo/tutorial/Lesson6" TYPE EXECUTABLE FILES "/home/carlos/Instaladores/ParadisEO-2.0/build/mo/tutorial/Lesson6/fdc")
  if(EXISTS "$ENV{DESTDIR}/share/paradiseo/mo/tutorial/Lesson6/fdc" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/share/paradiseo/mo/tutorial/Lesson6/fdc")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/share/paradiseo/mo/tutorial/Lesson6/fdc")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xexamplesx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/share/paradiseo/mo/tutorial/Lesson6/fitnessCloud" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/share/paradiseo/mo/tutorial/Lesson6/fitnessCloud")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/share/paradiseo/mo/tutorial/Lesson6/fitnessCloud"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/share/paradiseo/mo/tutorial/Lesson6/fitnessCloud")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/share/paradiseo/mo/tutorial/Lesson6" TYPE EXECUTABLE FILES "/home/carlos/Instaladores/ParadisEO-2.0/build/mo/tutorial/Lesson6/fitnessCloud")
  if(EXISTS "$ENV{DESTDIR}/share/paradiseo/mo/tutorial/Lesson6/fitnessCloud" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/share/paradiseo/mo/tutorial/Lesson6/fitnessCloud")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/share/paradiseo/mo/tutorial/Lesson6/fitnessCloud")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xexamplesx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/share/paradiseo/mo/tutorial/Lesson6/neutralDegree" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/share/paradiseo/mo/tutorial/Lesson6/neutralDegree")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/share/paradiseo/mo/tutorial/Lesson6/neutralDegree"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/share/paradiseo/mo/tutorial/Lesson6/neutralDegree")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/share/paradiseo/mo/tutorial/Lesson6" TYPE EXECUTABLE FILES "/home/carlos/Instaladores/ParadisEO-2.0/build/mo/tutorial/Lesson6/neutralDegree")
  if(EXISTS "$ENV{DESTDIR}/share/paradiseo/mo/tutorial/Lesson6/neutralDegree" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/share/paradiseo/mo/tutorial/Lesson6/neutralDegree")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/share/paradiseo/mo/tutorial/Lesson6/neutralDegree")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xexamplesx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/share/paradiseo/mo/tutorial/Lesson6/neutralWalk" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/share/paradiseo/mo/tutorial/Lesson6/neutralWalk")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/share/paradiseo/mo/tutorial/Lesson6/neutralWalk"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/share/paradiseo/mo/tutorial/Lesson6/neutralWalk")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/share/paradiseo/mo/tutorial/Lesson6" TYPE EXECUTABLE FILES "/home/carlos/Instaladores/ParadisEO-2.0/build/mo/tutorial/Lesson6/neutralWalk")
  if(EXISTS "$ENV{DESTDIR}/share/paradiseo/mo/tutorial/Lesson6/neutralWalk" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/share/paradiseo/mo/tutorial/Lesson6/neutralWalk")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/share/paradiseo/mo/tutorial/Lesson6/neutralWalk")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xexamplesx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/share/paradiseo/mo/tutorial/Lesson6/sampling" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/share/paradiseo/mo/tutorial/Lesson6/sampling")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/share/paradiseo/mo/tutorial/Lesson6/sampling"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/share/paradiseo/mo/tutorial/Lesson6/sampling")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/share/paradiseo/mo/tutorial/Lesson6" TYPE EXECUTABLE FILES "/home/carlos/Instaladores/ParadisEO-2.0/build/mo/tutorial/Lesson6/sampling")
  if(EXISTS "$ENV{DESTDIR}/share/paradiseo/mo/tutorial/Lesson6/sampling" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/share/paradiseo/mo/tutorial/Lesson6/sampling")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/share/paradiseo/mo/tutorial/Lesson6/sampling")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xexamplesx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/share/paradiseo/mo/tutorial/Lesson6/testMetropolisHasting" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/share/paradiseo/mo/tutorial/Lesson6/testMetropolisHasting")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/share/paradiseo/mo/tutorial/Lesson6/testMetropolisHasting"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/share/paradiseo/mo/tutorial/Lesson6/testMetropolisHasting")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/share/paradiseo/mo/tutorial/Lesson6" TYPE EXECUTABLE FILES "/home/carlos/Instaladores/ParadisEO-2.0/build/mo/tutorial/Lesson6/testMetropolisHasting")
  if(EXISTS "$ENV{DESTDIR}/share/paradiseo/mo/tutorial/Lesson6/testMetropolisHasting" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/share/paradiseo/mo/tutorial/Lesson6/testMetropolisHasting")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/share/paradiseo/mo/tutorial/Lesson6/testMetropolisHasting")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xexamplesx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/share/paradiseo/mo/tutorial/Lesson6/testRandomNeutralWalk" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/share/paradiseo/mo/tutorial/Lesson6/testRandomNeutralWalk")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/share/paradiseo/mo/tutorial/Lesson6/testRandomNeutralWalk"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/share/paradiseo/mo/tutorial/Lesson6/testRandomNeutralWalk")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/share/paradiseo/mo/tutorial/Lesson6" TYPE EXECUTABLE FILES "/home/carlos/Instaladores/ParadisEO-2.0/build/mo/tutorial/Lesson6/testRandomNeutralWalk")
  if(EXISTS "$ENV{DESTDIR}/share/paradiseo/mo/tutorial/Lesson6/testRandomNeutralWalk" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/share/paradiseo/mo/tutorial/Lesson6/testRandomNeutralWalk")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/share/paradiseo/mo/tutorial/Lesson6/testRandomNeutralWalk")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xexamplesx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/share/paradiseo/mo/tutorial/Lesson6/testRandomWalk" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/share/paradiseo/mo/tutorial/Lesson6/testRandomWalk")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/share/paradiseo/mo/tutorial/Lesson6/testRandomWalk"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/share/paradiseo/mo/tutorial/Lesson6/testRandomWalk")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/share/paradiseo/mo/tutorial/Lesson6" TYPE EXECUTABLE FILES "/home/carlos/Instaladores/ParadisEO-2.0/build/mo/tutorial/Lesson6/testRandomWalk")
  if(EXISTS "$ENV{DESTDIR}/share/paradiseo/mo/tutorial/Lesson6/testRandomWalk" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/share/paradiseo/mo/tutorial/Lesson6/testRandomWalk")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/share/paradiseo/mo/tutorial/Lesson6/testRandomWalk")
    endif()
  endif()
endif()

