#include <graphics.hpp>

using namespace cell_automata;

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

void graphics::init_style() {

    // ctrlPanelBody
    ctrlPanelBody.setFillColor(sf::Color::White);
    ctrlPanelBody.setOutlineColor(sf::Color::Black);
    ctrlPanelBody.setOutlineThickness(2.0f);

    // vertex arrays
    for (sf::VertexArray v : horizontalGridLines) {
        for (int it = 0; it < v.getVertexCount(); it++) {
            sf::Vertex v_0 = v[it];
            v_0.color = sf::Color(sf::Color::Black);
        }
    }
    for (sf::VertexArray v : verticalGridLines) {
        for (int it = 0; it < v.getVertexCount(); it++) {
            sf::Vertex v_0 = v[it];
            v_0.color = sf::Color(sf::Color::Black);
        }
    }

    if (!defaultFont.loadFromFile(DEFAULT_FONT_PATH)) {
        
    }

}