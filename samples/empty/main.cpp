#include <spdlog/spdlog.h>
#include <GLFW/glfw3.h>
#include <vulkan/vulkan.h>

#include <glm/glm.hpp>

#include <vector>


int main()
{
  glfwSetErrorCallback([](int code, const char* desc) -> void {
    spdlog::error("[GLFW] {}: {}", code, desc);
    });
  glfwInit();
  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  GLFWwindow* window = glfwCreateWindow(1280, 720, "Empty", nullptr, nullptr);

  uint32_t properticesCount = { 0 };
  vkEnumerateInstanceLayerProperties(&properticesCount, nullptr);
  std::vector<VkLayerProperties> props(properticesCount);
  vkEnumerateInstanceLayerProperties(&properticesCount, props.data());

  glm::vec4 vec = { 1.0f, 0.0f, 1.0f, 1.0f };
  auto res = glm::mat4(1.0f) * vec;

  spdlog::info("Is available of {} layers", properticesCount);
  for (auto layer : props)
  {
    spdlog::info("\t{}: {}.{}.{}", layer.layerName, VK_VERSION_MAJOR(layer.specVersion), VK_VERSION_MINOR(layer.specVersion), VK_VERSION_PATCH(layer.specVersion));
  }

  while (!glfwWindowShouldClose(window))
  {
    glfwPollEvents();
  }

  if (window)
  {
    glfwDestroyWindow(window);
  }

  glfwTerminate();

  return 0;
}