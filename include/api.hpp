#ifndef CELL_AUTOMATA_API_HPP
#define CELL_AUTOMATA_API_HPP

#include "cell_automata.hpp"

namespace cell_automata {

    enum class opcode {
        create_cell,
        destroy_cell
    };

    class operation {
        public:
            opcode code;
            std::pair<unsigned int, unsigned int> source;
            std::pair<unsigned int, unsigned int> destination;
            std::map<std::string, sol::object> cell_data;

            operation();
            operation(opcode o, std::pair<unsigned int, unsigned int> s, std::pair<unsigned int, unsigned int> d);
    };

    

}

#endif