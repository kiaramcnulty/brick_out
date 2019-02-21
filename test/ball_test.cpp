#include "ball.h"
#include "model.h"
#include <catch.h>

Block const paddle{100, 400, 100, 20};

TEST_CASE("Ball::Ball")
{
    Geometry geometry;
    Ball ball(paddle, geometry);

    CHECK( ball.center_.x == 150 );
    CHECK( ball.center_.y == 394 );
}

TEST_CASE("Ball::hits_side")
{
    Geometry geometry;
    Ball ball(paddle, geometry);

    CHECK_FALSE( ball.hits_side(geometry) );
    ball.center_.x = 1;
    CHECK( ball.hits_side(geometry) );
    ball.center_.x = geometry.scene_dims.width - 1;
    CHECK( ball.hits_side(geometry) );
    ball.center_.x = geometry.scene_dims.width / 2;
    CHECK_FALSE( ball.hits_side(geometry) );
}

TEST_CASE("Hit Block Contact Check") {
    Geometry geometry;
    Ball ball(paddle, geometry);
    Block block1({0, 0, 6, 6});
    Block block2({0, 14, 6, 6});
    Block block3({14, 0, 6, 6});
    Block block4({14, 14, 6, 6});

    Block block5({16, 16, 6, 6});

    Block block6({0, 9, 6, 1});
    Block block7({9, 0, 1, 6});
    Block block8({14, 9, 6, 1});
    Block block9({9, 14, 1, 6});

    ball.center_.x = 10;
    ball.center_.y = 10;

    CHECK(ball.hits_block(block1));
    CHECK(ball.hits_block(block2));
    CHECK(ball.hits_block(block3));
    CHECK(ball.hits_block(block4));

    CHECK_FALSE(ball.hits_block(block5));

    CHECK(ball.hits_block(block6));
    CHECK(ball.hits_block(block7));
    CHECK(ball.hits_block(block8));
    CHECK(ball.hits_block(block9));
}

TEST_CASE("Rec Dim Test") {
}

