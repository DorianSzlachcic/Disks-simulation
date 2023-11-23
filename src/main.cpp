#include <SFML/Graphics.hpp>
#include <vector>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1600, 900), "Disks", sf::Style::Close);
    std::vector<sf::CircleShape> disks;

    srand(time(0));

    for(int i = 0; i < 1000; i++)
    {
        sf::CircleShape shape(rand() % 30 + 5);
        shape.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
        shape.setOutlineColor(sf::Color::Black);
        shape.setOutlineThickness(1);
        shape.setPosition(rand() % 1600, rand() % 900);
        disks.push_back(shape);
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        
        for(auto disk: disks)
            window.draw(disk);

        window.display();
    }

    return 0;
}