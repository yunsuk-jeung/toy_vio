#pragma once
#include <vector>
#include <Eigen/Dense>
#include <opencv2/core/core.hpp>
#include "types.h"
namespace toy {
class Camera {
public:
  EIGEN_MAKE_ALIGNED_OPERATOR_NEW

  Camera(CameraInfo* camInfo);
  virtual ~Camera();

  virtual void project(Eigen::Vector3d& _xyz, Eigen::Vector2d& uv_) = 0;
  virtual void undistortPoints(std::vector<cv::Point2f>& pts,
                               std::vector<cv::Point2f>& upts)      = 0;

protected:
  double mW, mH;
  double mFx, mFy, mCx, mCy;
  double mD0, mD1, mD2, mD3, mD4;

  double mInvFx, mInvFy, mInvCx, mInvCy;
  bool   mIsDistortion;

  cv::Mat mK, mD;
};

class CameraFactory {
public:
  static Camera* createCamera(CameraInfo* camInfo);
};
}  //namespace toy