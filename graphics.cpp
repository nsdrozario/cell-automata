#include <graphics.hpp>
using namespace cell_automata;

sf::RectangleShape ctrlPanelBody;
sf::Text runningStatus;
sf::Text iterationCount; 
std::vector<sf::VertexArray> horizontalGridLines;
std::vector<sf::VertexArray> verticalGridLines;
sf::Font defaultFont;

sf::Vector2u graphics::ScreenData::screenSize;
sf::Vector2f graphics::ScreenData::ctrlPanelSize;
sf::Vector2f graphics::ScreenData::gridSize;

template <class T>
T graphics::clamp(T x, T minimum, T maximum) {
    if (x >= minimum && x <= maximum) { // x within [minimum, maximum]
        return x;
    } else {
        return (x < minimum) ? minimum : maximum; // if it isn't within the closed interval and isn't less than minimum, it has to be greater than maximum
    }
}

void graphics::reset_grid() {



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

}

void graphics::resize_all() {

    using graphics::ScreenData;
    
    ScreenData::screenSize = w.getSize();
    int panel_width = clamp<int>(ScreenData::screenSize.x/5, 50, 400);
    ScreenData::ctrlPanelSize = sf::Vector2f(static_cast<float>(panel_width), ScreenData::screenSize.y);
    ctrlPanelBody.setSize(ScreenData::ctrlPanelSize);

    reset_grid();

    return;
}