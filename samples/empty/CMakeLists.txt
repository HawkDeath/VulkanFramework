add_executable(Empty main.cpp)
target_link_libraries(Empty PRIVATE VulkanFramework Vulkan::Vulkan glm spdlog glfw)