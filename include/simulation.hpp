
/**
 * @file simulation.hpp
 * @author Driver - Smit Dumore
           Navigator - Badrinarayanan Raghunathan Srikumar
 * @brief  Hpp file that consists of the class Simulation definition.
 * @version 0.1
 * @date 2022-10-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */


// header guards
#ifndef INCLUDE_SIMULATION_HPP_
#define INCLUDE_SIMULATION_HPP_
#include<vector>

class Simulation {
 private:
       // simulation time variable
        int sim_time;
 public:
       /**
        * @brief Construct a new Simulation object
        */
       Simulation() {
              sim_time = 0.0;
       }
        /**
         * @brief - Function that converges the functionalities of all the cpp
                    files under one roof.
         * @param - none
         */
        void runSim();
};

#endif  // INCLUDE_SIMULATION_HPP_
