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
#include<tuple>

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


/**
 * @brief Controller class definition 
 */
class Controller {
 private:
    double Kp;
    double Ki;
    double Kd;
    double dt;
    std :: vector<double> vel_error;
    std :: vector<double> head_error;
 public:
    /**
     * @brief Construct a new Controller object
     * 
     * @param p - proportional gain value
     * @param i - integral gain value
     * @param d - derivative gain value
     * @param t - simulation time
     */
    Controller(double p, double i, double d, double t);

    /**
     * @brief - Funnction to compute system outputs with PID control
     * @param sp_angle - set point heading
     * @param pv_angle - current heading
     * @param sp_vel - set point velocity
     * @param pv_vel - current velocity
     * @return std::vector<double> - vector of calculated outputs
     */
    std::vector<double> computePID(std :: vector <double>);

    /**
     * @brief Get the Kp value
     * @return double 
     */
    double getKp();

    /**
     * @brief Get the Ki value
     * @return double 
     */
    double getKi();

    /**
     * @brief Get the Kd value
     * 
     * @return double 
     */
    double getKd();

    /**
     * @brief get the dt value
     * 
     * @return double 
     */
    double getdt();

   std::vector<double>  computePIDerror(double sp_vel, double pv_vel,
                                                   double sp_angle ,double pv_angle);
};

#endif  // INCLUDE_CONTROLLER_HPP_
