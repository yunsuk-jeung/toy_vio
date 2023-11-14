#include "Slam.h"
#include "config.h"
#include "Vio.h"
#include "ImagePyramid.h"
#include "Frame.h"
#include "Map.h"
namespace toy {

SLAM::SLAM() : vioUptr{nullptr} {};

SLAM::~SLAM(){};

void SLAM::prepare(const std::string& configFile) {
  Config::parseConfig(configFile);
  vioUptr = std::make_unique<Vio>();
  vioUptr->prepare();
}

void SLAM::setNewImage(const int       type_,
                       const int       format_,
                       const uint64_t& ns,
                       uint8_t*        buffer,
                       const int       l,
                       const int       w,
                       const int       h) {

  auto type   = static_cast<ImageType>(type_);
  auto format = static_cast<ImageFormat>(format_);

  auto* imagePyramid = new db::ImagePyramid(type, format, buffer, l, w, h);
  vioUptr->insert(imagePyramid);
  vioUptr->process();
}

void SLAM::setAcc(const uint64_t& ns, float* acc) {}

void SLAM::setGyr(const uint64_t& ns, float* gyr) {}

}  //namespace toy
