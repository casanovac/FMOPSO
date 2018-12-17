# Install script for directory: /home/carlos/Instaladores/ParadisEO-2.0/eo/tutorial/Lesson3

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
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/paradiseo/eo/examples/Lesson3/SecondBitEA-."
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/paradiseo/eo/examples/Lesson3/SecondBitEA"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/paradiseo/eo/examples/Lesson3" TYPE EXECUTABLE FILES
    "/home/carlos/Instaladores/ParadisEO-2.0/build/eo/tutorial/Lesson3/SecondBitEA-."
    "/home/carlos/Instaladores/ParadisEO-2.0/build/eo/tutorial/Lesson3/SecondBitEA"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/paradiseo/eo/examples/Lesson3/SecondBitEA-."
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/paradiseo/eo/examples/Lesson3/SecondBitEA"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHANGE
           FILE "${file}"
           OLD_RPATH "/home/carlos/Instaladores/ParadisEO-2.0/build/eo/lib:"
           NEW_RPATH "")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/usr/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xexamplesx" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/paradiseo/eo/examples/Lesson3/SecondRealEA-."
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/paradiseo/eo/examples/Lesson3/SecondRealEA"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/paradiseo/eo/examples/Lesson3" TYPE EXECUTABLE FILES
    "/home/carlos/Instaladores/ParadisEO-2.0/build/eo/tutorial/Lesson3/SecondRealEA-."
    "/home/carlos/Instaladores/ParadisEO-2.0/build/eo/tutorial/Lesson3/SecondRealEA"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/paradiseo/eo/examples/Lesson3/SecondRealEA-."
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/paradiseo/eo/examples/Lesson3/SecondRealEA"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHANGE
           FILE "${file}"
           OLD_RPATH "/home/carlos/Instaladores/ParadisEO-2.0/build/eo/lib:"
           NEW_RPATH "")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/usr/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xexamplesx" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/paradiseo/eo/examples/Lesson3/exercise3.1-."
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/paradiseo/eo/examples/Lesson3/exercise3.1"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/paradiseo/eo/examples/Lesson3" TYPE EXECUTABLE FILES
    "/home/carlos/Instaladores/ParadisEO-2.0/build/eo/tutorial/Lesson3/exercise3.1-."
    "/home/carlos/Instaladores/ParadisEO-2.0/build/eo/tutorial/Lesson3/exercise3.1"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/paradiseo/eo/examples/Lesson3/exercise3.1-."
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/paradiseo/eo/examples/Lesson3/exercise3.1"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHANGE
           FILE "${file}"
           OLD_RPATH "/home/carlos/Instaladores/ParadisEO-2.0/build/eo/lib:"
           NEW_RPATH "")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/usr/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

