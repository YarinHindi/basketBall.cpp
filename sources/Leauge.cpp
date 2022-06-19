
#include "Leauge.hpp"
Leauge::Leauge() {
    for (unsigned int i =0; i<num_of_teams;i++){
        this->teams.push_back(Team(nba_teams_names.at(i)));
    }
}
vector<string> Leauge::best_teams(int n) {
    sort(this->teams.begin(),this->teams.end(),Team::lesss());
    vector<string> ans;
    for (unsigned int i = 0; i < n; ++i) {
        ans.push_back("in the "+to_string(i)+" place with "+to_string(this->teams.at(i).wins)+" wins :"+
        this->teams.at(i).name);
    }
    return ans;
}
int Leauge::num_teams_positive_rank() {
    int counter=0;
    for(unsigned int i=0; i<this->teams.size();i++){
        if(this->teams.at(i).points_plus-this->teams.at(i).points_minus>0){
            counter++;
        }
    }
    return counter;
}
int Leauge::longest_loss_team() {
    unsigned int index = 0;
    for (unsigned int i = 0; i < this->teams.size(); ++i) {
        if(this->teams.at(index).max_loss_in_a_row>this->teams.at(i).max_loss_in_a_row){
            index = i;
        }
    }
    return this->teams.at(index).max_loss_in_a_row;
}
int Leauge::longest_win_team() {
    unsigned int index = 0;
    for (unsigned int i = 0; i < this->teams.size(); ++i) {
        if(this->teams.at(index).max_win_in_a_row>this->teams.at(i).max_win_in_a_row){
            index = i;
        }
    }
    return this->teams.at(index).max_win_in_a_row;
}
//should use at the end if you want to see it in order from the best to worst

