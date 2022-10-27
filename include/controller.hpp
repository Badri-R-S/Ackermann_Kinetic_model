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
const double tmax = 0.1;


/**
 * @brief Controller class that defines the required parameters for 
          both the controllers
 * 
 */
class Controller {
 private:
    double Kp_vel;
    double Ki_vel;
    double Kd_vel;
    double dt;
    double Kp_head;
    double Ki_head;
    double Kd_head;
    std :: vector<double> vel_error;
    std :: vector<double> head_error;

 public:
   /**
   * @brief Constructor to initialized the private members of 
            controller class
   * @param p_vel - Proportional constant for velocity
   * @param i_vel - Integral constant for velocity
   * @param d_vel - Derivative constant for velocity
   * @param t - Time interval for the controller
   * @param p_head - Proportional constant for heading
   * @param i_head - Integral constant for heading
   * @param d_head - Derivative constant for heading
   * @return Controller:: 
   */

    Controller(double p_vel, double i_vel, double d_vel, double t,
                double p_head, double i_head, double d_head);

   /**
   * @brief Function to compute the outputs of the velocity and heading 
            controller
   * @param errors - error vector which contains the velocity and heading error
                     computed by computePIDerror
   * @return std::vector<double> - returns the PID velocity and heading errors as a vector
   */

    std::vector<double> computePID(std :: vector <double>);

   /**
   * @brief Get the Kp_vel value
   * @return double 
   */
    double getKp_vel();

   /**
   * @brief Get the Ki_vel value 
   * @return double 
   */
    double getKi_vel();

   /**
    * @brief Get the Kd_vel value
   * @return double 
   */

    double getKd_vel();

    /**
     * @brief get the dt value
     * 
     * @return double 
     */
    double getdt();
   /**
   * @brief Get the Kp_head value
   * @return double 
   */
    double getKp_head();
   /**
   * @brief Get the Ki_head value
   * @return double 
   */
    double getKi_head();
   /**
   * @brief Get the Kd_head value
   * @return double
   */
    double getKd_head();
   /**
   * @brief function to compute the velocity and heading error from
            respective set points and current values.  
   * @param sp_vel - target value for velocity
   * @param pv_vel - current value of velocity
   * @param sp_angle - target value for heading
   * @param pv_angle - current value of heading
   * @return std::vector<double> - vector storing errors
   */
    std::vector<double>  computePIDerror(double sp_vel, double pv_vel,
                                    double sp_angle, double pv_angle);
};

#endif  // INCLUDE_CONTROLLER_HPP_
