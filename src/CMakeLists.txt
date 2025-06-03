# 1: Crear el directorio build con `mkdir build`
# 2: Ir al directorio build recién creado con `cd build`
# 3: Usar CMake para crear toda la morralla en el directorio build. `cmake .. -G Ninja`
# 4: Compilar usando `ninja` o lo que hayas utilizado para compilar si en vez de `-G Ninja` has puesto algo distinto en el comando de arriba
# 5: Ejecutar el KanjiGod.exe en el directorio principal

cmake_minimum_required(VERSION 3.28)
project(EraseUnCombate LANGUAGES CXX)

# El programa se creará en el directorio raíz del proyecto
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/..)

# Si hay algún error saldrán colorines
set(CMAKE_COLOR_DIAGNOSTICS ON)

# Aunque se use CMake super moderno se permitirá que el CMake de SFML sea más viejuno
set(CMAKE_POLICY_VERSION_MINIMUM 3.5)

# Cosa rara que se trae el repositorio entero de SFML de GitHub
include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.1
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

# Se ponen todos los ficheros .cpp
add_executable(KanjiGod main.cpp Button.cpp Kanji.cpp Utilities.cpp Controller.cpp KanjiRepository.cpp Word.cpp DrawableStroke.cpp MainWindow.cpp WordRepository.cpp DrawingBoard.cpp PointByPointBoard.cpp main.cpp Exercise.cpp ShowingBoard.cpp ScrewWindows.cpp Sign.cpp ResourceHolder.cpp)

# Se especifica que el estándar de C++ que se quiere usar es el de 2020
target_compile_features(KanjiGod PRIVATE cxx_std_20)

# Se especifican los cinco módulos de SFML
target_link_libraries(KanjiGod PRIVATE SFML::Graphics SFML::Window SFML::System SFML::Audio)

# Opciones de compilación para que salgan warnings
add_compile_options(-Wall -Wextra -Wpedantic)