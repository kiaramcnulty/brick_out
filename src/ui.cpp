// YOU DEFINITELY NEED TO MODIFY THIS FILE.

#include "ui.h"

///
/// VIEW CONSTANTS
///

// Colors are red-green-blue(-alpha), each component
// from 0 to 255.
ge211::Color const ball_color    {255, 127, 127};
ge211::Color const paddle_color  {255, 255, 127};
ge211::Color const brick_color   {100, 100, 100};

///
/// VIEW FUNCTIONS
///

// Data members that are references cannot be initialized by assignment
// in the constructor body and must be initialized in a member
// initializer list.
Ui::Ui(Model& model)
        : model_(model)
{ }

ge211::Dimensions Ui::initial_window_dimensions() const
{
    return model_.geometry_.scene_dims;
}

void Ui::draw(ge211::Sprite_set& sprites)
{
    // TODO: your code here
    sprites.add_sprite(ball_sprite_, model_.ball_.top_left());
    sprites.add_sprite(paddle_sprite_, {model_.paddle_.x, model_.paddle_.y});
    for(size_t brick_index = 0; brick_index < model_.bricks_.size(); brick_index++) {
        sprites.add_sprite(brick_sprite_, model_.bricks_[brick_index].top_left());
    }
}

///
/// CONTROLLER FUNCTIONS
///

void Ui::on_key(ge211::Key key)
{
    if (key == ge211::Key::code('q'))
        quit();

    // TODO: your code here
    if(key == ge211::Key::code(' ')) {
        model_.launch();
    }
}

void Ui::on_frame(double)
{
    // TODO: your code here
    model_.update(ge211::Abstract_game::get_random().between(-model_.geometry_.max_boost, model_.geometry_.max_boost));
}

void Ui::on_mouse_up(ge211::Mouse_button, ge211::Position)
{
    // TODO: your code here

    // This does not feel like all I have to do ...
    model_.launch();
}

void Ui::on_mouse_move(ge211::Position position)
{
    // TODO: your code here
    model_.paddle_to(position.x);
}

