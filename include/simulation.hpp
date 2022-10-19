
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

class Simulation {
 private:
       // simulation time variable
        int sim_time;
 public:
        /**
         * @brief - function to run the simulation of car
         * @param - none
         */
        void runSim();
};

#endif  // INCLUDE_SIMULATION_HPP_
