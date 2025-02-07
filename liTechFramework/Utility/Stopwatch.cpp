#include "Stopwatch.h"

using namespace std::chrono;

liStopwatch::liStopwatch(bool startClock) {
    if(startClock) {
        Begin();
    }
}

void liStopwatch::Begin() {
    this->beginPoint = high_resolution_clock::now();
}

void liStopwatch::End() {
    this->endPoint = high_resolution_clock::now();
    duration<double> duration = endPoint - beginPoint;
    this->beginPoint = endPoint;
    this->delta = duration.count();
}