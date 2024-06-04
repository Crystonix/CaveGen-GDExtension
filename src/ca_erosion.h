#pragma once
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <vector>

namespace godot 
{
    class CAErosion : public Node 
    {
        GDCLASS(CAErosion, Node);
 
        private:
            using BoolRow = std::vector<bool>;
            using BoolGrid = std::vector<BoolRow>;
            BoolGrid grid;

        protected:
            static void _bind_methods();

        public:
            CAErosion();
            ~CAErosion();
            void initialize_grid(int width = 128, int height = 128, bool state = false);

            void erode(int iterations = 3);
            void generate_noise(float p = 0.5);

            void print_grid();
            int get_neighbour_count(int x,int y);
            bool get_cell_state(int x, int y);
            void set_cell_state(int x, int y, bool state);
            int get_GRID_WIDTH();
            int get_GRID_HEIGHT();
    };
}