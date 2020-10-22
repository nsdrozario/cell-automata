#ifndef CELLAUTOMATA_GRAPHICS_HPP
#define CELLAUTOMATA_GRAPHICS_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include "cell_automata.hpp"

#define DEFAULT_FONT_PATH "font/Montserrat-Light.ttf"

extern sf::RenderWindow w;
extern sf::Event e;

// graphics elements
extern sf::RectangleShape ctrlPanelBody;
extern sf::Text runningStatus;
extern sf::Text iterationCount; 
extern std::vector<sf::VertexArray> horizontalGridLines;
extern std::vector<sf::VertexArray> verticalGridLines;
extern sf::Font defaultFont;

namespace cell_automata {
    namespace graphics {

        struct ScreenData {
                static sf::Vector2u screenSize;
                static sf::Vector2f ctrlPanelSize;
                static sf::Vector2f gridSize;
                static sf::FloatRect gridArea;
                static int pixelSize;
        };

        struct GraphicsState {
            static bool gridVisible;
            static sf::Vector2u cursorPositionGridCoords;
            static sf::RectangleShape cursor;
            static std::vector<std::vector<sf::RectangleShape>> squares;
        };

        void resize_all();
        void resize_text(sf::Text &t, const sf::FloatRect &bounds);
        void init_style();
        void reset_grid();
        template <class T> 
        T clamp(T x, T minimum, T maximum);

    }
}

#endif