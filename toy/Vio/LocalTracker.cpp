#include "ToyLogger.h"
#include "LocalMap.h"
#include "LocalTracker.h"

namespace toy {
LocalTracker::LocalTracker()
  : mStatus{Status::NONE}
  , mLocalMap{nullptr} {}

LocalTracker::~LocalTracker() {
  delete mLocalMap;
  mLocalMap = nullptr;
}

void LocalTracker::prepare() {
  mLocalMap = new db::LocalMap();
  mStatus   = Status::INITIALIZING;
}

void LocalTracker::process() {
  ToyLogD("localTracker in queue size : {}", mInQueue.unsafe_size());

  db::Frame* currFrame = getLatestInput();

  switch (mStatus) {
  case Status::NONE: {
    ToyLogE("prepare tracker before process");
    break;
  }
  case Status::INITIALIZING: {
    bool OK = initialize(currFrame);
    if (OK) { mStatus = Status::TRACKING; }
    else { mLocalMap->reset(); }
    break;
  }
  case Status::TRACKING: {
    break;
  }
  }
}

bool LocalTracker::initialize(db::Frame* currFrame) {
  db::FramePtr framePtr(currFrame);
  mLocalMap->addFramePtr(framePtr);

  return true;
}

}  //namespace toy