
#include<vector>

#ifndef INCLUDE_CONTROLLER_HPP_
#define INCLUDE_CONTROLLER_HPP_

const double Kpmax = 1;
const double Kpmin = -1;
const double Kimax = 1;
const double Kimin = -1;
const double Kdmax = 1;
const double Kdmin = -1;
const double tmax = 0.05;

class Controller {
    double Kp;
    double Ki;
    double Kd;
    double dt;
    public:
    Controller(double p, double i, double d, double t);
    std::vector<double> computePID(double sp_angle, double pv_angle, double sp_vel, double pv_vel);
    double getKp();
    /// Function to return Proportional constant
    double getKi();
    /// Function to return Integral constant
    double getKd();
    /// Function to return Derivative constant
    double getdt();
    /// Function to return time interval
};
#endif