#ifndef HELICOPTER_H
#define HELICOPTER_H

#include <Character.h>

class Helicopter : public Character
{
    public:
        Helicopter(Properties props); //: Character(props) {}

        virtual void Draw();
        virtual void Update(float dt);
        virtual void Clean();

    protected:

    private:
        int m_Row;
        int m_FrameCount;
};

#endif // HELICOPTER_H
