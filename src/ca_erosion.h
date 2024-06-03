#pragma once
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/core/class_db.hpp>

namespace godot {
    class CAErosion : public Node {
        GDCLASS(CAErosion, Node);
 
        private:
            static const int GRID_WIDTH = 100;
            static const int GRID_HEIGHT = 100;
            bool grid[GRID_WIDTH][GRID_HEIGHT];
        protected:
            static void _bind_methods();
        public:
            CAErosion();
            ~CAErosion();

            void _init();

            void initialize_grid();

            bool get_cell_state(int x, int y);
            void set_cell_state(int x, int y, bool state);
    };
}