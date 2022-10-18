/**
 * @file controller.cpp
 * @author Driver - Badrinarayanan Raghunathan Srikumar
           Navigator - Smit Dumore
 * @brief  Program that contains member functions for the controller
 * @version 0.1
 * @date 2022-10-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */

// Necessary header files included
#include "../include/controller.hpp"
#include <iostream>
// Controller constructor used to define the initial values of private members
Controller:: Controller(double p, double i, double d, double t) {
    Kp = p;
    Ki = i;
    Kd = d;
    dt = t;
}
// Member function that will be used to compute PID controller output
std::vector<double> Controller :: computePID(double sp_angle, double pv_angle,
 double sp_vel, double pv_vel) {
    std:: vector<double> result;
    sp_angle = 0.0;
    pv_angle = 0.0;
    pv_vel = 0.0;
    result.push_back(sp_angle + pv_angle + pv_vel + sp_vel);
    return result;
}
// Member function to get Kp value
double Controller:: getKp() {
    return Kp;
}
// Member function to get Kd value
double Controller ::getKd() {
    return Kd;
}
// Member function to get Ki value
double Controller ::getKi() {
    return Ki;
}
// Member function to get dt value
double Controller ::getdt() {
    return dt;
}
