#ifndef STOPWATCH_H
#define STOPWATCH_H
#pragma once

typedef std::chrono::high_resolution_clock::time_point liTimepoint;

class liStopwatch {
public:
    liStopwatch(bool startClock = false);

    void Begin();
    void End();
    
    inline double Millis() const { return delta * 1000.0; }
    inline double Seconds() const { return delta; }
    inline double FPS() const { return 1.0 / delta; }
private:
    liTimepoint beginPoint, endPoint;
    double delta;
};

#endif