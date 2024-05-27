#ifndef __DRAWING_REPOSITORY_HPP__
#define __DRAWING_REPOSITORY_HPP__

#include "Utilities.hpp"
#include <map>
#include <SFML/Graphics.hpp>

class DrawingRepository {
    private:
        // Constructor and destructor are made private
        // because the DrawingRepository is a Singleton
        DrawingRepository(){}
        ~DrawingRepository(){}

        // Only instance
        static DrawingRepository * drawingRepository;

        // Maps kanjis (identified by their hash code) to vectors of strokes
        std::map<hash_t,std::vector<sf::VertexArray>> strokes;

    public:


};

#endif // __DRAWING_REPOSITORY_HPP__
