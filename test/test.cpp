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