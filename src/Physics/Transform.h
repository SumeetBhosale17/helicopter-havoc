#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <string>
#include "Vector2D.h"

using namespace std;

class Transform
{
    public:

        float X, Y;

        Transform(float x = 0, float y = 0) : X(x), Y(y) {}

        inline void TranslateX(float x) {X += x;}
        inline void TranslateY(float y) {Y += y;}
        inline void Translate(Vector2D v) {X += v.X; Y += v.Y;}

        void Log(string mag = "")
        {
            cout<<mag<<"(X Y) = ("<<X<<" "<<Y<<")"<<endl;
        }

    protected:

    private:
};

#endif // TRANSFORM_H
