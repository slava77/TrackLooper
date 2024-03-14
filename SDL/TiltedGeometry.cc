#include "TiltedGeometry.h"

SDL::TiltedGeometry<SDL::Dev>::TiltedGeometry(std::string filename) { load(filename); }

void SDL::TiltedGeometry<SDL::Dev>::load(std::string filename) {
  drdzs_.clear();
  slopes_.clear();

  std::ifstream ifile;
  ifile.open(filename.c_str());
  std::string line;

  while (std::getline(ifile, line)) {
    unsigned int detid;
    float drdz;
    float slope;

    std::stringstream ss(line);

    ss >> detid >> drdz >> slope;

    drdzs_[detid] = drdz;
    slopes_[detid] = slope;
  }
}

float SDL::TiltedGeometry<SDL::Dev>::getDrDz(unsigned int detid) {
  if (drdzs_.find(detid) != drdzs_.end()) {
    return drdzs_[detid];
  } else {
    return 0;
  }
}

float SDL::TiltedGeometry<SDL::Dev>::getSlope(unsigned int detid) {
  if (slopes_.find(detid) != slopes_.end()) {
    return slopes_[detid];
  } else {
    return 0;
  }
}
