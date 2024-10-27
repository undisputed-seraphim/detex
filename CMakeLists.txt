cmake_minimum_required(VERSION 3.25)
project(detex VERSION 0.1.2)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

if (NOT MSVC)
	option(DETEX_VALIDATE "Build detex validate." ON)
	option(DETEX_VIEW "Build detex view." ON)
	OPTION(DETEX_CONVERT "Build detex convert (requires libpng)" ON)
endif()

set(detex_src
	bits.c
	clamp.c
	dds.c
	decompress-bptc.c
	decompress-eac.c
	decompress-rgtc.c
	file-info.c
	hdr.c
	misc.c
	raw.c
	bptc-tables.c
	convert.c
	decompress-bc.c
	decompress-bptc-float.c
	decompress-etc.c
	division-tables.c
	half-float.c
	ktx.c
	texture.c
)
add_library(detex STATIC ${detex_src})
target_compile_definitions(detex PUBLIC "DETEX_VERSION=\"${detex_VERSION}\"")
target_sources(detex PUBLIC FILE_SET includes TYPE HEADERS FILES "detex.h")
install(TARGETS detex EXPORT detex-targets FILE_SET includes)

if (NOT MSVC)
	if (DETEX_VALIDATE)
		add_executable(detex-validate validate.c)
		target_link_libraries(detex-validate PRIVATE detex)
		install(TARGETS detex-validate)
	endif()

	if (DETEX_VIEW)
		add_executable(detex-view detex-view.c)
		target_link_libraries(detex-view PRIVATE detex)
		install(TARGETS detex-view)
	endif()

	find_package(PNG)
	if (DETEX_CONVERT AND PNG_FOUND)
		add_executable(detex-convert detex-convert.c png.c)
		target_link_libraries(detex-convert PRIVATE detex PNG::PNG m)
		install(TARGETS detex-convert)
	endif()
endif()

include(CMakePackageConfigHelpers)
include(GNUInstallDirs)
write_file(${CMAKE_BINARY_DIR}/detex-config.cmake.in "@PACKAGE_INIT@\ninclude(\"\$\{CMAKE_CURRENT_LIST_DIR\}/detex-targets.cmake\")")
configure_package_config_file(${CMAKE_BINARY_DIR}/detex-config.cmake.in ${CMAKE_BINARY_DIR}/detex-config.cmake INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/detex)
write_basic_package_version_file(${CMAKE_BINARY_DIR}/detex-version.cmake COMPATIBILITY AnyNewerVersion)
install(FILES ${CMAKE_BINARY_DIR}/detex-config.cmake ${CMAKE_BINARY_DIR}/detex-version.cmake DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/detex)
install(EXPORT detex-targets DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/detex)
