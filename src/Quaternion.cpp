#include "Quaternion.h"

float *Quaternion::to_rotation_matrix() const {
    auto *mat = new float[]{
            1 - 2 * (y * y) - 2 * (z * z),  2 * x * y - 2 * w * z,           2 * x * z + 2 * w * y,         0, // 1st column
            2 * x * y + 2 * w * z,          1 - 2 * (x * x) - 2 * (z * z),   2 * y * z - 2 * w * x,         0, // 2nd column
            2 * x * z - 2 * w * y,          2 * y * z + 2 * w * x,           1 - 2 * (x * x) - 2 * (y * y), 0,

            0,
            0, // Move model down
            -75, // Move model back
            1
    };

    /*auto *mat = new float[]{
            2 * (w * w + x * x) - 1, 2 * (x * y - w * z), 2 * (x * z + w * y), 0,
            2 * (x * y + w * z), 2 * (w * w + y * y), 2 * (y * z - w * x), 0,
            2 * (x * z - w * y), 2 * (y * z + w * x), 2 * (w * w + z * z) - 1, 0,

            0,
            0, // Move model down
            -75, // Move model back
            1
    };*/

    return mat;
}

Quaternion Quaternion::to_quaternion(float yaw, float pitch, float roll) {
    // Abbreviations for the various angular functions
    float cy = cosf(yaw * 0.5f);
    float sy = sinf(yaw * 0.5f);
    float cp = cosf(pitch * 0.5f);
    float sp = sinf(pitch * 0.5f);
    float cr = cosf(roll * 0.5f);
    float sr = sinf(roll * 0.5f);

    Quaternion q;
    q.w = cr * cp * cy + sr * sp * sy;
    q.x = sr * cp * cy - cr * sp * sy;
    q.y = cr * sp * cy + sr * cp * sy;
    q.z = cr * cp * sy - sr * sp * cy;

    return q;
}