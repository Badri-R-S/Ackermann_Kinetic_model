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

/**
 * @brief Construct a new Controller object
 * 
 * @param p - proportional gain value
 * @param i - integral gain value
 * @param d - derivative gain value
 * @param t - simulation time
*/
Controller:: Controller(double p, double i, double d, double t) {
    Kp = p;
    Ki = i;
    Kd = d;
    dt = t;
}

/**
 * @brief - Funnction to compute system outputs with PID control
 * @param sp_angle - set point heading
 * @param pv_angle - current heading
 * @param sp_vel - set point velocity
 * @param pv_vel - current velocity
 * @return std::vector<double> - vector of calculated outputs
 */
std::vector<double> Controller :: computePID(double sp_angle, double pv_angle,
 double sp_vel, double pv_vel) {
    std:: vector<double> result;
    sp_angle = 0.0;
    pv_angle = 0.0;
    pv_vel = 0.0;
    sp_vel = 0.0;
    result.push_back(sp_angle + pv_angle + pv_vel + sp_vel);
    return result;
}

/**
 * @brief Get the Kp value
 * @return double 
 */
double Controller:: getKp() {
    return Kp;
}

/**
 * @brief Get the Kd value
 * 
 * @return double 
 */
double Controller ::getKd() {
    return Kd;
}

/**
 * @brief Get the Ki value
 * @return double 
 */
double Controller ::getKi() {
    return Ki;
}

/**
 * @brief get the dt value
 * 
 * @return double 
 */
double Controller ::getdt() {
    return dt;
}
