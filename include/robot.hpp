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

/**
 * @brief Class definition of Robot
 * 
 */
class Robot {
    double wheel_base;
    double wheel_radius;
    double track_width;
 public :
    /**
     * @brief Construct a new Robot object
     * 
     * @param wb - wheel base of car
     * @param wr - wheel radius of the car
     * @param tw - track width of the car
     */
    Robot(double wb, double wr, double tw);

    /**
     * @brief Compute the turn radius for the car 
     * 
     * @param target_vel - target velocity given by the user
     * @param target_heading - target heading given by the user
     * @return double - steering angle
     */
    double computeTurnRadius(double target_vel, double target_heading);
};

#endif  // INCLUDE_ROBOT_HPP_
