

#include "Game.hpp"
#include <time.h>
Game::Game( Team &home,  Team &away):home(&home),away(&away) {}

Game::Game():home(nullptr),away(nullptr) {}

Team& Game::make_game_return_winner() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> away_team(min_away_points,max_points);
    uniform_int_distribution<> home_team(min_home_points,max_points);
    std::uniform_real_distribution<> draw(0,1.0);

    int home_points = home_team(gen)+round(this->home->skill * mul_talent);
    int away_points = away_team(gen)+round(this->away->skill * mul_talent);
    this->home->update_points_plus(home_points);
    this->home->update_points_minus(away_points);
    this->away->update_points_plus(away_points);
    this->away->update_points_minus(home_points);
    if(home_points>away_points){
        this->home->update_wins();
        this->away->update_loss();
        return *(this->home);
    }
    if(home_points<away_points){
        this->away->update_wins();
        this->home->update_loss();
        return *(this->away);
    }
    srand( time(NULL) ); //Randomize seed initialization
    int randNum = rand() % 2;
    if(randNum==0){
        this->home->update_wins();
        this->away->update_loss();
        return *(this->home);
    }
    this->away->update_wins();
    this->home->update_loss();
    return *(this->away);

}

void Game::change_teams(Team &team_home, Team &team_away) {
    this->home = &team_home;
    this->away = &team_away;
}

