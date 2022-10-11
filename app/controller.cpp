#include "../include/controller.hpp"
#include <iostream>

Controller:: Controller(double p, double i, double d, double t) {
    Kp = p;
    Ki = i;
    Kd = d;
    dt = t;
}

std::vector<double> Controller :: computePID(double sp_angle, double pv_angle, double sp_vel, double pv_vel) {
    std:: vector<double> result;
    result.push_back(5);
    result.push_back(7);
    return result;
}

double Controller:: getKp() {
    return Kp;
}

double Controller ::getKd() {
    return Kd;
}
double Controller ::getKi() {
    return Ki;
}
double Controller ::getdt() {
    return dt;
}
