#ifndef INC_2022_03_30_QUATERNION_H
#define INC_2022_03_30_QUATERNION_H

#include <cmath>

class Quaternion {
private:
public:
    float w;
    float x;
    float y;
    float z;

    explicit Quaternion(float q1 = 0, float q2 = 0, float q3 = 0, float q4 = 0)
            : w(q1), x(q2), y(q3), z(q4) {}

    ~Quaternion() = default;

    // Somme
    Quaternion operator+=(const Quaternion &other) {
        w += other.w;
        x += other.x;
        y += other.y;
        z += other.z;
        return *this;
    }

    // TODO: https://stackoverflow.com/a/39001018
    // Multiplication
    Quaternion operator*=(const Quaternion &other) {
        w *= other.w;
        x *= other.x;
        y *= other.y;
        z *= other.z;
        return *this;
    }

    // Multiplication scalaire
    Quaternion operator*=(const float other) {
        w *= other;
        x *= other;
        y *= other;
        z *= other;
        return *this;
    }

    // Conjugaison
    static inline Quaternion conjugate(const Quaternion &other) {
        return Quaternion{other.w, -other.x, -other.y, -other.z};
    }

    // Norme
    float norm() const {
        return w * w + x * x + y * y + z * z;
    }

    // Quaternion unitaire
    bool unit() const {
        return this->norm() == 1;
    }

    // produit vectoriel, produit matriciel

    float *to_rotation_matrix() const;

    static Quaternion to_quaternion(float yaw, float pitch, float roll);
};


#endif //INC_2022_03_30_QUATERNION_H
