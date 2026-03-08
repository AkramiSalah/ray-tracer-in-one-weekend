#pragma once

#include <cmath>
#include <iostream>
#include <cassert>
#include "../Float.h"

struct Vec3{
    static constexpr size_t VECTOR_SIZE = 3;

    Float e[VECTOR_SIZE];

    constexpr Vec3() : e{ ZERO, ZERO, ZERO }{}
    constexpr Vec3(Float e0, Float e1, Float e2) : e{e0, e1, e2}{}
    constexpr explicit Vec3(Float scalar) : e{scalar,scalar,scalar}{}

    Vec3(const Vec3& other) = default;
    Vec3& operator=(const Vec3& other) = default;
    ~Vec3() = default;

    Float* begin(){return e;}
    Float* end(){return e + VECTOR_SIZE;}

    Float x() const { return e[0]; }
    Float y() const { return e[1]; }
    Float z() const { return e[2]; }

    Vec3 operator-() const{
        return Vec3(-e[0], -e[1], -e[2]);
    }

    const Float& operator[](size_t index) const{
        assert(index < VECTOR_SIZE);
        return e[index];
    }

    Float& operator[](size_t index){
        assert(index < VECTOR_SIZE);
        return e[index];
    }

    Vec3& operator+=(const Vec3& other){
        for (int i = 0; i < VECTOR_SIZE; ++i) e[i] += other.e[i];
        return *this;
    }

    Vec3& operator-=(const Vec3& other){
        for (int i = 0; i < VECTOR_SIZE; ++i) e[i] -= other.e[i];
        return *this;
    }

    Vec3& operator*=(const Float& scalar){
        for (int i = 0; i < VECTOR_SIZE; ++i) e[i] *= scalar;
        return *this;
    }

    Vec3& operator/=(const Float& scalar){
        assert( scalar != ZERO);
        return (*this) *= ONE/scalar;
    }

    Float length_squared() const{
        return dot(*this, *this);
    }

    Float length() const{
        return std::sqrt(length_squared());
    }

    // Vector Utility Functions
    friend std::ostream& operator<<(std::ostream& os, const Vec3& v){
        return os << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
    }

    friend Vec3 operator+(Vec3 lhs, const Vec3& rhs){
        lhs += rhs;
        return lhs;
    }

    friend Vec3 operator-(Vec3 lhs, const Vec3& rhs){
        return lhs + (-rhs);
    }

    friend Vec3 operator*(Vec3 lhs, const Float& scalar){
        return lhs *= scalar;
    }

    friend Vec3 operator*(const Float& scalar, const Vec3& rhs){
        return rhs * scalar;
    }

    // this is a hadamard/schur product!
    // it has been chosen as the default * becasue itll be used alot in the future.
    friend Vec3 operator*(Vec3 lhs, const Vec3& rhs){
        for (int i = 0; i < VECTOR_SIZE; ++i) lhs[i] *= rhs[i];
        return lhs;
    }

    friend Vec3 operator/(Vec3 v, Float scalar) {
        return v /= scalar;
    }

    friend Float dot(const Vec3& lhs, const Vec3& rhs){
        Float res = ZERO;
        for (int i = 0; i < VECTOR_SIZE; ++i) res += lhs[i] * rhs[i];
        return res;
    }

    friend Vec3 cross(const Vec3& lhs, const Vec3& rhs){
        return Vec3(
            lhs[1] * rhs[2] - lhs[2] * rhs[1],
            lhs[2] * rhs[0] - lhs[0] * rhs[2],
            lhs[0] * rhs[1] - lhs[1] * rhs[0]
        );
    }

    friend Vec3 unit_vector(const Vec3& v){
        return v / v.length();
    }

    static constexpr Vec3 zero() { return Vec3(ZERO, ZERO, ZERO); }

    static constexpr Vec3 xhat() { return Vec3(ONE, ZERO, ZERO); }
    static constexpr Vec3 yhat() { return Vec3(ZERO, ONE, ZERO); }
    static constexpr Vec3 zhat() { return Vec3(ZERO, ZERO, ONE); }
};

using Point3 = Vec3;
