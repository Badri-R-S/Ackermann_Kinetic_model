/**
 * @file robot.cpp
 * @author Driver - Badrinarayanan Raghunathan Srikumar
           Navigator - Smit Dumore
 * @brief Program that contains member functions of class Robot
          that defines the geometry of the robot
 * @version 0.1
 * @date 2022-10-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */

// Necessary header file sincluded
#include "../include/robot.hpp"
#include <math.h>
#include <iostream>




#define PI 3.1416
/**
 * @brief Construct a new Robot object
 * 
 * @param wb - wheel base of car
 * @param wr - wheel radius of the car
 * @param tw - track width of the car
 */
Robot ::Robot(double wb, double wr, double tw) {
    wheel_base = wb;
    wheel_radius = wr;
    track_width = tw;
    alpha_i = 0;  // inner wheel angle
    alpha_o = 0;  // outer wheel angle
    omega_i = 0;  // inner wheel angular velocity
    omega_o = 0;  // outer wheel angular velocity
    heading = 0;  // initial heading
    speed = 0;   // initial speed
}

/**
 * @brief Function that computes the final speed and heading by taking
         in the PID controllers' output and time interval
 * 
 * @param PID_heading_output 
 * @param PID_velocity_output 
 * @param dt 
 */
void Robot:: Simulate_robot_model(double PID_heading_output,
                         double PID_velocity_output, double dt ) {
    char turn;
    double R;
    double delta_theta = 0;
    double new_speed = 0;

    if (PID_heading_output > 0) {
            // Robot is executing a left turn
            R = wheel_base * 1/tan(PID_heading_output);
            alpha_i = atan(wheel_base / (R - (track_width / 2)));  // left wheel
            alpha_o = atan(wheel_base /
                        (R + (track_width / 2)));  // right wheel
            omega_o += PID_velocity_output;
            delta_theta = (wheel_radius * omega_o* dt)
                    / (R + (track_width/ 2));
            omega_i = (delta_theta * (R - (track_width / 2)))
                    / (wheel_radius * dt);
            new_speed = std::abs((R * delta_theta) / dt);
    } else if (PID_heading_output < 0) {
            // Robot is executing a right turn
            R = wheel_base * 1/tan(PID_heading_output);
            alpha_o = atan(wheel_base / (R - (track_width / 2)));  // left wheel
            alpha_i = atan(wheel_base /
                        (R + (track_width / 2)));  // right wheel
            omega_i += PID_velocity_output;
            delta_theta = (wheel_radius * omega_i* dt)
                    / (R + (track_width / 2));
            omega_o = (delta_theta * (R - (track_width / 2)))
                    / (wheel_radius * dt);
            new_speed = std::abs((R * delta_theta) / dt);
    } else {
            // Robot is going straight
            alpha_o = 0;
            alpha_i = 0;
            if (omega_i >= omega_o) {
                omega_o += PID_velocity_output;
                omega_i = omega_o;
            } else {
                omega_i += PID_velocity_output;
                omega_o = omega_i;
            }
            new_speed = omega_i*wheel_radius;
    }
    heading += delta_theta;
    speed = new_speed;
    std ::cout << "heading : " << 180*heading/PI << "\n";
    std ::cout << "Speed :" << speed << "\n";
}
/**
 * @brief function to get initial heading
 * 
 * @return double 
 */
double Robot ::getHeading() {
    return heading;
}
 /**
  * @brief function to get initial speed
  * 
  * @return double 
  */

double Robot ::getSpeed() {
    return speed;
}
