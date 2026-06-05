// 03_movej - joint-space motion with MoveJ
//
// Usage: ./03_movej [robot_ip]
//
// Safety note: this example moves J1 by a small offset from the current state.
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

        // Enable motors and give the controller time to switch modes.
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

        const auto state = robot.GetState();
        rcore::sdk::JointPositions target{};
        for (size_t i = 0; i < 6; ++i)
        {
            target[i] = state.positions[i];
        }
        target[0] += 0.05; // Small J1 offset from the current state.

        std::printf("MoveJ target [rad]:");
        for (size_t i = 0; i < 6; ++i)
        {
            std::printf(" %.4f", target[i]);
        }
        std::printf("\n");

        // Synchronous mode: block until the motion finishes.
        auto result = robot.MoveJ(target);
        if (!result.IsSuccess())
        {
            std::fprintf(stderr, "MoveJ failed: code=%u msg=%s\n",
                         result.GetErrorCode(), result.GetErrorMsg().c_str());
            robot.Shutdown();
            return 1;
        }
        std::printf("MoveJ completed\n");

        robot.Shutdown();
        return 0;
    }
    catch (const std::exception &e)
    {
        std::fprintf(stderr, "Exception: %s\n", e.what());
        return 1;
    }
}
