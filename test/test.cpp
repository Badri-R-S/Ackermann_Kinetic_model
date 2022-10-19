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
// Unit test to check if the Proportional constant is in the range
/**
 * @brief Test stub to check if Kp is in range
 * 
 */
TEST(testingforkp, Testfail) {
    Controller Controller(0.5, 1, 0.01, 0.05);
    EXPECT_TRUE(IsBetweenmaxmin(Controller.getKp(), Kpmin, Kpmax));
}
// Unit test to check if the Integral constant is in the range
/**
 * @brief Test stub to check if the Integral constant is in the range
 * 
 */
TEST(testingforki, TestFail) {
     Controller Controller(0.5, 1, 0.01, 0.05);
     EXPECT_TRUE(IsBetweenmaxmin(Controller.getKi(), Kimin, Kimax));
}
// Unit test to check if the Derivative constant is in the range
/**
 * @brief Test stub to check if the Derivative constant is in the range
 * 
 */
TEST(testingforkd, TestFail) {
     Controller Controller(0.5, 1, 0.01, 0.05);
     EXPECT_TRUE(IsBetweenmaxmin(Controller.getKd(), Kdmin, Kdmax));
}
// Unit test to check if dt is in the range
/**
 * @brief Test stub to check if dt is in the range
 * 
 */
TEST(testingfortime, TestFail) {
     Controller Controller(0.5, 1, 0.01, 0.05);
     EXPECT_TRUE(IsBetweenmaxmin(Controller.getdt(), 0, tmax));
}
// Unit test to check computeturn radius function
/**
 * @brief Test stub to check TurnRadiusompute function
 * 
 */
TEST(TurnRadiuscompute, testcompute) {
    double target_vel = 5;
    double target_heading = 1;
    Robot Robot(5 , 5 , 5);
    double value = Robot.computeTurnRadius(target_vel, target_heading);
    EXPECT_EQ(value , 0.0);
}
// Unit test to check compute function
/**
 * @brief Test stub to check compute function
 * 
 */ 
TEST(Pidcompute, testcompute) {
    double sp_vel = 5;
    double pv_vel = 1;
    double sp_angle = 5;
    double pv_angle = 1;
    Controller Controller(0.5, 1, 0.01, 0.05);
    std::vector<double> value = Controller.computePID(sp_vel, pv_vel,
    sp_angle, pv_angle);
    EXPECT_EQ(value[0], 0.0);
    EXPECT_EQ(value[1], 0.0);
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
