#pragma once
#include <memory>
#include <vector>
#include <map>
#include "macros.h"
namespace toy {
namespace db {
class Frame;
class MapPoint;
}  //namespace db
class VioSolver {
public:
  USING_SMART_PTR(VioSolver);
  VioSolver() {}
  virtual ~VioSolver() {}

  virtual int solve(std::vector<std::shared_ptr<db::Frame>>&    frames,
                    std::vector<std::shared_ptr<db::MapPoint>>& mapPoints) = 0;

protected:
};

class VioSolverFactory {
public:
  static VioSolver::Uni createVioSolver();
};

}  //namespace toy