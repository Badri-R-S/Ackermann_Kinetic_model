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
#include <iostream>
#include <math.h>

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
    alpha_i = 0;
    alpha_o = 0;
    omega_i = 0;
    omega_o = 0;
    heading = 0;
    speed = 0;
}

/**
 * @brief Compute the turn radius for the car 
 * 
 * @param target_vel - target velocity given by the user
 * @param target_heading - target heading given by the user
 * @return double - steering angle
 */
void Robot:: Simulate_robot_model(double PID_heading_output, double PID_velocity_output, double dt ) {
    char turn;
    double R;
    double delta_theta = 0;
    double new_speed = 0;

    if (PID_heading_output > 0) {
        //std::cout << "Turning left" << std::endl;
            R = wheel_base * 1/tan(PID_heading_output);
            alpha_i = atan(wheel_base / (R - (track_width / 2)));
            alpha_o = atan(wheel_base / (R + (track_width / 2)));
            omega_o += PID_velocity_output;
            delta_theta = (wheel_radius * omega_o* dt)
                    / (R + (track_width/ 2));
            omega_i = (delta_theta * (R - (track_width / 2)))
                    / (wheel_radius * dt);
            new_speed = std::abs((R * delta_theta) / dt);
    }
    else if (PID_heading_output < 0) {
        //std::cout << "Turning right" << std::endl;
        R = wheel_base * 1/tan(PID_heading_output);
            alpha_o = atan(wheel_base / (R - (track_width / 2)));
            alpha_i = atan(wheel_base / (R + (track_width / 2)));
            omega_i += PID_velocity_output;
            delta_theta = (wheel_radius * omega_i* dt)
                    / (R + (track_width / 2));
            omega_o = (delta_theta * (R - (track_width / 2)))
                    / (wheel_radius * dt);
            new_speed = std::abs((R * delta_theta) / dt);
    }
    else {
        std::cout << "Going straight" << std::endl;
            //right_wheel_angle = 0;
            //left_wheel_angle = 0;

            //if (left_wheel_velocity >= right_wheel_velocity) {
            //    left_wheel_velocity += throttle;
            //    right_wheel_velocity = left_wheel_velocity;
            //} else {
            //   right_wheel_velocity += throttle;
            //    left_wheel_velocity = right_wheel_velocity;
            //}
            //new_speed = right_wheel_velocity*wheel_radius;
    }
    heading += delta_theta;
    speed = new_speed;
    std ::cout<<"heading : " << 180*heading/PI<<"\n";
    std ::cout<<"Speed :" << speed<<"\n";
}

 double Robot ::getHeading() {
    return heading;
 }

 double Robot ::getSpeed() {
    return speed;
 }

