#include "Quaternion.h"

float *Quaternion::to_rotation_matrix() const {
    // Source: http://www.songho.ca/opengl/gl_quaternion.html
    float *mat = new float[]{
            1 - 2 * (y * y) - 2 * (z * z), 2 * x * y - 2 * w * z, 2 * x * z + 2 * w * y, 0, // 1st column
            2 * x * y + 2 * w * z, 1 - 2 * (x * x) - 2 * (z * z), 2 * y * z - 2 * w * x, 0, // 2nd column
            2 * x * z - 2 * w * y, 2 * y * z + 2 * w * x, 1 - 2 * (x * x) - 2 * (y * y), 0,

            0,
            -15, // Move model down
            -75, // Move model back
            1
    };

    // Source: https://en.wikipedia.org/wiki/Conversion_between_quaternions_and_Euler_angles
    /*float q0 = this->w;
    float q1 = this->x;
    float q2 = this->y;
    float q3 = this->z;
    float *mat = new float[]{
        1 - 2 * ((q2*q2) + (q3*q3)), 2 * ((q1 * q2) + (q0 * q3)),     2 * ((q1 * q3) + (q0 * q2)), 0,
        2 * ((q1 * q2) - (q0 * q3)), 1 - 2 * ((q1 * q1) + (q3 * q3)), 2 * ((q0 * q1) + (q2 * q3)), 0,
        2 * ((q0 * q2) + (q1 *q3)),  2 * ((q2 * q3) - (q0 * q1)),     1 - 2 * ((q1 * q1) + (q2 * q2)), 0,

        0, -15, -50, 1,
    };*/

    // Source: https://automaticaddison.com/how-to-convert-a-quaternion-to-a-rotation-matrix/
    /*float *mat = new float[]{
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

Quaternion Quaternion::from_euler(float yaw, float pitch, float roll) {
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

float *Quaternion::to_euler() {
    float roll, pitch, yaw;

    // roll (x-axis rotation)
    double sinr_cosp = 2 * (w * x + y * z);
    double cosr_cosp = 1 - 2 * (x * x + y * y);
    roll = std::atan2(sinr_cosp, cosr_cosp);

    // pitch (y-axis rotation)
    double sinp = 2 * (w * y - z * x);
    if (std::abs(sinp) >= 1)
        pitch = std::copysign(M_PI / 2, sinp); // use 90 degrees if out of range
    else
        pitch = std::asin(sinp);

    // yaw (z-axis rotation)
    double siny_cosp = 2 * (w * z + x * y);
    double cosy_cosp = 1 - 2 * (y * y + z * z);
    yaw = std::atan2(siny_cosp, cosy_cosp);

    return new float[4]{
            yaw, pitch, roll,
    };
}

void Quaternion::add_euler(float yaw, float pitch, float roll) {
    float* euler = to_euler();

    Quaternion q = from_euler(euler[0] + yaw, euler[1] + pitch, euler[2] + roll);

    w = q.w;
    x = q.x;
    y = q.y;
    z = q.z;
}