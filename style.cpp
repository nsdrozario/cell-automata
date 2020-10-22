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
    ctrlPanelBody.setFillColor(sf::Color(217, 219, 219));
    ctrlPanelBody.setOutlineColor(sf::Color::Black);
    ctrlPanelBody.setOutlineThickness(2.0f);

    // text

    runningStatus.setString("State: Paused [SPACE]");
    
    // cursor

    GraphicsState::cursor.setFillColor(sf::Color(150,255,255));
    GraphicsState::cursor.setSize(sf::Vector2f(static_cast<float>(ScreenData::pixelSize), static_cast<float>(ScreenData::pixelSize)));

    // vertex arrays
    for (sf::VertexArray v : horizontalGridLines) {
        v.setPrimitiveType(sf::Lines);
        for (size_t it = 0; it < v.getVertexCount(); it++) {
            sf::Vertex v_0 = v[it];
            v_0.color = sf::Color(sf::Color::Black);
        }
    }
    for (sf::VertexArray v : verticalGridLines) {
        v.setPrimitiveType(sf::Lines);
        for (size_t it = 0; it < v.getVertexCount(); it++) {
            sf::Vertex v_0 = v[it];
            v_0.color = sf::Color(sf::Color::Black);
        }
    }

    defaultFont.loadFromFile(DEFAULT_FONT_PATH);

    // text
    runningStatus.setFont(defaultFont);
    runningStatus.setFillColor(sf::Color::Red);

    iterationCount.setFont(defaultFont);
    iterationCount.setFillColor(sf::Color::Black);

}