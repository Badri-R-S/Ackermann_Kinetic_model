#include <iostream>
#include "../include/simulation.hpp"
#include "../include/userInput.hpp"
#include "../include/controller.hpp"
#include "../include/robot.hpp"


void Simulation::runSim(){
    double initial_heading = 0.0;
    double initial_velocity = 0.0;
    UserInput u_inp(initial_velocity, initial_heading);
    u_inp.getUserInputs();

    Robot car(1.0, 0.1, 0.25);
    double sterring  = car.computeTurnRadius(u_inp.getTargetVelocity(), u_inp.getTargetHeading());

    Controller car_controller(0.1, 0.0, 0.0, 10);
    std::vector<double> result = car_controller.computePID(initial_heading ,  u_inp.getTargetHeading(), 
                                                    initial_velocity, u_inp.getTargetVelocity());
    
    for(auto it:result){
        std::cout << it  << "\n"; 
    }
}