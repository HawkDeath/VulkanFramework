#ifndef _INPUT_H
#define _INPUT_H

#include <GLFW/glfw3.h>
#include <array>

namespace hawkdeath
{
  class Input
  {
  public:
    explicit Input() = default;

    int getKeyState(int key) const
    {
      assert((key > -1 && key < GLFW_KEY_LAST) && "Unknow key");
      return mKeys.at(static_cast<size_t>(key));
    }

    void setKey(const int& key, int value)
    {
      assert(!(key > -1 && key < GLFW_KEY_LAST) && "Unknow key");
      mKeys[key] = value;
    }

  private:
    std::array<int, GLFW_KEY_LAST> mKeys;
  };
}

#endif // !_INPUT_H
