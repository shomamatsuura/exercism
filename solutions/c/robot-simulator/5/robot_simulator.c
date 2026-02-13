#include "robot_simulator.h"

static const int DX[] = {0, 1, 0, -1};    // N, E, S, W
static const int DY[] = {1, 0, -1, 0};    // N, E, S, W


static inline void robot_advance(robot_status_t *robot){
    if(robot->direction < 0 || robot->direction >= DIRECTION_MAX) return;
    robot->position.x += DX[robot->direction];
    robot->position.y += DY[robot->direction];        
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
                robot_advance(robot);
                break;
            default:
                continue;
        }
    }
}