
#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <vector>
#include <QObject>
#include <QDebug>
#include <array>

// server include
#pragma comment(lib, "ws2_32.lib")
#include <WinSock2.h>
#include <WS2tcpip.h>


class GameState: public QObject
{
    Q_OBJECT

public:
    GameState(QObject *parent);

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

    // id
    void changePieceIdCounter();
    int getPieceIdCounter();
    void resetPieceIdCounter();

    // positions
    // std::vector<std::vector<std::pair<int, int>>> getGameStatePositions();
    std::array<std::array<std::pair<int, int>, 16>,2> getGameStatePositions();
    void changeGameStatePosition(StateTeam team, int id,int x, int y);

    // server
    SOCKET connection;

private:
    // std::vector<std::vector<std::pair<int, int>>> positions;
    std::array<std::array<std::pair<int, int>, 16>,2> positions;
    StateTeam yourTeam;
    StateTeam teamToMove;
    int pieceIdCounter;

signals:
    void startReceivingSig();

};

#endif // GAMESTATE_H
