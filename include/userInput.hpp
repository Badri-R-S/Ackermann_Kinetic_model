
#ifndef INCLUDE_USERINPUT_HPP_
#define INCLUDE_USERINPUT_HPP_


class userInput{
public :
    double intial_velocity = 0.0;  
    double intial_heading = 0.0;  
    double target_velocity;
    double target_heading;

 
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