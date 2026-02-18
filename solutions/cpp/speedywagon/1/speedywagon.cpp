#include "speedywagon.h"

namespace speedywagon {

// Enter your code below:

// Please don't change the interface of the uv_light_heuristic function
int uv_light_heuristic(std::vector<int>* data_array) {
    double avg{};
    for (auto element : *data_array) {
        avg += element;
    }
    avg /= data_array->size();
    int uv_index{};
    for (auto element : *data_array) {
        if (element > avg) ++uv_index;
    }
    return uv_index;
}
bool uv_alarm(pillar_men_sensor* sensor){
    if(sensor == nullptr) return false;
    int level = uv_light_heuristic(&(sensor->data));
    return level > sensor->activity;
}
bool connection_check(pillar_men_sensor* sensor){
    return sensor != nullptr;
}
int activity_counter(pillar_men_sensor* sensor_array, int capacity){
    int accumulated_acitivity = 0;
    for(int i = 0; i < capacity; ++i){
        accumulated_acitivity += (sensor_array + i)->activity;
    }
    return accumulated_acitivity;
}
bool alarm_control(pillar_men_sensor* db){
    if(db == nullptr) return false;
    return db->activity > 0;
}
}  // namespace speedywagon
