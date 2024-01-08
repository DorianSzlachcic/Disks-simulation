#include <SFML/Graphics.hpp>
#include <vector>
#include "disk.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1600, 900), "Disks", sf::Style::Close);
    std::vector<Disk*> disks;

    srand(time(0));

    for(int i = 0; i < 1000; i++)
    {
        Disk* disk = new Disk(window);
        disks.push_back(disk);
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);
        
        for(auto disk: disks)
        {
            disk->logic();
            disk->draw();
        }

        window.display();
    }

    for(auto disk: disks)
        delete disk;

    return 0;
}