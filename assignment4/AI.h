#ifndef AI_H
#define AI_H

struct AI_room{
    int event; // 0 empty, 1 wumpus, 2 bat, 3 pit, 4 gold, 5 unknown
    int has_wumpus;
    int has_bat;
    int has_pit;
    int has_gold;

};

class AI{
private:
    AI_room* AI_board;
    bool* path_board; // true for path, false for none path
public:
    AI();
    AI(int);


};

#endif
