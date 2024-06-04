#include "ca_erosion.h"
#include <godot_cpp/classes/time.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/classes/timer.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <vector>

using namespace godot;

void CAErosion::_bind_methods(){
    ClassDB::bind_method(D_METHOD("initialize_grid","width","height","state"), &CAErosion::initialize_grid);
    ClassDB::bind_method(D_METHOD("get_cell_state", "x", "y"), &CAErosion::get_cell_state);
    ClassDB::bind_method(D_METHOD("set_cell_state", "x", "y"), &CAErosion::set_cell_state);
    ClassDB::bind_method(D_METHOD("print_grid"), &CAErosion::print_grid);
    ClassDB::bind_method(D_METHOD("generate_noise","p"), &CAErosion::generate_noise);
    ClassDB::bind_method(D_METHOD("erode","iterations"), &CAErosion::erode);
    ClassDB::bind_method(D_METHOD("get_neighbour_count","x","y"), &CAErosion::get_neighbour_count);
    ClassDB::bind_method(D_METHOD("get_GRID_WIDTH"), &CAErosion::get_GRID_WIDTH);
    ClassDB::bind_method(D_METHOD("get_GRID_HEIGTH"), &CAErosion::get_GRID_HEIGHT);
    ClassDB::bind_method(D_METHOD("clear_grid"), &CAErosion::clear_grid);
    //ClassDB::add_property("test",PropertyInfo(Variant::FLOAT,"speed"), "set_width","get_speed");
    //ADD_SIGNAL(MethodInfo("test_signal", PropertyInfo(Variant::String, "data")));
}
CAErosion::CAErosion(){
    initialize_grid();
}

CAErosion::~CAErosion(){
    initialize_grid();
}

bool CAErosion::get_cell_state(int x, int y) {
    return grid[x][y];
}

void CAErosion::set_cell_state(int x, int y, bool state) {
    grid[x][y] = state;
}

void CAErosion::initialize_grid(int p_width, int p_height, bool state){
    grid.resize(p_width, std::vector<bool>(p_height, state));
}

void CAErosion::clear_grid()
{
    for (int x = 0; x < grid.size();++x)
    {
        for (int y = 0; y < grid[x].size(); ++y)
        {
            grid[x][y] = false;
        }   
    }
}

void CAErosion::print_grid() {
    for (const auto& row : grid)
    {
        for (auto cell : row)
        {
            UtilityFunctions::print(cell);
        }   
    }
}

void CAErosion::erode(int iterations)
{   
    if (iterations == 0) {
        UtilityFunctions::print("0 iterations"); 
        return;
    }

    BoolGrid new_grid(grid);

    for (int i = 0; i < iterations; ++i){   
        for (int x = 0; x < grid.size(); ++x) {
            for (int y = 0; y < grid[x].size(); ++y) {
                int neighbor_count = get_neighbour_count(x, y);
                new_grid[x][y] = (grid[x][y] ? neighbor_count > 4 : neighbor_count < 4);
            }
        }
        grid.swap(new_grid);
    }
}

int CAErosion::get_neighbour_count(int x,int y){
    int count = 0;
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if (i == 0 && j == 0) continue;

            int nx = x + i;
            int ny = y + j;

            if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[x].size())
            {
                if (get_cell_state(nx,ny) == true) count++;
            }
        }
    }
    return count;
}

void CAErosion::generate_noise(float p) {
    for (int y = 0; y < grid.size(); ++y) {
        for (int x = 0; x < grid[y].size(); ++x) {
            if (p < UtilityFunctions::randf()) {
                grid[y][x] = true;
            }
        }
    }
}


int CAErosion::get_GRID_WIDTH()
{
    return grid.size();
}

int CAErosion::get_GRID_HEIGHT()
{
    return grid[0].size();
}