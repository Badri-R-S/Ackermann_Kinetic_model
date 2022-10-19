/**
 * @file main.cpp
 * @author Driver - Smit Dumore
           Navigator - Badrinarayanan Raghunathan Srikumar
 * @brief  contains the main function. This is the driver code
 * @version 0.1
 * @date 2022-10-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */

// cpp headers
#include <iostream>
#include "../include/simulation.hpp"
#include <vector>

int main() {
    // creating a Simulation class object
    Simulation sim;
    std::vector<double> test;
    test = sim.runSim();
    return 0;
}
