#include "PointExtractor.h"

namespace toy {
PointExtractor::PointExtractor() {
  extractor = cv::FastFeatureDetector::create();
}

PointExtractor::~PointExtractor() {}

void PointExtractor::process(cv::Mat image, std::vector<cv::Point2f>& points) {
  std::vector<cv::KeyPoint> keyPoints;
  extractor->detect(image, keyPoints);
  convertKptsToPts(keyPoints, points);
}

void PointExtractor::convertKptsToPts(std::vector<cv::KeyPoint>& kpts,
                                      std::vector<cv::Point2f>&  pts) {
  pts.reserve(kpts.size());
  for(const auto& kpt : kpts){
    pts.push_back(kpt.pt);
  }
}

}  //namespace toy