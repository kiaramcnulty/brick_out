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
    paddle_.x += x;
    if(!ball_.live_) {
        ball_ = Ball(paddle_, geometry_);
    }

}

// Updates the state of the game for one frame (usually 1/60 s).
//
// If the ball is dead then nothing happens. Otherwise there are
// several possible cases, depending on the speculative next
// position of the ball according to `Ball::next() const`. In
// particular:
//
//  1. If the next position of the ball is off the bottom of the
//     screen (according to Ball::hits_bottom(Geometry const&)),
//     resets the ball to dead and returns.
//
//  2. If the next position of the ball would be off the top of
//     the screen, reflects the velocity of the ball vertically.
//
//  3. If the next position of the ball would be off one side of
//     the screen, reflects the velocity of the ball horizontally.
//
// (Note that cases 2 and 3 can both happen at the same time!)
//
//  4. If the next position of the ball destroys a brick (using
//     Ball::destroy_bricks(std::vector<Block>&)) then it reflects
//     the velocity of the ball both horizontally and vertically [1].
//
//  5. If the next position of the ball hits the block then it
//     reflects vertical component of the ball's velocity and
//     adds `boost` to the horizontal component [2].
//
// In all cases where the ball is still live (2–5), we then update
// the ball to its next position for real.
//
// [1] Yes, this is weird physics.
//
// [2] This causes the effect where the velocity of the ball varies
//     after each bounce off the paddle. While this adjustment is
//     random, we require the UI component to perform the actual
//     random number generation and pass the result to the model.
//     This makes the model deterministic and thus easier to test.
//

void Model::update(int boost)
{
    // TODO: your code here
    if (ball_.live_)
    {
        if (ball_.hits_bottom(geometry_)) {
            ball_.live_ = false;
        }
        else
        {
            Ball next = ball_.next();
            if (next.hits_side(geometry_) && next.hits_top(geometry_))
            {
                next.velocity_.height *= -1;
                next.velocity_.width *= -1;
            }
            else if (next.hits_top(geometry_))
            {
                next.velocity_.height *= -1;
            }
            else if (next.hits_side(geometry_))
            {
                next.velocity_.width *= -1;
            }




            //UPDATE BALL TO NEXT AT END OF THIS
        }

    }

}


