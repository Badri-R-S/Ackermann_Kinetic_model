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

/**
 * @brief Construct a new Robot object
 * 
 * @param wb - wheel base of car
 * @param wr - wheel radius of the car
 * @param tw - track width of the car
 */
Robot ::Robot(double wb, double wr, double tw) {
    wheel_base = wb;
    wheel_radius = wr;
    track_width = tw;
}

/**
 * @brief Compute the turn radius for the car 
 * 
 * @param target_vel - target velocity given by the user
 * @param target_heading - target heading given by the user
 * @return double - steering angle
 */
double Robot:: computeTurnRadius(double target_vel, double target_heading ) {
    target_vel = 0.0;
    target_heading = 0.0;
    return target_heading + target_vel;
}

