cmake_minimum_required(VERSION 3.20)

set(FRAMEWORK_HEADERS)
set(FRAMEWORK_SOURCES)

add_library(VulkanFramework ${FRAMEWORK_SOURCES} ${FRAMEWORK_HEADERS})
target_link_libraries(VulkanFramework PRIVATE glfw glm spdlog VulkanMemoryAllocator)