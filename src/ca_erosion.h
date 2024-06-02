#pragma once
#include <godot_cpp/classes/node2d.hpp>

namespace godot {
    class CAErosion : public Node2D {
        GDCLASS(CAErosion, Node2D);

        private:
            double time_passed;
        
        protected:
            static void _bind_methods();
        
        public:
            CAErosion();
            ~CAErosion();

            void _process(double delta) override;
    };
}