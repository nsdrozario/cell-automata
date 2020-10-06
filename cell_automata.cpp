#include <cell_automata.hpp>
#include <graphics.hpp>

sf::Event e;
sf::RenderWindow w;
sol::state lua_state;

int main () {

    w.create (
        sf::VideoMode ( // default 800x600 window
            800,
            600
        ),
        "Cellular Automata Simulation",
        sf::Style::Default
    );

    while (w.pollEvent(e)) {
        if (e.type == sf::Event::Closed) {
            
        } else if (e.type == sf::Event::Resized) {
            w.setView(sf::View(
                sf::FloatRect(
                    0, 0, e.size.width, e.size.height
                )
            ));
            cell_automata::graphics::resize_grid();
        }
    }

    return 0;

}