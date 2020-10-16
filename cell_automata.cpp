#include <cell_automata.hpp>
#include <graphics.hpp>

sf::RenderWindow w;
sf::Event e;
sol::state lua_state;


/*

[Elements to keep track of]

// graphics elements
extern sf::RectangleShape ctrlPanelBody;
extern sf::Text runningStatus;
extern sf::Text iterationCount; 
extern std::vector<sf::VertexArray> horizontalGridLines;
extern std::vector<sf::VertexArray> verticalGridLines;
extern sf::Font defaultFont;
*/

void draw_main() {

    // 

    runningStatus.setString("State: Paused [SPACE]");

    w.draw(ctrlPanelBody);
    w.draw(runningStatus);
    w.draw(iterationCount);

    // draw squares
    
    // draw grid lines
    if (cell_automata::graphics::GraphicsState::gridVisible) {
        for (sf::VertexArray v : horizontalGridLines) {
            w.draw(v);
        }
        for (sf::VertexArray v : verticalGridLines) {
            w.draw(v);
        }
    }

}

int main () {

    w.create (
    sf::VideoMode ( // default 800x600 window
        800,
        600
    ),
    "Cellular Automata Simulation"
    );

    cell_automata::graphics::init_style();
    cell_automata::graphics::resize_all();
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
                cell_automata::graphics::resize_all();
            }
        }

        w.clear(sf::Color::White);

        draw_main();

        w.display();

    }

    return 0;

}