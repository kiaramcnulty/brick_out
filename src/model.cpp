// YOU DEFINITELY NEED TO MODIFY THIS FILE.

#include "model.h"

Model::Model(Geometry const& geometry)
        : geometry_(geometry)
        , paddle_(Block::from_top_left(geometry_.paddle_top_left0(),
                                       geometry_.paddle_dims_))
        , ball_(paddle_, geometry_)
{
    // TODO: your code here

    int rows = geometry_.brick_rows;
    int cols = geometry_.brick_cols;
    std::vector<ge211::Rectangle> bricks;
    for(int rowIndex = 0; rowIndex < rows; rowIndex++) {
        for(int colIndex = 0; colIndex < cols; colIndex++) {
            ge211::Rectangle rec;
            rec.dimensions() = geometry_.brick_dims();
            rec.x = rowIndex * (geometry_.brick_dims().width + geometry_.brick_spacing.width) + geometry_.side_margin;
            rec.y = colIndex * (geometry_.brick_dims().height + geometry_.brick_spacing.height) + geometry_.top_margin;

            bricks_.push_back(rec);
        }
    }
}

// Freebie.
void Model::launch()
{
    ball_.live_ = true;
}

void Model::paddle_to(int x)
{
    // TODO: your code here
    paddle_.x = x - paddle_.width/2;
    if(!ball_.live_)
        ball_ = Ball(paddle_, geometry_);
}

void Model::update(int boost)
{
    // TODO: your code here
    if (ball_.live_)
    {
        if (ball_.hits_bottom(geometry_))
            ball_.live_ = false;
        else
        {
            Ball next = ball_.next();
            if ((next.hits_side(geometry_) && next.hits_top(geometry_)) || next.destroy_brick(bricks_)) {
                next.velocity_.height *= -1;
                next.velocity_.width *= -1;
            }
            else if (next.hits_top(geometry_))
                next.velocity_.height *= -1;
            else if (next.hits_side(geometry_))
                next.velocity_.width *= -1;
            else if (next.hits_block(paddle_)) {
                next.velocity_.height *= -1;
                next.velocity_.width += boost;
            }

            ball_ = next;
        }

    }

}


