#include "game.h"
#include <iostream>

Game::Game():
    window(sf::VideoMode(480,320), "Snake"),
    t1(), t2(), t3(), s1(), s2(), s3()
{
    srand(time(NULL));
    t1.loadFromFile("images/white.png");
    t2.loadFromFile("images/red.png");
    t3.loadFromFile("images/green.png");

    s1.setTexture(t1);
    s2.setTexture(t2);
    s3.setTexture(t3);

    treat.first = rand()%30;
    treat.second = rand()%20;
    s3.setPosition(treat.first*16,treat.second*16);
}

void Game::run() {
    sf::Clock clock;
    sf::Time time;
    sf::Time perFrame = sf::seconds(1.f/60.f);

    while(window.isOpen()) {
        time += clock.restart();
        if(time > perFrame){
            time -= perFrame;
            procesEvent();
            update(perFrame);
            render();
        }
    }
}


void Game::procesEvent() {

    sf::Event event;

    while(window.pollEvent(event)) {
        if(event.type == sf::Event::Closed) {window.close();}
        if(event.type == sf::Event::KeyPressed){
            if(event.key.code == sf::Keyboard::Right) dir = 0;
            if(event.key.code == sf::Keyboard::Down) dir = 1;
            if(event.key.code == sf::Keyboard::Left) dir = 2;
            if(event.key.code == sf::Keyboard::Up) dir = 3;
        }
    }
}

void Game::update(sf::Time time) {

    static sf::Time timer = sf::Time::Zero;
    timer += time;
    if(timer > sf::seconds(1.f/8.f)){
        timer -= sf::seconds(1.f/8.f);

        if(p[0].first == treat.first && p[0].second == treat.second) {
            length += 1;
            treat.first = rand()%30;
            treat.second = rand()%20;
            s3.setPosition(treat.first*16,treat.second*16);
        }

        for(int i=length;i>0;i--){
            p[i].first = p[i-1].first;
            p[i].second = p[i-1].second;
        }

        if(dir==0) p[0].first += 1;
        if(dir==1) p[0].second += 1;
        if(dir==2) p[0].first -= 1;
        if(dir==3) p[0].second -= 1;

        if(p[0].first > 29) p[0].first = 0;
        if(p[0].first < 0) p[0].first = 29;
        if(p[0].second > 19) p[0].second = 0;
        if(p[0].second < 0) p[0].second = 19;

    }
}

void Game::render() {
    window.clear(sf::Color::White);
    for(int i=0;i<W;i++){
        for(int j=0;j<H;j++){
            s1.setPosition(i*16, j*16);
            window.draw(s1);
        }
    }
    for(int i=length;i>=0;i--){
        s2.setPosition(p[i].first*16, p[i].second*16);
        window.draw(s2);
    }
    window.draw(s3);
    window.display();
}

