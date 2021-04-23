#ifndef TRANSFORM_MATRIX_H
#define TRANSFORM_MATRIX_H

#include "rotate_matrix.hpp"
#include "../inc/dot.hpp"
#include "../inc/logs.hpp"

int make_transform_matrix(matrix_t &matrix, transform_settings_t settings, const dot_t &center);

#endif