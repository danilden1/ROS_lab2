#include <ros/ros.h>
#include <lab_2/GetSolveOfEquations.h>
#include <iostream>
#include <string>

bool solve(lab_2::GetSolveOfEquations::Request  &req,
         lab_2::GetSolveOfEquations::Response &res);


int main(int argc, char **argv)
{
    ros::init(argc, argv, "get_solve_of_equations_server");
    ros::NodeHandle n;

    ros::ServiceServer lab_2_service = n.advertiseService("get_solve_of_equations_server", solve);
    ros::spin();
    
    return 0;
}

bool solve(lab_2::GetSolveOfEquations::Request  &req,
           lab_2::GetSolveOfEquations::Response &res)
{
    res.answer = "hz";
    float a = req.input_odds[0];
    float b = req.input_odds[1];
    float c = req.input_odds[2];
    float d = req.input_odds[3];
    float e = req.input_odds[4];
    float f = req.input_odds[5];

    ROS_INFO("request: a = %f, b = %f, c = %f, d = %f, e = %f, f = %f",
    a, b, c, d, e, f);
    if((b * d - a * e) == 0)
    {
        res.answer = "NO ROOTS";
        return true;
    }
    float x = (b * f - c * e)/(b * d - a * e);
    float y = (c * d - a * f)/(b * d - a * e);
    res.answer = "x= " + std::to_string(x) + ", y= " + std::to_string(y);
    return true;
}