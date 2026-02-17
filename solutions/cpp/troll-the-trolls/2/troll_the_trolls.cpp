namespace hellmath {

// TODO: Task 1 - Define an `AccountStatus` enumeration to represent the four
// account types: `troll`, `guest`, `user`, and `mod`.
enum class AccountStatus{
    troll,
    guest,
    user,
    mod
};
// TODO: Task 1 - Define an `Action` enumeration to represent the three
// permission types: `read`, `write`, and `remove`.
enum class Action{
    read,
    write,
    remove
};

// TODO: Task 2 - Implement the `display_post` function, that gets two arguments
// of `AccountStatus` and returns a `bool`. The first argument is the status of
// the poster, the second one is the status of the viewer.
bool display_post(AccountStatus poster_status, AccountStatus viewer_status){
    if(poster_status == AccountStatus::troll){
        return viewer_status == AccountStatus::troll;
    }
    return true;
}
// TODO: Task 3 - Implement the `permission_check` function, that takes an
// `Action` as a first argument and an `AccountStatus` to check against. It
// should return a `bool`.
bool permission_check(Action action, AccountStatus action_status){
    switch(action_status){
        case AccountStatus::troll:
        case AccountStatus::user:
            return action == Action::read || action == Action::write;
        case AccountStatus::guest:
            return  action == Action::read;
        case AccountStatus::mod:
            return action == Action::read || action == Action::write || action == Action::remove;
        default:
            return false;
    }
}
// TODO: Task 4 - Implement the `valid_player_combination` function that
// checks if two players can join the same game. The function has two parameters
// of type `AccountStatus` and returns a `bool`.
bool valid_player_combination(AccountStatus player1_action_status, AccountStatus player2_action_status){
    if(player1_action_status == AccountStatus::guest || player2_action_status == AccountStatus::guest){
        return false;
    }
    if((player1_action_status == AccountStatus::troll && player2_action_status != AccountStatus::troll) || (player1_action_status != AccountStatus::troll && player2_action_status == AccountStatus::troll)){
        return false;
    }
    return true;
    
}

// TODO: Task 5 - Implement the `has_priority` function that takes two
// `AccountStatus` arguments and returns `true`, if and only if the first
// account has a strictly higher priority than the second.
bool has_priority(AccountStatus first_account_status, AccountStatus second_account_status){
    return first_account_status > second_account_status;
}
}  // namespace hellmath
