#ifndef CELLAUTOMATA_GRAPHICS_HPP
#define CELLAUTOMATA_GRAPHICS_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include "cell_automata.hpp"

extern sf::RenderWindow w;
extern sf::Event e;

// graphics elements
extern sf::RectangleShape ctrlPanelBody;
extern sf::Text runningStatus;
extern sf::Text iterationCount; 
extern std::vector<sf::VertexArray> horizontalGridLines;
extern std::vector<sf::VertexArray> verticalGridLines;

namespace cell_automata {
    namespace graphics {
        void resize_grid();
    }
}

#endif