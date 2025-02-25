#ifndef GDEXAMPLE_H
#define GDEXAMPLE_H

#include <godot_cpp/classes/sprite2d.hpp>

namespace godot
{

    class GDExample : public Sprite2D
    {
        GDCLASS(GDExample, Sprite2D)

    protected:
        static void _bind_methods();

    public:
        GDExample();
        ~GDExample() override;

        void set_amplitude(double amplitude);
        [[nodiscard]] double get_amplitude() const;

        void set_speed(double speed);
        [[nodiscard]] double get_speed() const;

        void _process(double delta) override;

    private:
        double m_time_passed;
        double m_amplitude;
        double m_speed;

        double m_time_emit;

        void _announce_tree_enter() const;
    };

}

#endif