#ifndef SAILOR_DUCK_SAILOR_DUCK_SPRITE_HPP
#define SAILOR_DUCK_SAILOR_DUCK_SPRITE_HPP

#include "sailor_duck/ColorPalette.hpp"
#include "sailor_duck/Sprite.hpp"

namespace sailor_duck {

// Fabrica la paleta de colores para el sprite.
ColorPalette build_sailor_duck_palette();

// Construye el sprite comprimido en memoria con la pose completa.
Sprite build_sailor_duck_sprite();

} // namespace sailor_duck

#endif // SAILOR_DUCK_SAILOR_DUCK_SPRITE_HPP
