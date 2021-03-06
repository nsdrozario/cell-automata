#include <graphics.hpp>
#include <string>
#include <cell_automata.hpp>

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
int graphics::ScreenData::pixelSize = 64; // default value
sf::FloatRect graphics::ScreenData::gridArea;

bool graphics::GraphicsState::gridVisible = true;
sf::Vector2u graphics::GraphicsState::cursorPositionGridCoords;
sf::RectangleShape graphics::GraphicsState::cursor;
std::vector<std::vector<sf::RectangleShape>> graphics::GraphicsState::squares;

template <class T>
T graphics::clamp(T x, T minimum, T maximum) {
    if (x >= minimum && x <= maximum) { // x within [minimum, maximum]
        return x;
    } else {
        return (x < minimum) ? minimum : maximum; // if it isn't within the closed interval and isn't less than minimum, it has to be greater than maximum
    }
}

void graphics::reset_grid() {

    int numLinesHorizontal = static_cast<int> (ScreenData::gridSize.x / ScreenData::pixelSize);
    int numLinesVertical = static_cast<int> (ScreenData::gridSize.y / ScreenData::pixelSize);

    horizontalGridLines.resize(numLinesHorizontal);
    verticalGridLines.resize(numLinesVertical);

    for (int i = 0; i < numLinesHorizontal; i++) {
        horizontalGridLines[i] = sf::VertexArray(sf::Lines, 2);
        if (horizontalGridLines[i].getVertexCount() != 2) {
            horizontalGridLines[i].resize(2);
        }
        float maxYCoord = ScreenData::gridSize.y;
        float currentXCoord = ScreenData::ctrlPanelSize.x + (i * ScreenData::pixelSize);
        horizontalGridLines[i][0] = sf::Vertex(
            sf::Vector2f(currentXCoord+0.5, 0.5),
            sf::Color::Black
        );
        horizontalGridLines[i][1] = sf::Vertex(
            sf::Vector2f(currentXCoord+0.5, maxYCoord+0.5),
            sf::Color::Black
        );

        util::data.resize(numLinesHorizontal);

        for (std::vector<cell> v : util::data) {
            v.resize(numLinesVertical);
        }

    }

    for (int i = 0; i < numLinesVertical; i++) {
        verticalGridLines[i] = sf::VertexArray(sf::Lines, 2);
        if (verticalGridLines[i].getVertexCount() != 2) {
            verticalGridLines[i].resize(2);
        }
        float maxXCoord = ScreenData::screenSize.x;
        float currentYCoord = i * ScreenData::pixelSize;
        verticalGridLines[i][0] = sf::Vertex(
            sf::Vector2f(ScreenData::ctrlPanelSize.x+0.5, currentYCoord+0.5),
            sf::Color::Black
        );
        verticalGridLines[i][1] = sf::Vertex(
            sf::Vector2f(maxXCoord+0.5, currentYCoord+0.5),
            sf::Color::Black
        );
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
    int panel_width = clamp<int>(ScreenData::screenSize.x/5, 50, 150);
    ScreenData::ctrlPanelSize = sf::Vector2f(static_cast<float>(panel_width), ScreenData::screenSize.y);
    ctrlPanelBody.setSize(ScreenData::ctrlPanelSize);
    ctrlPanelBody.setPosition(0,0);

    ScreenData::gridSize.x = ScreenData::screenSize.x - ScreenData::ctrlPanelSize.x;
    ScreenData::gridSize.y = ScreenData::screenSize.y;

    ScreenData::gridArea = sf::FloatRect(
        sf::Vector2f(
            ScreenData::ctrlPanelSize.x,
            0
        ),
        ScreenData::gridSize
    );

    resize_text(runningStatus, ctrlPanelBody.getLocalBounds());
    resize_text(iterationCount, ctrlPanelBody.getLocalBounds());

    reset_grid();

    return;
}