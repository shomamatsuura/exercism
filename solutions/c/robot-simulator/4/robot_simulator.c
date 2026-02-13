#include "robot_simulator.h"

static inline void robot_advance(robot_status_t *robot, robot_direction_t direction){
    int dx[] = {0, 1, 0, -1};    // N, E, S, W
    int dy[] = {1, 0, -1, 0};

    robot->position.x += dx[direction];
    robot->position.y += dy[direction];        
}

robot_status_t robot_create(robot_direction_t direction, int x, int y){
    robot_status_t robot;
    robot.position.x = x;
    robot.position.y = y;
    robot.direction = direction;

    return robot;
    
}
void robot_move(robot_status_t *robot, const char *commands){
    for(; *commands !='\0'; ++commands){
        switch(*commands){
            case 'R':
                robot->direction = ((robot->direction + 1) % DIRECTION_MAX);
                break;
            case 'L':
                robot->direction = ((robot->direction + DIRECTION_MAX - 1) % DIRECTION_MAX);
                break;
            case 'A':
                robot_advance(robot, robot->direction);
                break;
            default:
                continue;
        }
    }
}