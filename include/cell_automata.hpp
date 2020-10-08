#ifndef CELL_AUTOMATA_HPP
#define CELL_AUTOMATA_HPP

#define CELL_AUTOMATA_CONFIG_PATH "config.lua"

#include <sol/sol.hpp>
#include <map>
#include <vector>
#include <string>


namespace cell_automata {
    
    struct cell {
        std::map<std::string, sol::object> data;
    };

    struct util {
        static std::vector<std::vector<cell>> data;
        static sol::protected_function callback;

        static int pixel_size;

        static cell *access_cell(int x, int y); // will return nullptr if coordinates are invalid (nil in Lua)
        static void load_configs();
    };
}

#endif