#include "Quaternion.h"

float *Quaternion::to_rotation_matrix() const {
    auto *mat = new float[]{
            1 - 2 * (y * y) - 2 * (z * z), 2 * x * y - 2 * w * z, 2 * x * z + 2 * w * y, 0, // 1st column
            2 * x * y + 2 * w * z, 1 - 2 * (x * x) - 2 * (x * x), 2 * y * z - 2 * w * x, 0, // 2nd column
            2 * x * z - 2 * w * y, 2 * y * z + 2 * w * x, 1 - 2 * (x * x) - 2 * (y * y), 0,
            0, 0 /* Move model down */, 0 /* Move model back */, 1
    };

    return mat;
}
