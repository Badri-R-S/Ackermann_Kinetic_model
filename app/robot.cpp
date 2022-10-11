#include "../include/robot.hpp"
#include <iostream>

Robot ::Robot(double wb, double wr, double tw) {
    wheel_base = wb;
    wheel_radius = wr;
    track_width = tw;
}
double Robot:: computeTurnRadius(double target_vel, double target_heading ) {
    return 7;
}

