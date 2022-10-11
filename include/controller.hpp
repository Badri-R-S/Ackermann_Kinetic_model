/**
 * @file controller.hpp
 * @author Driver - Badrinarayanan Raghunathan Srikumar
           Navigator - Smit Dumore
 * @brief  Hpp file that contains class definition of Controller class
 * @version 0.1
 * @date 2022-10-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */

// Necessary header files included
#include<vector>

// Header guards included
#ifndef INCLUDE_CONTROLLER_HPP_
#define INCLUDE_CONTROLLER_HPP_

// Max and Min values for Kp,Ki,Kd and dt are defined
const double Kpmax = 1;
const double Kpmin = -1;
const double Kimax = 1;
const double Kimin = -1;
const double Kdmax = 1;
const double Kdmin = -1;
const double tmax = 0.05;

// Class definition with it's private members
/**
 * @brief Controller class with the respective P,I,D constants
 * 
 */
class Controller {
    double Kp;
    double Ki;
    double Kd;
    double dt;
 public:
// Constructor definition
    Controller(double p, double i, double d, double t);
    std::vector<double> computePID(double sp_angle, double pv_angle,
    double sp_vel, double pv_vel);
// Function to return Proportional constant
    double getKp();
// Function to return Integral constant
    double getKi();
// Function to return Derivative constant
    double getKd();
// Function to return time interval
    double getdt();
};

#endif  // INCLUDE_CONTROLLER_HPP_
