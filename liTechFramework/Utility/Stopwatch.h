#ifndef LITECHFRAMEWORK_STOPWATCH_H
#define LITECHFRAMEWORK_STOPWATCH_H
#include "Typedefs.h"

typedef std::chrono::high_resolution_clock::time_point liTimepoint;

class liStopwatch {
public:
    liStopwatch(bool startClock = false);

    void Begin();
    void End();
    
    LITECH_INLINE double Millis() const { return delta * 1000.0; }
    LITECH_INLINE double Seconds() const { return delta; }
    LITECH_INLINE double FPS() const { return 1.0 / delta; }
private:
    liTimepoint beginPoint, endPoint;
    double delta;
};

#endif