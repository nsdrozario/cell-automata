#include <cell_automata.hpp>
#include <graphics.hpp>

sf::RenderWindow w;
sf::Event e;
sol::state lua_state;
sf::Vector2f mousePosition;

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

using namespace cell_automata;

void draw_main() {

    // draw controls
    w.draw(ctrlPanelBody);
    w.draw(runningStatus);
    w.draw(iterationCount);

    // draw mouse selection

    

    // draw contents of util::data

    // draw grid lines
    if (graphics::GraphicsState::gridVisible) {

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

    graphics::init_style();
    graphics::resize_all();
    
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
                graphics::resize_all();
            }
        }

        w.clear(sf::Color::White);

        mousePosition = w.mapPixelToCoords(sf::Mouse::getPosition());

        // determine cursor hovering position
        if (graphics::ScreenData::gridArea.contains(mousePosition)) {

            unsigned int mouseX = static_cast<unsigned int>(mousePosition.x/static_cast<float>(graphics::ScreenData::pixelSize));
            unsigned int mouseY = static_cast<unsigned int>(mousePosition.y/static_cast<float>(graphics::ScreenData::pixelSize));
            graphics::GraphicsState::cursorPositionGridCoords = sf::Vector2u(mouseX, mouseY);

        }


        draw_main();

        w.display();

    }

    return 0;

}