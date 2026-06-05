// 02_read_state - read robot state and motor status: GetState / GetMotorStatus
//
// Usage: ./02_read_state [robot_ip]

#include "sdk/robot.hpp"

#include <cstddef>
#include <cstdio>
#include <string>

int main(int argc, char **argv)
{
    const std::string robot_ip = (argc > 1) ? argv[1] : "";

    rcore::sdk::Robot robot;
    if (!robot.Initialize(robot_ip))
    {
        std::fprintf(stderr, "Initialize failed\n");
        return 1;
    }

    // Full state snapshot: joints, Cartesian pose, errors, and control mode.
    const auto state = robot.GetState();

    std::printf("Joint positions [rad]:");
    for (double q : state.positions)
    {
        std::printf(" %.4f", q);
    }
    std::printf("\n");

    std::printf("TCP position [m]: %.4f %.4f %.4f\n", state.cartesian_position[0],
                state.cartesian_position[1], state.cartesian_position[2]);
    std::printf("Control mode: %d\n", static_cast<int>(state.control_mode));
    std::printf("Latched error count: %zu\n", state.errors.GetLatchedErrorCount());

    // Motor hardware status.
    const auto motor = robot.GetMotorStatus();
    std::printf("motor.enabled=%s estop=%s error=%s operational=%s\n",
                motor.enabled ? "true" : "false",
                motor.estop ? "true" : "false",
                motor.error ? "true" : "false",
                motor.operational ? "true" : "false");

    robot.Shutdown();
    return 0;
}
