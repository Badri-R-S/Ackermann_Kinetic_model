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
#include <tuple>

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
std::vector<double> Controller :: computePID(std:: vector<double> errors) {
    double P_vel_ouput, I_vel_output, D_vel_output;
    double P_head_ouput, I_head_output, D_head_output;
    P_vel_ouput = Kp * errors[0];
    double sum_vel = 0;
    for (auto err : vel_error) {
        sum_vel += err * dt;
    }
    I_vel_output = Ki * sum_vel;
    if(vel_error.size() < 2)
        D_vel_output = 0;
    else
        D_vel_output = Kd * ((vel_error.end()[-1]-vel_error.end()[-2])/dt);
    double PID_vel_output = P_vel_ouput + I_vel_output + D_vel_output;
     P_head_ouput = Kp * errors[1];
    double sum_head = 0;
    for (auto err : head_error) {
        sum_head += err * dt;
    }
    I_head_output = Ki * sum_head;
    if(head_error.size() < 2)
        D_head_output = 0;
    else
        D_head_output = Kd * ((head_error.end()[-1]- head_error.end()[-2])/dt);
    double PID_head_output = P_head_ouput + I_head_output + D_head_output;
    std :: vector<double> PID_output;
    PID_output[0] = PID_vel_output;
    PID_output[1] = PID_head_output;
    return PID_output;
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

std::vector<double>  Controller::computePIDerror(double sp_vel, double pv_vel,
                                                   double sp_angle ,double pv_angle) {
    double current_vel_error = sp_vel - pv_vel;
    double current_angle_error = sp_angle - pv_vel;
    std:: vector<double> errors;
    vel_error.push_back(current_vel_error);
    head_error.push_back(current_angle_error);
    errors[0] = current_vel_error;
    errors[1] = current_angle_error;

    return errors;
}