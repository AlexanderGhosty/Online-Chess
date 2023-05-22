#pragma once
#include <vector>

class GameState
{
public:
    GameState();

    // 0 - �����, 1 - ������
    // 0, 1, 2, 3, 4, 5, 6, 7, 8 - �����
    // 9, 10 - ���� �����
    // 11, 12 - �����
    // 13, 14 - �����
    // 15 - �����
    // 16 - ����

    enum class StateTeam { White, Black };

    StateTeam getYourTeam();
    void setYourTeam(StateTeam team);
    StateTeam getTeamToMove();
    void changeTeamToMove();

    // id
    void changePieceIdCounter();
    int getPieceIdCounter();
    void resetPieceIdCounter();
    // positions
    std::vector<std::vector<std::pair<int, int>>> getGameStatePositions();
    void changeGameStatePosition(StateTeam team, int id, int x, int y);
    // isWin
    bool get_isWin();
    

private:
    std::vector<std::vector<std::pair<int, int>>> positions;
    StateTeam yourTeam;
    StateTeam teamToMove;
    int pieceIdCounter;
    bool isWin;
};
