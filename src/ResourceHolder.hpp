#pragma once

#include "Enums.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <memory>
#include <map>

/*
    The Resource Holder is a class that stores all sorts of resources. The other classes can
    use the Resource Holder to access textures, fonts and sounds instead of accessing them
    themselves. This is a generic class, so it can be used for any resource.
*/

// First of all, we declare the class
template <class Resource, class Identifier>
class ResourceHolder;

// Now we can use trypedefs to make it easier to write the names of the different
// resource holders we use
typedef ResourceHolder<sf::Texture,TextureID> TextureHolder;
typedef ResourceHolder<sf::SoundBuffer,SoundID> SoundHolder;
typedef ResourceHolder<sf::Font,FontID> FontHolder;

// This class is a Singleton, which means that there is only one resource holder
// for each type of resource. You can't create your own instances and must use
// the instances provided by the class by using the getInstance() method
template <class Resource, class Identifier>
class ResourceHolder
{
    protected:
        // Both the constructor and the destructur are protected
        ResourceHolder(){loadAllResources();}
        ~ResourceHolder(){}

        // The only instances are here
        static TextureHolder * textureHolder;
        static SoundHolder * soundHolder;
        static FontHolder * fontHolder;

    private:
        // A map that stores resources based on their identifiers
        std::map<Identifier, std::unique_ptr<Resource>> resourceMap;

    public:
        // Loads a resource given its identifier and the path to its file
        void load(Identifier id, const std::string& filePath);

        // Returns a reference to a resource given its identifier
        Resource& get(Identifier id);

        // Loads all resources from the specific resource holder used
        void loadAllResources();

        // NEVER CLONE A SINGLETON
        ResourceHolder(ResourceHolder &other) = delete;

        // NEVER ASSIGN A SINGLETON
        void operator=(const ResourceHolder &) = delete;

        // Use this to get the instances
        static ResourceHolder<Resource,Identifier> * getInstance();

};

// Because this class is a template class, there are some tricky stuff that must be put in a
// separate .tpp file. This file must be included right here, at the end of the .hpp file

#include "ResourceHolder.tpp"