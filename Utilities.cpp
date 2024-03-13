#include "Utilities.hpp"

namespace util{
    bool isInRectangle(int x, int y, int rectX, int rectY, int rectWidth, int rectHeight)
    {
        return  x > rectX &&
                x < rectX+rectWidth &&
                y > rectY &&
                y < rectY+rectHeight;
    }
}