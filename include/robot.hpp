



#ifndef INCLUDE_ROBOT_HPP_
#define INCLUDE_ROBOT_HPP_




class Robot {
    double wheel_base;
    double wheel_radius;
    double track_width;
    public :
    Robot( double wb, double wr, double tw);
    double computeTurnRadius(double target_vel, double target_heading );
};

#endif
