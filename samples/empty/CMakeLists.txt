add_executable(Empty main.cpp)
target_link_libraries(Empty PRIVATE glfw spdlog Vulkan::Vulkan glm)