cmake_minimum_required (VERSION 2.6)
project (Party)

set (Party_VERSION_MAJOR 0)
set (Party_VERSION_MINOR 1)
set (_ITERATOR_DEBUG_LEVEL 0)
set (SKIA_DIR "G:/skia")
set (SDL_DIR "D:/cpplib/SDL2-2.0.8")

configure_file (
  "${PROJECT_SOURCE_DIR}/PartyConfig.h.in"
  "${PROJECT_BINARY_DIR}/PartyConfig.h"
)

include_directories("${PROJECT_BINARY_DIR}")

add_executable(Party party.cc)
find_library(SKIA_OPENGL_LIBRARY OpenGL PATH "D:/cpplib")
message(${SKIA_OPENGL_LIBRARY})

set(SKIA_OUT_DIR "${SKIA_DIR}/out/Release")

find_library(SKIA_LIBRARY skia PATH "${SKIA_OUT_DIR}")
find_library(SDL_LIBRARY SDL2 PATH "${SDL_DIR}/lib/x64")
find_library(SDL_MAIN_LIBRARY SDL2main PATH "${SDL_DIR}/lib/x64")

find_path(SKIA_CONFIG_INCLUDE_DIR SkUserConfig.h HINTS "${SKIA_DIR}/include/config")
find_path(SKIA_CORE_INCLUDE_DIR SkCanvas.h HINTS "${SKIA_DIR}/include/core")
find_path(SKIA_UTILS_INCLUDE_DIR SkRandom.h HINTS "${SKIA_DIR}/include/utils")
find_path(SKIA_CODEC_INCLUDE_DIR SkCodec.h HINTS "${SKIA_DIR}/include/codec")
find_path(SKIA_EFFECTS_INCLUDE_DIR SkImageSource.h HINTS "${SKIA_DIR}/include/effects")
find_path(SKIA_GPU_INCLUDE_DIR GrContext.h HINTS "${SKIA_DIR}/include/gpu")
find_path(SKIA_PRIVATE_INCLUDE_DIR GrTypesPriv.h HINTS "${SKIA_DIR}/include/private")
find_path(SKIA_GPU2_INCLUDE_DIR gl/GrGLDefines.h HINTS "${SKIA_DIR}/src/gpu")
find_path(SKIA_ANGLE_INCLUDE_DIR angle_gl.h HINTS "${SKIA_DIR}/third_party/externals/angle2/include")

include_directories(
  ${SKIA_CONFIG_INCLUDE_DIR}
  ${SKIA_CORE_INCLUDE_DIR}
  ${SKIA_PORTS_INCLUDE_DIR}
  ${SKIA_UTILS_INCLUDE_DIR}
  ${SKIA_CODEC_INCLUDE_DIR}
  ${SKIA_GPU_INCLUDE_DIR}
  ${SKIA_PRIVATE_INCLUDE_DIR}
  ${SKIA_GPU2_INCLUDE_DIR}
)
if(WIN32)
  include_directories(${SKIA_ANGLE_INCLUDE_DIR})
  endif()

include_directories(
  ${SDL_DIR}/include
)

set(SKIA_LIBRARIES
  ${SKIA_LIBRARY}
  ${SKIA_OPENGL_LIBRARY}
)
set(SDL_LIBRARIES
  ${SDL_LIBRARY}
  ${SDL_MAIN_LIBRARY}
)
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
target_compile_definitions(Party PRIVATE SK_BUILD_FOR_WIN32
_CRT_SECURE_NO_WARNINGS)
target_compile_definitions(Party PRIVATE
SK_INTERNAL
SK_GAMMA_SRGB
SK_GAMMA_APPLY_TO_A8
SK_SCALAR_TO_FLOAT_EXCLUDED
SK_ALLOW_STATIC_GLOBAL_INITIALIZERS=1
SK_SUPPORT_OPENCL=0
SK_FORCE_DISTANCE_FIELD_TEXT=0
GR_GL_FUNCTION_TYPE=__stdcall
SK_SUPPORT_GPU=1)

target_link_libraries(Party
  ${SKIA_LIBRARIES}
  ${SDL_LIBRARIES}
)