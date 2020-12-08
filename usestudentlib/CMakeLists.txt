cmake_minimum_required(VERSION 2.8.9)
project (TestLibrary)

#For the shared library:
# on Windows add testStudent.lib to same directory with testStudent.dll
if (WIN32)
  set ( PROJECT_LINK_LIBS testStudent.dll )
  link_directories( "C:/Users/hsyn/Desktop/SoftRoles/cmake-tutorial/studentlib_shared/out/build/x64-Debug (default)" )
  MESSAGE( VERBOSE ${CMAKE_CURRENT_SOURCE_DIR} )
endif (WIN32)

if (UNIX)
  set ( PROJECT_LINK_LIBS testStudent.so )
  link_directories( ${CMAKE_CURRENT_SOURCE_DIR}/../studentlib_shared/build )
  MESSAGE ( STATUS ${CMAKE_CURRENT_SOURCE_DIR}/../studentlib_shared/build )
endif (UNIX)

#For the static library:
#set ( PROJECT_LINK_LIBS libtestStudent.a )
#link_directories( ~/exploringBB/extras/cmake/studentlib_static/build )

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../studentlib_shared/include)

add_executable(libtest libtest.cpp)
target_link_libraries(libtest ${PROJECT_LINK_LIBS} )
