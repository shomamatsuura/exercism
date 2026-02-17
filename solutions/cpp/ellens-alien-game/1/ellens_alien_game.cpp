namespace targets {
    class Alien{
        private:
            int health{3};
        public:
            Alien(int x, int y){
                x_coordinate = x;
                y_coordinate = y;
            }
            int x_coordinate;
            int y_coordinate;
            int get_health(){
                return health;
            }
            bool hit();
            bool is_alive(){return health > 0;};
            bool teleport(int x_new, int y_new);
            bool collision_detection(Alien alien){return x_coordinate == alien.x_coordinate  && y_coordinate == alien.y_coordinate;};
    };
    bool Alien::hit(){
        if(health > 0){
            health--;
            return true;
        } else{
            return false;
        }                        
    }
    bool Alien::teleport(int x_new, int y_new){
        x_coordinate = x_new;
        y_coordinate = y_new;
        return true;
    };
}  // namespace targets
