#ifndef GAME_H
#define GAME_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Game
{
public:
    Game();
    void run();
private:
    void procesEvent();
    void update(sf::Time time);
    void render();

    int W = 30;
    int H = 20;
    int length = 4;
    int dir= 0;
    std::pair<int,int> p[100];
    std::pair<int,int> treat;

    sf::RenderWindow window;
    sf::Texture t1, t2, t3;
    sf::Sprite s1, s2, s3;
};

#endif // GAME_H
