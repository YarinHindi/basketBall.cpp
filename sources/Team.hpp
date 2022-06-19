

#include <time.h>
#include <string>
#include <iostream>
#include <random>
using namespace std;

class Team{



public:
    struct lesss{
        bool operator()(Team & first, Team & second){
            if(first.wins==second.wins){
                return (first.points_plus-first.points_minus<second.points_plus-second.points_minus) ? false : true;
            }
            return first.wins<second.wins ? false : true;
        }
    };
    double skill;
    int wins;
    int loss;
    int counter_loss_in_a_row;
    int counter_win_in_a_row;
    int max_loss_in_a_row;
    int max_win_in_a_row;
    int points_plus;
    int points_minus;
    Team( const string & name);
    void update_wins();
    void update_loss();
    void update_points_plus(int num);
    void update_points_minus(int num);
    string name;

};