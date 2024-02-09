#ifndef TiltedGeometry_h
#define TiltedGeometry_h

#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

namespace SDL {
  class TiltedGeometry {
  private:
    std::map<unsigned int, float> drdzs_;
    std::map<unsigned int, float> slopes_;

  public:
    TiltedGeometry() = default;
    TiltedGeometry(std::string filename);
    ~TiltedGeometry() = default;

    void load(std::string);

    float getDrDz(unsigned int detid);
    float getSlope(unsigned int detid);
  };

  namespace globals {
    extern TiltedGeometry tiltedGeometry;
  }
}  // namespace SDL

#endif
