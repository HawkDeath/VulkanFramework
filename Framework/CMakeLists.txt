cmake_minimum_required(VERSION 3.20)


# utils module
set(UTILS_MODULE_HEADERS Utils/Log.h)
set(UTILS_MODULE_SOURCES )

# window module
set(WINDOW_MODULE_HEADERS window/Window.h window/Input.h)
set(WINDOW_MODULE_SOURCES window/Window.cpp)


set(FRAMEWORK_HEADERS ${WINDOW_MODULE_HEADERS} ${UTILS_MODULE_HEADERS})
set(FRAMEWORK_SOURCES ${WINDOW_MODULE_SOURCES} ${UTILS_MODULE_SOURCES})

add_library(VulkanFramework ${FRAMEWORK_SOURCES} ${FRAMEWORK_HEADERS})
target_link_libraries(VulkanFramework PRIVATE glfw glm spdlog VulkanMemoryAllocator)

install(DIRECTORY . DESTINATION ${CMAKE_INSTALL_INCLUDEDIR} 
        FILES_MATCHING PATTERN "*/*.h")