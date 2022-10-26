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
#define PI 3.14159265

/**
 * @brief Construct a new Controller object
 * 
 * @param p - proportional gain value
 * @param i - integral gain value
 * @param d - derivative gain value
 * @param t - simulation time
*/
Controller:: Controller(double p_vel, double i_vel, double d_vel, double t, double p_head ,double i_head, double d_head) {
    Kp_vel = p_vel;
    Ki_vel = i_vel;
    Kd_vel = d_vel;
    dt = t;
    Kp_head = p_head;
    Ki_head = i_head;
    Kd_head = d_head;

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
    P_vel_ouput = Kp_vel * vel_error.end()[-1];
    
    double sum_vel = 0;
    for (auto err : vel_error) {
        sum_vel += err * dt;
    }
    
    I_vel_output = Ki_vel * sum_vel;
    
    if(vel_error.size() < 2)
        D_vel_output = 0;
    else
        D_vel_output = Kd_vel * ((vel_error.end()[-1]-vel_error.end()[-2])/dt);
    double PID_vel_output = P_vel_ouput + I_vel_output + D_vel_output;


     P_head_ouput = Kp_head * head_error.end()[-1];
    double sum_head = 0;
    for (auto err : head_error) {
        sum_head += err * dt;
    }
    I_head_output = Ki_head * sum_head;
    if(head_error.size() < 2)
        D_head_output = 0;
    else
        D_head_output = Kd_head * ((head_error.end()[-1]- head_error.end()[-2])/dt);
    double PID_head_output = P_head_ouput + I_head_output + D_head_output;
    std :: vector<double> PID_output;
    PID_output.push_back(PID_vel_output);
    PID_output.push_back(PID_head_output);
    return PID_output;
}

/**
 * @brief Get the Kp value
 * @return double 
 */
double Controller:: getKp_vel() {
    return Kp_vel;
}

/**
 * @brief Get the Kd value
 * 
 * @return double 
 */
double Controller ::getKd_vel() {
    return Kd_vel;
}

/**
 * @brief Get the Ki value
 * @return double 
 */
double Controller ::getKi_vel() {
    return Ki_vel;
}

/**
 * @brief get the dt value
 * 
 * @return double 
 */
double Controller ::getdt() {
    return dt;
}

double Controller ::getKp_head() {
    return Kp_head;
}

double Controller ::getKi_head() {
    return Ki_head;
}

double Controller ::getKd_head() {
    return Kd_head;
}

std::vector<double>  Controller::computePIDerror(double sp_vel, double pv_vel,
                                                   double sp_angle ,double pv_angle) {
    double current_vel_error = sp_vel - pv_vel;
    std::cout<<"Error_vel :"<<current_vel_error<<"\n";
    double current_angle_error = sp_angle - pv_angle;
    std::cout<<"Error_head :"<<current_angle_error * 180/PI;
    std:: vector<double> errors;
    vel_error.push_back(current_vel_error);
    head_error.push_back(current_angle_error);
    errors.push_back(current_vel_error);
    errors.push_back(current_vel_error);

    return errors;
}