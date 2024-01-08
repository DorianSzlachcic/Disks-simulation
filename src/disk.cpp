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

    velocity = sf::Vector2f(random_number(-5, 5), random_number(-5, 5));
}

void Disk::draw()
{
    window.draw(shape);
}

void Disk::logic()
{
    shape.move(velocity);
}
