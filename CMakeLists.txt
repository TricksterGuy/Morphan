cmake_minimum_required (VERSION 2.6)
project (morphan)

set(CPACK_BINARY_DEB "ON")
set(CPACK_BINARY_RPM "OFF")
set(CPACK_GENERATOR "DEB")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Morphan")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "morphan 1.0.0")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_PACKAGE_VERSION_MAJOR "1")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set(CPACK_PACKAGE_VERSION_PATCH "0")

set(CPACK_DEBIAN_PACKAGE_NAME "morphan")
set(CPACK_DEBIAN_PACKAGE_VERSION "1.0")
set(CPACK_DEBIAN_PACKAGE_DEPENDS "")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Brandon Whitehead <brandon.whitehead@gatech.edu>")
set(CPACK_DEBIAN_PACKAGE_DESCRIPTION "morphan")

set(CPACK_PACKAGE_FILE_NAME "morphan-1.0.0-i386")
set(CPACK_DEBIAN_PACKAGE_ARCHITECTURE "i386")

include(CPack)
include(FindPkgConfig)

add_definitions(-DLINUX)

option(DEBUG_MODE "Build for debugging" ON)
option(TEST_MODE "Build for testing" OFF)

# Source files definition
set(SRC_MORPHAN
	src/data/Morphan.cpp
	src/data/MorphanKeyFrame.cpp

	src/data/primitives/Arc.cpp
	src/data/primitives/BezierCurve.cpp
	src/data/primitives/Circle.cpp
	src/data/primitives/ConvexPolygon.cpp
	src/data/primitives/Ellipse.cpp
	src/data/primitives/Line.cpp
	src/data/primitives/Polygon.cpp
	src/data/primitives/Primitive.cpp
	src/data/primitives/PrimitiveFactory.cpp
	src/data/primitives/Rectangle.cpp

	src/gen/GridSizeGUI.cpp
	src/gen/MorphanGUI.cpp
	src/gen/Morphan.pb.cc

	src/gui/GridSizeDialog.cpp
	src/gui/MorphanApp.cpp
	src/gui/MorphanFrame.cpp
	src/gui/MorphanPanel.cpp
	src/gui/MorphanView.cpp

	src/gui/images/Arc.cpp
	src/gui/images/BezierCurve.cpp
	src/gui/images/Circle.cpp
	src/gui/images/ConvexPolygon.cpp
	src/gui/images/Duplicate.cpp
	src/gui/images/Ellipse.cpp
	src/gui/images/Line.cpp
	src/gui/images/MoveObject.cpp
	src/gui/images/MovePoint.cpp
	src/gui/images/Polygon.cpp
	src/gui/images/Rectangle.cpp
	src/gui/images/Select.cpp

	src/gui/tool/ArcTool.cpp
	src/gui/tool/BezierTool.cpp
	src/gui/tool/CircleTool.cpp
	src/gui/tool/ConvexPolygonTool.cpp
	src/gui/tool/EllipseTool.cpp
	src/gui/tool/LineTool.cpp
	src/gui/tool/PolygonTool.cpp
	src/gui/tool/RectangleTool.cpp

	src/gui/tool/ModifyTool.cpp
	src/gui/tool/DuplicateTool.cpp
	src/gui/tool/MoveObjectTool.cpp
	src/gui/tool/MovePointTool.cpp
    src/gui/tool/SelectTool.cpp
)


set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
set(wxWidgets_USE_LIBS xrc xml html adv gl net core base)
find_package(wxWidgets REQUIRED)
find_package(GTK2 REQUIRED gtk)
pkg_search_module(PROTOBUF REQUIRED protobuf)

IF(DEBUG_MODE)
    set(CMAKE_CXX_FLAGS "-g -Wall -std=c++0x -DwxUSE_GRAPHICS_CONTEXT=1")
ELSE()
    set(CMAKE_CXX_FLAGS "-O3 -s -Wall -std=c++0x -DwxUSE_GRAPHICS_CONTEXT=1")
ENDIF(DEBUG_MODE)

set(CMAKE_SKIP_RPATH TRUE)
include(${wxWidgets_USE_FILE})

include_directories(${morphan_SOURCE_DIR}/src/data)
include_directories(${morphan_SOURCE_DIR}/src/data/primitives)
include_directories(${morphan_SOURCE_DIR}/src/gen)
include_directories(${morphan_SOURCE_DIR}/src/gui)
include_directories(${morphan_SOURCE_DIR}/src/gui/images)
include_directories(${morphan_SOURCE_DIR}/src/gui/tool)
include_directories(${GTK2_INCLUDE_DIRS})
include_directories(${PROTOBUF_INCLUDEDIR})

add_executable(
	morphan
	${SRC_MORPHAN}
)

target_link_libraries(
	morphan
	${wxWidgets_LIBRARIES}
	${GTK2_LIBRARIES}
	${PROTOBUF_LIBRARIES}
)

install(PROGRAMS ${CMAKE_CURRENT_BINARY_DIR}/morphan DESTINATION bin)
