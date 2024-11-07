#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <iostream>

using namespace std;

class Vector2D
{
    public:
        int X, Y;

        Vector2D(float x = 0, float y = 0): X(x), Y(y) {}

        inline Vector2D operator+(const Vector2D& v2) const // Vector Addition
        {
            return Vector2D(X + v2.X, Y + v2.Y);
        }

        inline Vector2D operator-(const Vector2D& v2) const // Vector Subtraction
        {
            return Vector2D(X - v2.X, Y - v2.Y);
        }

        inline Vector2D operator*(const float scalar) const // Vector Multiplication
        {
            return Vector2D(X*scalar, Y*scalar);
        }

        void Log(string mag = "")
        {
            cout<<mag<<"(X Y) = ("<<X<<" "<<Y<<")"<<endl;
        }
    protected:

    private:
};

#endif // VECTOR2D_H
