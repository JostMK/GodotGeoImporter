#include "gdexample.h"
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void GDExample::_bind_methods()
{
    ADD_SIGNAL(MethodInfo("position_changed", PropertyInfo(Variant::OBJECT, "node"),
                          PropertyInfo(Variant::VECTOR2, "new_pos")));

    ClassDB::bind_method(D_METHOD("get_amplitude"), &GDExample::get_amplitude);
    ClassDB::bind_method(D_METHOD("set_amplitude", "amplitude"), &GDExample::set_amplitude);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "amplitude"), "set_amplitude", "get_amplitude");

    ClassDB::bind_method(D_METHOD("get_speed"), &GDExample::get_speed);
    ClassDB::bind_method(D_METHOD("set_speed", "speed"), &GDExample::set_speed);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "speed", PROPERTY_HINT_RANGE, "0,20,0.01"),
                 "set_speed", "get_speed");

    ClassDB::bind_method(D_METHOD("_announce_tree_enter"), &GDExample::_announce_tree_enter);
}

GDExample::GDExample() : m_time_passed(0.0), m_amplitude(10.0), m_speed(1.0), m_time_emit(0.0)
{
    this->connect("tree_entered", Callable(this, "_announce_tree_enter"));
}

GDExample::~GDExample()
{
    this->disconnect("tree_entered", Callable(this, "_announce_tree_enter"));
}

void GDExample::set_amplitude(const double amplitude)
{
    m_amplitude = amplitude;
}

double GDExample::get_amplitude() const
{
    return m_amplitude;
}

void GDExample::set_speed(const double speed)
{
    m_speed = speed;
}

double GDExample::get_speed() const
{
    return m_speed;
}

void GDExample::_process(const double delta)
{
    m_time_passed += delta * m_speed;

    const auto new_position =
        Vector2(static_cast<float>(m_amplitude + m_amplitude * sin(m_time_passed * 2.0)),
                static_cast<float>(m_amplitude + m_amplitude * cos(m_time_passed * 1.5)));

    set_position(new_position);

    m_time_emit += delta;
    if (m_time_emit > 1.0)
    {
        emit_signal("position_changed", this, new_position);

        m_time_emit = 0.0;
    }
}

void GDExample::_announce_tree_enter() const
{
    UtilityFunctions::print_rich("Hello from GDExtension! [", this->get_name(), "]");
}