
#include "Schedule.hpp"
#include <algorithm>
Schedule::Schedule(Leauge &leauge):leauge(&leauge) {
    this->game = Game();
}

void Schedule::run_season() {
    ///frist half of the season;
    for (unsigned int i=0;i<this->leauge->teams.size();i++){
        for (unsigned int j = i+1; j <this->leauge->teams.size() ; ++j) {
            this->game.change_teams(this->leauge->teams.at(i),this->leauge->teams.at(j));
            this->game.make_game_return_winner();
        }

    }
    ///second half of the season
    for (unsigned int i=0;i<this->leauge->teams.size();i++){
        for (unsigned int j = i+1; j <this->leauge->teams.size() ; ++j) {
            this->game.change_teams(this->leauge->teams.at(j),this->leauge->teams.at(i));
            this->game.make_game_return_winner();
        }
    }
}
void Schedule::show_table_end_results_statistics() {
    sort(this->leauge->teams.begin(),this->leauge->teams.end(),Team::lesss());
    for (unsigned int i = 0; i < this->leauge->teams.size(); ++i) {
        cout<< "the team in the "<<i<<" place is :"<<this->leauge->teams.at(i).name<<endl;
    }
}