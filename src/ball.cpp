// YOU DEFINITELY NEED TO MODIFY THIS FILE.

#include "ball.h"
#include "geometry.h"

static ge211::Position above_block(Block const& block,
                                   Geometry const& geometry)
{
    // TODO: your code here
    ge211::Position posn = block.top_left();
    posn.right_by(block.width/2);
    posn.up_by(1 + geometry.ball_radius);
    return posn;
}

// It won't compile without this, so you get it for free.
Ball::Ball(Block const& paddle, Geometry const& geometry)
        : radius_   (geometry.ball_radius)
        , velocity_ (geometry.ball_velocity0)
        , center_   (above_block(paddle, geometry))
        , live_     (false)
{ }

ge211::Position Ball::top_left() const
{
    // TODO: your code here
    return {center_.x - radius_, center_.y - radius_};

}

bool Ball::hits_bottom(Geometry const& geometry) const
{
    // TODO: your code here
    int y_posn = center_.y + radius_;
    return (y_posn > geometry.scene_dims.height);


}

bool Ball::hits_top(Geometry const&) const
{
    // TODO: your code here
    int y_posn = center_.y + radius_;
    return (y_posn < 0);
}

bool Ball::hits_side(Geometry const& geometry) const
{
    // TODO: your code here
    int x_left = center_.x - radius_;
    int x_right = center_.x + radius_;
    return (x_left < 0 || x_right > geometry.scene_dims.width);
}

Ball Ball::next() const
{
    // TODO: your code here
    Ball next_ball(*this);
    next_ball.center_.x += next_ball.velocity_.width;
    next_ball.center_.y += next_ball.velocity_.height;
    return next_ball;
}

bool Ball::hits_block(Block const& block) const
{
    // TODO: your code here
    int ball_right = center_.x + radius_;
    int ball_left = center_.x - radius_;
    int block_left = block.x;
    int block_right = block.x + block.width;
    int ball_bottom = center_.y + radius_;
    int ball_top = center_.y - radius_;
    int block_top = block.y;
    int block_bottom = block.y + block.height;

    return !(ball_right < block_left || block_right < ball_left || ball_bottom < block_top || block_bottom < ball_top);
    // need to add more checks
}

void Ball::reflect_vertical()
{
    velocity_.height *= -1;
}

void Ball::reflect_horizontal()
{
    velocity_.width *= -1;
}

bool Ball::destroy_brick(std::vector<Block>& bricks) const
{
    // TODO: your code here
    for (Block brick : bricks) {
        if(hits_block(brick)) {
            std::swap(brick, bricks.back());
            bricks.pop_back();
            return true;
        }
    }
}

bool operator==(Ball const& b1, Ball const& b2)
{
    // TODO: your code here
    return b1.radius_ == b2.radius_ && b1.velocity_ == b2.velocity_ && b1.center_ == b2.center_ && b1.live_ == b2.live_;
}

bool operator!=(Ball const& b1, Ball const& b2) {
    return !(b1 == b2);
}

// CHANGE TO THE CODE
