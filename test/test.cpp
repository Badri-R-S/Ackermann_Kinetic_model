/**
 * @file test.cpp
 * @author Driver - Badrinarayanan Raghunathan Srikumar
           Navigator - Smit Dumore
 * @brief  Test program that contains test stubs to test the cpp and hpp files
 * @version 0.1
 * @date 2022-10-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */

// Necessary header files added
#include <gtest/gtest.h>
#include<iostream>
#include "../include/controller.hpp"
#include "../include/robot.hpp"
#include "../include/userInput.hpp"
#include "../include/simulation.hpp"

::testing::AssertionResult IsBetweenmaxmin(double val, double a, double b) {
    if ( ( val >= a) && ( val <= b) )
        return ::testing::AssertionSuccess();
    else
        return ::testing::AssertionFailure()
               << val << " is outside the range " << a << " to " << b;
}
// Unit test to check if the velocity Proportional constant is in the range
/**
 * @brief Test stub to check if Kp_vel is in range
 * 
 */
TEST(testingforkpvel, Testfail) {
     Controller Controller(0.05, 0.001, 0.1, 0.1, 0.5, 0.001, 0.01);
     EXPECT_TRUE(IsBetweenmaxmin(Controller.getKp_vel(), Kpmin, Kpmax));
}
// Unit test to check if the velocity Integral constant is in the range
/**
 * @brief Test stub to check if Ki_vel is in the range
 * 
 */
TEST(testingforkivel, TestFail) {
     Controller Controller(0.05, 0.001, 0.1, 0.1, 0.5, 0.001, 0.01);
     EXPECT_TRUE(IsBetweenmaxmin(Controller.getKi_vel(), Kimin, Kimax));
}
// Unit test to check if the velocity Derivative constant is in the range
/**
 * @brief Test stub to check if Kd_vel is in the range
 * 
 */
TEST(testingforkdvel, TestFail) {
     Controller Controller(0.05, 0.001, 0.1, 0.1, 0.5, 0.001, 0.01);
     EXPECT_TRUE(IsBetweenmaxmin(Controller.getKd_vel(), Kdmin, Kdmax));
}
// Unit test to check if dt is in the range
/**
 * @brief Test stub to check if dt is in the range
 * 
 */
TEST(testingfortime, TestFail) {
     Controller Controller(0.05, 0.001, 0.1, 0.1, 0.5, 0.001, 0.01);
     EXPECT_TRUE(IsBetweenmaxmin(Controller.getdt(), 0, tmax));
}
// Unit test to check if heading proportional constant is in the range
/**
 * @brief Test stub to check if Kp_head is in the range
 * 
 */
TEST(testingforkphead, TestFail) {
     Controller Controller(0.05, 0.001, 0.1, 0.1, 0.5, 0.001, 0.01);
     EXPECT_TRUE(IsBetweenmaxmin(Controller.getKp_head(), Kpmin, Kpmax));
}
// Unit test to check if heading Integral constant is in the range
/**
 * @brief Test stub to check if Ki_head is in the range
 * 
 */

TEST(testingforkihead, TestFail) {
     Controller Controller(0.05, 0.001, 0.1, 0.1, 0.5, 0.001, 0.01);
     EXPECT_TRUE(IsBetweenmaxmin(Controller.getKi_head(), Kimin, Kimax));
}
// Unit test to check if heading derivative constant is in the range
/**
 * @brief Test stub to check if Kd_head is in the range
 * 
 */
TEST(testingforkdhead, TestFail) {
     Controller Controller(0.05, 0.001, 0.1, 0.1, 0.5, 0.001, 0.01);
     EXPECT_TRUE(IsBetweenmaxmin(Controller.getKd_head(), Kdmin, Kdmax));
}
// Test stub to check userInput getter functions
/**
 * @brief Test stub to check userInput getter functions
 * 
 */ 
TEST(Targetvelcheck, testcompute) {
    UserInput UserInput(0.0 , 0.0);
    EXPECT_EQ(UserInput.getTargetVelocity() , 0);
    EXPECT_EQ(UserInput.getTargetHeading(), 0);
}
// Unit test to check if the error vector returned by PIDerror compute
// function is of proper size
/**
 * @brief Test stub to check error vector returned by computePIDerror
 * 
 */
TEST(PIDerrorcheck, testcompute) {
     Controller Controller(0.05, 0.001, 0.1, 0.1, 0.5, 0.001, 0.01);
     std :: vector <double> error;
     error = Controller.computePIDerror(10.0, 5.0, 10.0, 5.0);
     EXPECT_EQ(error.size(), 2);
}
// Unit test to check if the PID heading ouput is less than 45 degrees
/**
 * @brief Test stub to check if the output of PID heading is less than
          45 degrees
 * 
 */
/*
TEST(PIDcompute, testcompute) {
  Controller Controller(0.05, 0.001, 0.1, 0.1, 0.5, 0.001, 0.01); 
  std :: vector <double> error = { 5.0 , 5.0};
  std :: vector <double> PID_output;
  PID_output = Controller.computePID(error);
  //std::cout<<PID_output.size();
  if(PID_output.size() > 0){
    EXPECT_LE(PID_output[1],(45/180) * 3.14159265); 
  }else{
    EXPECT_EQ(PID_output.size() , 0);
  }
}
*/
// Unit test to check if initial heading and speed are assigned correctly
/**
 * @brief Test stub to check if initial heading and speed are assigned 
          correctly
 * 
 */
TEST(Robot, testcompute) {
     Robot Robot(2.0, 2.0, 2.0);
     EXPECT_EQ(Robot.getHeading(), 0);
     EXPECT_EQ(Robot.getSpeed(), 0);
}


