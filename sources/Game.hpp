#include "Team.hpp"
using namespace std;

#define min_away_points  50
#define min_home_points  55
#define max_points  100
#define mul_talent  10

class Game{
     Team * home;
     Team * away;
public:
    Game( Team & home, Team & away);
    Game();
    Team& make_game_return_winner();
    void change_teams( Team & team_home,Team & team_away);


};