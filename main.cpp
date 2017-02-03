// Example template
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Example");

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the windows events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();

            else if (event.type == sf::Event::KeyReleased) {
                // close if escape key was pressed
                if (event.key.code == sf::Keyboard::Escape) {
                    window.close();
                }
            }
        }

        // clear the window to black
        window.clear();

        //window.draw();

        // display the windows content
        window.display();
    }
    return 0;
}
