/**
 * @file robot.hpp
 * @author Driver - Badrinarayanan Raghunathan Srikumar
           Navigator - Smit Dumore
 * @brief  Hpp file that consists of the class Robot definition.
 * @version 0.1
 * @date 2022-10-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */


// Header guards added
#ifndef INCLUDE_ROBOT_HPP_
#define INCLUDE_ROBOT_HPP_

// Class Robot definition.
/**
 * @brief Class with the wheel radius, wheel_base length and track_width
          as it's members
 * 
 */
class Robot {
    double wheel_base;
    double wheel_radius;
    double track_width;
 public :
// COnstructor definition
    Robot(double wb, double wr, double tw);
// Function definition to compute turn radius
    double computeTurnRadius(double target_vel, double target_heading);
};

#endif  // INCLUDE_ROBOT_HPP_
