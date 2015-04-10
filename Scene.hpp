#ifndef SCENE_H
#define SCENE_H
#include "Game.hpp"
#include "Player.hpp"
#include "Chameleon.hpp"

class Scene : public Game {
public:
    Scene(int scrwidth, int scrheight, std::string title, int style);
    ~Scene();
    void update(float deltaTime);
    void draw();
    void processEvents();
private:
    Player player;
    std::vector<Chameleon> chameleons;
};

#endif // SCENE_H
