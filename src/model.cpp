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
    for(int rowIndex = 0; rowIndex < geometry_.brick_rows; rowIndex++) {
        for(int colIndex = 0; colIndex < geometry_.brick_rows; colIndex++) {
            ge211::Rectangle rec;
            rec.dimensions() = geometry_.brick_dims();
            rec.x = rowIndex * (rec.width + geometry_.brick_spacing.width) + geometry_.side_margin;
            rec.y = colIndex * (rec.height + geometry_.brick_spacing.height) + geometry_.top_margin;

            bricks.push_back(rec);
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

}

void Model::update(int boost)
{
    // TODO: your code here
    paddle_.x += boost;
    if(!ball_.live_) {
        ball_ = Ball(paddle_, geometry_);
    }
}


