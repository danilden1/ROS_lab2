#include <ros/ros.h>
#include <lab_2/GetSolveOfEquations.h>
#include <iostream>
#include <string>
#include <cstdlib> // для функций rand() и srand()
#include <ctime> // для функции time()





int main(int argc, char **argv)
{
    srand(static_cast<unsigned int>(time(0))); // устанавливаем значение системных часов в качестве стартового числа

    ros::init(argc, argv, "get_solve_of_equations_client");
    ros::NodeHandle n;
    ros::ServiceClient lab_2_client = n.serviceClient<lab_2::GetSolveOfEquations>("get_solve_of_equations_server");
    lab_2::GetSolveOfEquations srv;
    ros::Rate loop_rate(1);

    float test[6] = {4.0, 6.0, 9.0, 5.0, 1.0, 18.0};
    while (ros::ok())
    {
        for(auto i = 0; i < 6; i++)
        {
            //srv.request.input_odds[i] = test[i];
            srv.request.input_odds[i] = rand() / 10000;
        }
        if (lab_2_client.call(srv))
            ROS_INFO_STREAM("Answer = " << srv.response.answer);
        else
            ROS_ERROR_STREAM("Fail");

        loop_rate.sleep();
    }
}
