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


    Quaternion operator*(const Quaternion &q2) {
        Quaternion result;

        result.w = this->w*q2.w - this->x*q2.x - this->y*q2.y - this->z*q2.z;
        result.x = this->x*q2.w + this->w*q2.x + this->y*q2.z - this->z*q2.y;
        result.y = this->w*q2.y - this->x*q2.z + this->y*q2.w + this->z*q2.x;
        result.z = this->w*q2.z + this->x*q2.y - this->y*q2.x + this->z*q2.w;

        return result;
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
