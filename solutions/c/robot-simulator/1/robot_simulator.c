#include "robot_simulator.h"

static void robot_advance(robot_status_t *robot){
    switch(robot -> direction){
        case DIRECTION_EAST:
            ++robot->position.x;
            break;
        case DIRECTION_WEST:
            --robot -> position.x;
            break;
        case DIRECTION_NORTH:
            ++robot -> position.y;
            break;
        // case DIRECTION_SOUTH:
        default:
            --robot -> position.y;
    } 
}

robot_status_t robot_create(robot_direction_t direction, int x, int y){
    robot_position_t current_position = {x, y};
    robot_status_t current_status = {direction, current_position};
    return current_status;
}


void robot_move(robot_status_t *robot, const char *commands){
    for(; *commands != '\0'; ++commands){
        char command = *commands;
        switch(command){
            case 'R':
                robot -> direction = robot -> direction == DIRECTION_WEST ? DIRECTION_NORTH : robot -> direction + 1 ;
                break;
            case 'L':
                robot -> direction = robot -> direction == DIRECTION_NORTH ? DIRECTION_WEST : robot -> direction - 1 ;
                break;
            case 'A':
                robot_advance(robot);
                break;
        }
    }        
}



