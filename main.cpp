// Example template
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Example", sf::Style::Resize);

    bool isHidden = true;
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
                else if (event.key.code == sf::Keyboard::M) {
                    window.setState(sf::State::Minimized);
                    sf::sleep(sf::seconds(3));
                    std::cout << window.getState() << std::endl;
                    window.setState(sf::State::Maximized);
                }
                else if (event.key.code == sf::Keyboard::N) {
                    window.setState(sf::State::Maximized);
                }
                else if (event.key.code == sf::Keyboard::W) {
                    window.setState(sf::State::Windowed);
                }
                else if (event.key.code == sf::Keyboard::F) {
                    window.setState(sf::State::Fullscreen);
                }
                else if (event.key.code == sf::Keyboard::H) {
                    isHidden = !isHidden;
                    window.setVisible(isHidden);
                }
                else if (event.key.code == sf::Keyboard::G) {
                    std::cout << window.getState() << std::endl;
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
