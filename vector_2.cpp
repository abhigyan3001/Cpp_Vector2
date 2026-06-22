#include <iostream>
#include <cmath>

using namespace std;

class vector2
{

private:
    float x;
    float y;

public:
    vector2(float x = 0, float y = 0)
    {
        this->x = x;

        this->y = y;
    }

    vector2 operator+(const vector2 &other)

    {
        return vector2(x + other.x,
                       y + other.y);
    }

    vector2 operator-(const vector2 &other)
    {
        return vector2(x-other.x,y-other.y);
    }

    vector2 operator*(float scalar)
    {
        return vector2(x*scalar,y*scalar);
    }

     float dot(const vector2& other)
    {
        return x * other.x +
               y * other.y;
    }

    // Magnitude (Length)
    float magnitude()
    {
        return sqrt(x*x + y*y);
    }

    // Normalize
    vector2 normalize()
    {
        float mag = magnitude();

        if(mag == 0)
            return vector2();

        return vector2(x/mag,
                       y/mag);
    }

    void display()
    {

        cout << "(" << x << "," << y << ")" << endl;
    }
};

int main()
{
    vector2 playervelocity(3, 4);

    vector2 windforce(1, 2);

    vector2 finalvelocity = playervelocity + windforce;

    cout << "Final Velocity = ";
    finalvelocity.display();

    cout << "Speed = "
         << finalvelocity.magnitude()
         << endl;

    cout << "Dot Product = "
         << playervelocity.dot(windforce)
         << endl;

    return 0;
}
