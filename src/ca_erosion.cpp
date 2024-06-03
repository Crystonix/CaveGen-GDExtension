#include "ca_erosion.h"
#include <godot_cpp/classes/time.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/classes/timer.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <vector>

using namespace godot;

void CAErosion::_bind_methods(){
    ClassDB::bind_method(D_METHOD("initialize_grid"), &CAErosion::initialize_grid);
    ClassDB::bind_method(D_METHOD("get_cell_state", "x", "y"), &CAErosion::get_cell_state);
    ClassDB::bind_method(D_METHOD("set_cell_state", "x", "y"), &CAErosion::set_cell_state);
    ClassDB::bind_method(D_METHOD("print_grid"), &CAErosion::print_grid);
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
    if (x >= 0 && x < GRID_WIDTH && y >= 0 && y < GRID_HEIGHT) {
        return grid[x][y];
    } else {
        return false;
    }
}

void CAErosion::set_cell_state(int x, int y, bool state) {
    if (x >= 0 && x < GRID_WIDTH && y >= 0 && y < GRID_HEIGHT) {
        grid[x][y] = state;
    }
}

void CAErosion::initialize_grid(){
    for (int x = 0; x < GRID_WIDTH; ++x) {
        for (int y = 0; y < GRID_HEIGHT; ++y) {
            grid[x][y] = false;
        }
    }
}

void CAErosion::print_grid() {
    for (int y = 0; y < GRID_HEIGHT; ++y) {
        String row = "";
        for (int x = 0; x < GRID_WIDTH; ++x) {
            row += (grid[x][y] ? String("1") : String("0")) + " ";
        }
        UtilityFunctions::print(row);
    }
}


