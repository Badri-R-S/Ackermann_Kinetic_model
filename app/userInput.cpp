/**
 * @file userInput.cpp
 * @author Driver - Smit Dumore
           Navigator - Badrinarayanan Raghunathan Srikumar
 * @brief  Program that contains member functions for the userInput class
 * @version 0.1
 * @date 2022-10-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */

// cpp headers
#include "../include/userInput.hpp"
#include <iostream>

#define PI 3.14159265

/**
 * @brief: Constructor for the UserInput class
 * @param - iv  intial velocity
 * @param - ih intial heading angle
 * @return: None
*/
UserInput:: UserInput(double iv, double ih) {
    intial_velocity = iv;
    intial_heading = ih;
}

/**
 * @brief - Function to get inputs from the user
 * @param - none
 * @return - none
 */
void UserInput::getUserInputs() {
    std::cout << "Enter the target heading (in degrees): ";
    double target_heading_deg, target_heading_rad =0.0;
    std::cin >> target_heading_deg;
    target_heading_rad = (target_heading_deg*PI)/180;
    this->target_heading = target_heading_rad;

    std::cout << "Enter the target speed (in m/s): ";
    std::cin >> this->target_velocity;
}

/**
* @brief: Return the target velocity.
* @return: target velocity.
*/
double UserInput::getTargetVelocity() {
    return target_velocity;
}

/**
* @brief: Return the target heading.
* @return: target heading.
*/
double UserInput::getTargetHeading() {
    return target_heading;
}

