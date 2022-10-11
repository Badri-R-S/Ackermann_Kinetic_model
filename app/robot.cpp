/**
 * @file robot.cpp
 * @author Driver - Badrinarayanan Raghunathan Srikumar
           Navigator - Smit Dumore
 * @brief Program that contains member functions of class Robot
          that defines the geometry of the robot
 * @version 0.1
 * @date 2022-10-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */






// Necessary header file sincluded
#include "../include/robot.hpp"
#include <iostream>
// Constructor that is used to initialize the private members of the class
Robot ::Robot(double wb, double wr, double tw) {
    wheel_base = wb;
    wheel_radius = wr;
    track_width = tw;
}
// compute function that computes turn radius of the robot
double Robot:: computeTurnRadius(double target_vel, double target_heading ) {
    return 7;
}

