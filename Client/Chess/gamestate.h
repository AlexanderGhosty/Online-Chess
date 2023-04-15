
#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <vector>


class GameState
{
public:
    GameState();

    // 0 - белые, 1 - Черные
    // 0, 1, 2, 3, 4, 5, 6, 7, 8 - пешки
    // 9, 10 - кони белых
    // 11, 12 - слоны
    // 13, 14 - ладья
    // 15 - ферзь
    // 16 - слон

    enum class StateTeam{ White, Black };

    StateTeam getYourTeam();
    void setYourTeam(StateTeam team);
    StateTeam getTeamToMove();
    void changeTeamToMove();


private:
    std::vector<std::vector<std::pair<int, int>>> positions;
    StateTeam yourTeam;
    StateTeam teamToMove;

};

#endif // GAMESTATE_H
