#include <cell_automata.hpp>
#include <graphics.hpp>

sf::RenderWindow w;
sf::Event e;
sol::state lua_state;

void draw_main() {



}

int main () {

    w.create (
    sf::VideoMode ( // default 800x600 window
        800,
        600
    ),
    "Cellular Automata Simulation"
    );

    while (w.isOpen()) {
        while (w.pollEvent(e)) {
            if (e.type == sf::Event::Closed) {
                w.close();
            } else if (e.type == sf::Event::Resized) {
                w.setView(sf::View(
                    sf::FloatRect(
                        0, 0, e.size.width, e.size.height
                    )
                ));
                cell_automata::graphics::resize_grid();
            }
        }

        w.clear(sf::Color::White);

        draw_main();

        w.display();

    }

    return 0;

}