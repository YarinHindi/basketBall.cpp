
#pragma once
#include "Game.hpp"

#pragma once
#define num_of_teams 20

class Leauge{

public:
    vector<string> nba_teams_names = {
            "Boston Celtics" , "New York Knicks" ,
            "Toronto Raptors" , "Chicago Bulls" ,
            "Cleveland Cavaliers" , "Detroit Pistons" ,
            "Milwaukee Bucks" , "Miami Heat" ,
            "Washington Wizards" ,"Orlando Magic" ,
            "Denver Nuggets" , "New Orleans Pelicans" ,
            "Utah Jazz" , "Golden State Warriors" ,
            "LA Clippers" , "Los Angeles Lakers" ,
            "Phoenix Suns" , "Houston Rockets" ,
            "Memphis Grizzlies" , "San Antonio Spurs"};
    Leauge();
    vector<Team> teams;
    int longest_win_team();
    int longest_loss_team();
    int num_teams_positive_rank();
    vector<string> best_teams(int n);
    static bool order(const Team &first,const Team &second);
};
