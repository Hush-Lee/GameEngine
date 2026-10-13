file(GLOB_RECURSE ENGINE_CPP CONFIGURE_DEPENDS
	${CMAKE_CURRENT_SOURCE_DIR}/core/*.cpp
)
file(GLOB_RECURSE ENGINE_MODULES CONFIGURE_DEPENDS
	${CMAKE_CURRENT_SOURCE_DIR}/core/*.cppm
)

add_library(engine STATIC ${ENGINE_CPP})
target_sources(engine PUBLIC FILE_SET CXX_MODULES FILES ${ENGINE_MODULES})

# 实现单元里需要 import std;
target_link_libraries(engine PRIVATE std-modules)
