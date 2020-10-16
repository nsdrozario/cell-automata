#include <graphics.hpp>
#include <iostream>
#include <string>

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
unsigned int graphics::ScreenData::pixelSize = 16; // default value

bool graphics::GraphicsState::gridVisible;


template <class T>
T graphics::clamp(T x, T minimum, T maximum) {
    if (x >= minimum && x <= maximum) { // x within [minimum, maximum]
        return x;
    } else {
        return (x < minimum) ? minimum : maximum; // if it isn't within the closed interval and isn't less than minimum, it has to be greater than maximum
    }
}

void graphics::create_grid() {

    for (sf::VertexArray v : horizontalGridLines) {
        v.setPrimitiveType(sf::Lines);
        v.resize(2);
        v[0].color = sf::Color::Black;
        v[1].color = sf::Color::Black;
    }
    for (sf::VertexArray v : verticalGridLines) {
        v.setPrimitiveType(sf::Lines);
        v.resize(2);
        v[0].color = sf::Color::Black;
        v[1].color = sf::Color::Black;
    }

}

void graphics::reset_grid() {

    unsigned int numLinesHorizontal = static_cast<unsigned int> (ScreenData::gridSize.x / ScreenData::pixelSize);
    unsigned int numLinesVertical = static_cast<unsigned int> (ScreenData::gridSize.y / ScreenData::pixelSize);

    horizontalGridLines.resize(numLinesHorizontal);
    verticalGridLines.resize(numLinesVertical);

    for (size_t i = 0; i < horizontalGridLines.size(); i++) {
        sf::VertexArray currentLine = horizontalGridLines[i];
        float maxYCoord = ScreenData::gridSize.y;
        float currentXCoord;
        currentLine[0] = sf::Vector2f();
    }

    for (size_t i = 0; i < verticalGridLines.size(); i++) {

    }

}

void graphics::resize_text(sf::Text &t, const sf::FloatRect &bounds) {
    /* 
        Set character size and scale accordingly to desired bounding box
    */
    std::string text = t.getString();
    t.setCharacterSize(ScreenData::ctrlPanelSize.x / (text.length()/3));
    sf::FloatRect textBounds = t.getLocalBounds();

    if (textBounds.width > bounds.width) {
        float ratio = bounds.width / textBounds.width;
        t.setScale(ratio, 1);
        t.setCharacterSize(t.getCharacterSize()-1);
    }

    if (textBounds.height > bounds.height) {
        float ratio = bounds.height / textBounds.height;
        t.setScale(1, ratio);
        t.setCharacterSize(t.getCharacterSize()-1);
    }

}

void graphics::resize_all() {

    using graphics::ScreenData;

    ScreenData::screenSize = w.getSize();
    int panel_width = clamp<int>(ScreenData::screenSize.x/5, 50, 200);
    ScreenData::ctrlPanelSize = sf::Vector2f(static_cast<float>(panel_width), ScreenData::screenSize.y);
    ctrlPanelBody.setSize(ScreenData::ctrlPanelSize);
    ctrlPanelBody.setPosition(0,0);

    resize_text(runningStatus, ctrlPanelBody.getLocalBounds());
    resize_text(iterationCount, ctrlPanelBody.getLocalBounds());

    // std::cout << "Panel size: " << ScreenData::screenSize.x << " " << ScreenData::screenSize.y << "\n";

    reset_grid();

    return;
}