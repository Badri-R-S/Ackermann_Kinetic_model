/**
 * @file simulation.cpp
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
#include <iostream>
#include <ostream>
#include <vector>
#include "../include/simulation.hpp"
#include "../include/userInput.hpp"
#include "../include/controller.hpp"
#include "../include/robot.hpp"

/**
 * @brief Function that converges the functionalities of all the cpp
          files under one roof.
 * 
 */
void Simulation::runSim() {
    double initial_heading = 0.0;
    double initial_velocity = 0.0;

    // getting user inputs
    UserInput u_inp(initial_velocity, initial_heading);
    u_inp.getUserInputs();
    std :: cout << "Got user inputs" << "\n";

    // creating an instance of the robot class
    Robot car(4.0, 0.3, 2.0);
    std:: cout << "Initialized car parameters" << std::endl;

    // creating an instance of the controller class
    Controller controller(0.25, 0.001, 0.1, 0.1, 0.5, 0.001, 0.01);

    // running the simulation loop
    for (float i = 0; i < 20; i+=0.1) {
        // computing errors
        controller.computePIDerror(u_inp.getTargetVelocity(),
        car.getSpeed(), u_inp.getTargetHeading(), car.getHeading());
        // computing PID gains
        std::vector<double> result = controller.computePID();
        // applying controller to robot and simulating it
        car.Simulate_robot_model(result[1], result[0], controller.getdt());
    }
}
