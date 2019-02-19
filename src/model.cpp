// YOU DEFINITELY NEED TO MODIFY THIS FILE.

#include "model.h"

Model::Model(Geometry const& geometry)
        : geometry_(geometry)
        , paddle_(Block::from_top_left(geometry_.paddle_top_left0(),
                                       geometry_.paddle_dims_))
        , ball_(paddle_, geometry_)
{
    // TODO: your code here
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
}


