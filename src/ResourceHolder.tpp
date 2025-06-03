#include <iostream>

template <class Resource, class Identifier>
void ResourceHolder<Resource,Identifier>::load(Identifier id, const std::string& filePath){

    // Unique pointers are great for this case since they can only exist in one place at a time.
    // Since this is a Resource Holder, it will hold resources and return references to them, so there
    // will only be one copy of each resource, and it will be stored here.
    std::unique_ptr<Resource> resource = std::make_unique<Resource>();
    
    // If the resource can't be loaded, the process dies horribly
    if(!resource->loadFromFile(filePath)){
        std::cerr << "ERROR: tried to load the resource at " << filePath << ", but it wasn't possible\n";
        exit(EXIT_FAILURE);
    }

    // If everything went alright, we can store the resource in the Resource Holder. With std::move we
    // tell C++ that the unique pointer now belongs to the Resource Holder until it is moved again (until
    // now, it belonged to this load function)
    resourceMap.insert(std::make_pair(id,std::move(resource)));
}

template <class Resource, class Identifier>
Resource& ResourceHolder<Resource,Identifier>::get(Identifier id){
    // First we need to find the element in the resource map.
    auto found = resourceMap.find(id);

    // If the element can't be found, the process dies horribly
    if(found == resourceMap.end()){
        std::cerr << "ERROR: tried to get a resource, but it wasn't available in the Resource Holder\n";
        exit(EXIT_FAILURE);
    }

    // Once we find the element, we use found->second because found has two values: the first one
    // is the identifier and the second one is the resource. Now, since the resource is actually a unique
    // pointer, we must dereference it using the asterisk operator (*).
    return *(found->second);
}