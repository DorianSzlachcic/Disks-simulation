#include <math.h>
#include <iostream>


#include "disk.h"
#include "funcs.h"

Disk::Disk(sf::RenderWindow& target) : window(target)
{
    const int margin_from_border = 10;
    int radius = random_number(10, 20);

    shape = sf::CircleShape(radius);
    shape.setFillColor(sf::Color(random_number(256), random_number(256), random_number(256)));
    shape.setOutlineColor(sf::Color::Black);
    shape.setOutlineThickness(1);
    shape.setPosition(
        random_number(margin_from_border, window.getSize().x - 2*radius - margin_from_border),
        random_number(margin_from_border, window.getSize().y - 2*radius - margin_from_border)
    );

    velocity = sf::Vector2f(random_number(-2, 2), random_number(-2, 2));
    mass = random_number(1, 100) / 10;
}

void Disk::draw()
{
    window.draw(shape);
}

void Disk::logic()
{
    sf::Vector2f mouse_position = sf::Vector2f(sf::Mouse::getPosition(window));
    if(shape.getGlobalBounds().contains(mouse_position))
    {
        if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
            dragged = true;
        else
            dragged = false;
    }

    if(!dragged)
        move();
    else
        shape.setPosition(sf::Vector2f(mouse_position.x - shape.getRadius(), mouse_position.y - shape.getRadius()));
}


void Disk::move()
{
    const auto position = shape.getPosition();

    // Atractive force to the center
    double cx = window.getSize().x / 2;
    double cy = window.getSize().y / 2;

    double r = std::sqrt(std::pow(cx - position.x, 2) + std::pow(cy - position.y, 2));
    double force = 30 / (std::pow(r, 2) * mass);
    sf::Vector2f direction = sf::Vector2f((cx - position.x) / r, (cy - position.y) / r);

    velocity += sf::Vector2f(direction.x * force, direction.y * force);

    // Aerodynamic drag
    double drag_force = -6 * M_PI * 0.000003 * shape.getRadius();
    sf::Vector2f drag = sf::Vector2f(velocity.x * drag_force, velocity.y * drag_force);
    velocity += drag;

    // Bounce off the edges 
    if (position.x < 0 + shape.getRadius() || position.x >= window.getSize().x - shape.getRadius())
        velocity.x = -velocity.x;
    if (position.y < 0 + shape.getRadius() || position.y >= window.getSize().y - shape.getRadius())
        velocity.y = -velocity.y;

    shape.move(velocity);
}
