

#include "Leauge.hpp"

class Schedule{


public:
    Game  game;
    Leauge * leauge;
    Schedule(Leauge & leauge);
    void run_season();
    void show_table_end_results_statistics();
    friend bool order(const Team &first,const Team &second);





};