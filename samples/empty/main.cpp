#include "../../Framework/Window/Window.h" // TODO: Fix this; Framework must share header files
#include "../../Framework/Utils/Log.h" // TODO: same like above

#include <vulkan/vulkan.h>
#include <glm/glm.hpp>

#include <memory>
#include <vector>

int main()
{
  std::unique_ptr<hawkdeath::Window> window = std::make_unique<hawkdeath::Window>("Empty", 1280, 720);

  uint32_t properticesCount = { 0 };
  vkEnumerateInstanceLayerProperties(&properticesCount, nullptr);
  std::vector<VkLayerProperties> props(properticesCount);
  vkEnumerateInstanceLayerProperties(&properticesCount, props.data());

  glm::vec4 vec = { 1.0f, 0.0f, 1.0f, 1.0f };
  auto res = glm::mat4(1.0f) * vec;

   LOG("Is available of {} layers", properticesCount);
  for (auto layer : props)
  {
    LOG("\t{}: {}.{}.{}", layer.layerName, VK_VERSION_MAJOR(layer.specVersion), VK_VERSION_MINOR(layer.specVersion), VK_VERSION_PATCH(layer.specVersion));
  }

  while (!window->isClose())
  {
    glfwPollEvents();
  }


  return 0;
}