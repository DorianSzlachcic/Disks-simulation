#pragma once

#include <SFML/Graphics.hpp>

class Disk
{
public:
    Disk() = default;
    Disk(sf::RenderWindow& target);
    ~Disk() = default;

    void draw();
    void logic();

private:
    sf::CircleShape shape;
    sf::RenderWindow& window;
    sf::Vector2f velocity;

    double mass;
    bool dragged = false;

    void move();
};
