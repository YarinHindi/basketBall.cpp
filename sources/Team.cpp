
#include "Team.hpp"

Team::Team(const string & name):name(name) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> talent_for_team(0,1.0);
    this->skill = talent_for_team(gen);
    this->max_loss_in_a_row = 0;
    this->max_win_in_a_row = 0;
    this->counter_loss_in_a_row=0;
    this->counter_win_in_a_row=0;
    this->points_minus=0;
    this->points_plus=0;
    this->wins=0;
    this->loss = 0;

}

void Team::update_loss() {
    this->loss++;
    this->counter_loss_in_a_row++;
    this->counter_win_in_a_row = 0;
    if(this->max_loss_in_a_row<=counter_loss_in_a_row){
        this->max_loss_in_a_row = counter_loss_in_a_row;
    }

}
void Team::update_wins() {
    this->wins++;
    this->counter_win_in_a_row++;
    this->counter_loss_in_a_row=0;
    if(this->max_win_in_a_row<= this->counter_win_in_a_row){
        this->max_win_in_a_row = this->counter_win_in_a_row;
    }
}
void Team::update_points_minus(int num) {
    this->points_minus+=num;
}
void Team::update_points_plus(int num) {
    this->points_plus+=num;
}