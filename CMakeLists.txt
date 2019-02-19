cmake_minimum_required(VERSION 3.3)
project(brick_out CXX)
include(.eecs211/cmake/CMakeLists.txt)

# Defines a variable to stand for the two .cpp files that implement
# the model.
set(MODEL_COMMON
        src/geometry.cpp
        src/ball.cpp
        src/model.cpp)

# Adds a program named `brick_out` built from src/brick_out.cpp and
# the common model files.
add_program(brick_out
        src/brick_out.cpp
        src/ui.cpp
        ${MODEL_COMMON})
target_link_libraries(brick_out ge211)

# Adds a test program named `ball_test` built from test/ball_test.cpp
# and the common model files.
add_test_program(ball_test
        test/ball_test.cpp
        ${MODEL_COMMON})
target_link_libraries(ball_test ge211)

# Adds a test program named `model_test` built from test/model_test.cpp
# and the common model files.
add_test_program(model_test
        test/model_test.cpp
        ${MODEL_COMMON})
target_link_libraries(model_test ge211)
