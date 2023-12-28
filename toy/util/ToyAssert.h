#pragma once
#include "ToyLogger.h"

//YSTODO to camke list
#define ENABLE_ASSERT
#ifdef ENABLE_ASSERT
#define TOY_ASSERT(result)                                                               \
  toy::ToyAssert::Assert(!!(result), __FILE__, __LINE__, __FUNCTION__)
#else
#define TOY_ASSERT(ans) void()
#endif

namespace toy {
class ToyAssert {
public:
  static void Assert(bool result, const char* file, int line, const char* function) {
    if (result) {
      return;
    }
    ToyLogger::logE(LogUtil::extractFileName(file), line, "Assertion failed in {}", function);
    std::abort();
  }
};
}  //namespace toy
