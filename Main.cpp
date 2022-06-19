


#include <iostream>
using namespace std;
#include <vector>


#include "sources/Leauge.hpp"
#include "sources/Schedule.hpp"

int main(){

    Leauge my_leauge;
    Schedule my_sch(my_leauge);
    my_sch.run_season();
    vector<string> best_teams = my_leauge.best_teams(5);
    for (auto i : best_teams) {
        cout<<i<<endl;
    }
    my_sch.show_table_end_results_statistics();
    cout<<my_leauge.longest_loss_team()<<endl;
    cout<<my_leauge.longest_win_team()<<endl;

}
