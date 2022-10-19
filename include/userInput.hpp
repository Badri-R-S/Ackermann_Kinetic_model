
/**
 * @file userInput.hpp
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
#ifndef INCLUDE_USERINPUT_HPP_
#define INCLUDE_USERINPUT_HPP_


class UserInput{
    double intial_velocity = 0.0;
    double intial_heading = 0.0;
    double target_velocity  = 0.0;
    double target_heading = 0.0;
 public :
    /**
    * @brief: Constructor for the UserInput class
    * @param - iv  intial velocity
    * @param - ih intial heading angle
    * @return: None
    */
    UserInput(double iv, double ih);

    /**
    * @brief: Prompts user for target inputs
    * @return: None
    */
    void getUserInputs();

    /**
    * @brief: Return the target velocity.
    * @return: target velocity.
    */
    double getTargetVelocity();

    /**
    * @brief: Return the target heading.
    * @return: target heading.
    */
    double getTargetHeading();
};

#endif  // INCLUDE_USERINPUT_HPP_
