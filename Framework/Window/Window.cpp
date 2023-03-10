#include "Window.h"
#include "Input.h"
#include "../Utils/Log.h"

using namespace hawkdeath;


Window::Window(const std::string& title, const std::int32_t& width, const int32_t& height) : mWindow{ nullptr }, mWidth{ width }, mHeight{ height }, mWasResized{ false }, mInput{ nullptr }
{
  glfwSetErrorCallback([](int code, const char* desc) -> void {
    ELOG("GLFW {}: {}", code, desc);
    });
  glfwInit();

  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  mWindow = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
  if (!mWindow)
  {
    RT_THROW("Failed to create window");
  }

  glfwSetWindowUserPointer(mWindow, this);
  mInput = std::make_shared<Input>();

  glfwSetKeyCallback(mWindow, &Window::key_callback);
  glfwSetFramebufferSizeCallback(mWindow, &Window::framebuffer_size_callback);
  LOG("GLFW {}.{}.{}", GLFW_VERSION_MAJOR, GLFW_VERSION_MINOR, GLFW_VERSION_REVISION);
}

Window::~Window()
{
  if (mWindow)
  {
    glfwDestroyWindow(mWindow);
  }
  glfwTerminate();
}
void Window::framebuffer_size_callback(GLFWwindow* win, int width, int height)
{
  auto internalWin = reinterpret_cast<Window*>(glfwGetWindowUserPointer(win));
  internalWin->mWidth = width;
  internalWin->mHeight = height;
  internalWin->mWasResized = true;
}

void Window::key_callback(GLFWwindow* win, int key, int scancode, int action, int mods)
{
  UNUSE(scancode);
  UNUSE(mods);
  auto internalWin = reinterpret_cast<Window*>(glfwGetWindowUserPointer(win));
  internalWin->mInput->setKey(key, action);
}