#ifndef CELL_AUTOMATA_DEBUG_HPP
#define CELL_AUTOMATA_DEBUG_HPP

#include <fstream>
#include <iostream>

namespace cell_automata {
    namespace debug {
        class io {
            static std::ofstream error_log;
            static std::ofstream output;
        };
    }
}    

#endif