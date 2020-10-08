#include <graphics.hpp>
using namespace cell_automata;

sf::RectangleShape ctrlPanelBody;
sf::Text runningStatus;
sf::Text iterationCount; 
std::vector<sf::VertexArray> horizontalGridLines;
std::vector<sf::VertexArray> verticalGridLines;

template <class T>
T graphics::clamp(T x, T minimum, T maximum) {
    if (x >= minimum && x <= maximum) { // x within [minimum, maximum]
        return x;
    } else {
        return (x < minimum) ? minimum : maximum; // if it isn't within the closed interval and isn't less than minimum, it has to be greater than maximum
    }
}

void graphics::resize_all() {

    sf::Vector2u screen_size = w.getSize();
    int panel_width = clamp<int>(screen_size.x/5, 50, 400);
    ctrlPanelBody.setSize(sf::Vector2f(static_cast<float>(panel_width), screen_size.y));


    return;
}