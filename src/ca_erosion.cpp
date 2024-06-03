#include "ca_erosion.h"
#include <godot_cpp/classes/time.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/classes/timer.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <vector>

using namespace godot;

void CAErosion::_bind_methods(){
    ClassDB::bind_method(D_METHOD("_init"), &CAErosion::_init);
    ClassDB::bind_method(D_METHOD("initialize_grid"), &CAErosion::initialize_grid);
    ClassDB::bind_method(D_METHOD("get_cell_state", "x", "y"), &CAErosion::get_cell_state);
    ClassDB::bind_method(D_METHOD("set_cell_state", "x", "y"), &CAErosion::set_cell_state);
}
CAErosion::CAErosion(){
    
}

CAErosion::~CAErosion(){

}

void CAErosion::_init() {
    initialize_grid();
}

bool CAErosion::get_cell_state(int x, int y) {
    // Check bounds
    if (x >= 0 && x < GRID_WIDTH && y >= 0 && y < GRID_HEIGHT) {
        return grid[x][y];
    } else {
        // Return false for cells outside the grid
        return false;
    }
}

void CAErosion::set_cell_state(int x, int y, bool state) {
    // Check bounds
    if (x >= 0 && x < GRID_WIDTH && y >= 0 && y < GRID_HEIGHT) {
        grid[x][y] = state;
    }
}

void CAErosion::initialize_grid(){
    for (int x = 0; x < GRID_WIDTH; ++x) {
        for (int y = 0; y < GRID_HEIGHT; ++y) {
        grid[x][y] = false; // or true for initialization
        }
    }
}