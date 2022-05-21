#ifndef INC_2022_03_30_QUATERNION_H
#define INC_2022_03_30_QUATERNION_H


class Quaternion {
private:
public:
    float _q1;
    float _q2;
    float _q3;
    float _q4;

    explicit Quaternion(float q1 = 0, float q2 = 0, float q3 = 0, float q4 = 0)
            : _q1(q1), _q2(q2), _q3(q3), _q4(q4) {}

    ~Quaternion() = default;

    // Somme
    Quaternion operator+=(const Quaternion &y) {
        _q1 += y._q1;
        _q2 += y._q2;
        _q3 += y._q3;
        _q4 += y._q4;
        return *this;
    }

    // Multiplication
    Quaternion operator*=(const Quaternion &y) {
        _q1 *= y._q1;
        _q2 *= y._q2;
        _q3 *= y._q3;
        _q4 *= y._q4;
        return *this;
    }

    // Multiplication scalaire
    Quaternion operator*=(const float y) {
        _q1 *= y;
        _q2 *= y;
        _q3 *= y;
        _q4 *= y;
        return *this;
    }

    // Conjugaison
    static inline Quaternion conjugate(const Quaternion &x) {
        return Quaternion{x._q1, -x._q2, -x._q3, -x._q4};
    }

    // Norme
    float norm() const {
        return _q1 * _q1 + _q2 * _q2 + _q3 * _q3 + _q4 * _q4;
    }

    // Quaternion unitaire
    bool unit() const {
        return this->norm() == 1;
    }

    // produit vectoriel, produit matriciel

    float *to_rotation_matrix();
};


#endif //INC_2022_03_30_QUATERNION_H
