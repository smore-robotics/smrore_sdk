// 04_movel - Cartesian line motion with MoveL
//
// Usage: ./04_movel [robot_ip]
//
// Safety note: this example moves through conservative Cartesian targets.
// Verify the workspace is clear and emergency stop is reachable before running.

#include "sdk/robot.hpp"

#include <chrono>
#include <cstdio>
#include <exception>
#include <string>
#include <thread>

int main(int argc, char **argv)
{
    const std::string robot_ip = (argc > 1) ? argv[1] : "";

    try
    {
        rcore::sdk::Robot robot;
        if (!robot.Initialize(robot_ip))
        {
            std::fprintf(stderr, "Initialize failed\n");
            return 1;
        }

        auto enable_result = robot.Enable();
        if (!enable_result.IsSuccess())
        {
            std::fprintf(stderr, "Enable failed: code=%u msg=%s\n",
                         enable_result.GetErrorCode(),
                         enable_result.GetErrorMsg().c_str());
            robot.Shutdown();
            return 1;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        // Move to a conservative start pose with MoveP, then execute a short
        // Cartesian line segment with MoveL.
        rcore::sdk::Vec<double, 3> rpy_zero{0.0, 0.0, 0.0};
        rcore::sdk::Vec<double, 3> start_translation{0.3, -0.05, 0.45};
        rcore::sdk::Vec<double, 3> target_translation{0.3, 0.05, 0.45};
        const auto start =
            rcore::sdk::Pose::FromEuler(start_translation, rpy_zero);
        const auto target =
            rcore::sdk::Pose::FromEuler(target_translation, rpy_zero);

        auto move_p = robot.MoveP(start);
        if (!move_p.IsSuccess())
        {
            std::fprintf(stderr, "MoveP to start failed: code=%u msg=%s\n",
                         move_p.GetErrorCode(), move_p.GetErrorMsg().c_str());
            robot.Shutdown();
            return 1;
        }

        auto result = robot.MoveL(target);
        if (!result.IsSuccess())
        {
            std::fprintf(stderr, "MoveL failed: code=%u msg=%s\n",
                         result.GetErrorCode(), result.GetErrorMsg().c_str());
            robot.Shutdown();
            return 1;
        }
        std::printf("MoveL completed\n");

        robot.Shutdown();
        return 0;
    }
    catch (const std::exception &e)
    {
        std::fprintf(stderr, "Exception: %s\n", e.what());
        return 1;
    }
}
