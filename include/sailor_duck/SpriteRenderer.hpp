#ifndef SAILOR_DUCK_SPRITE_RENDERER_HPP
#define SAILOR_DUCK_SPRITE_RENDERER_HPP

#include "sailor_duck/ColorPalette.hpp"
#include "sailor_duck/Sprite.hpp"

namespace sailor_duck {

// Responsable de traducir datos de sprite en llamadas compactas a MiniWin.
class SpriteRenderer {
public:
    explicit SpriteRenderer(int pixel_size);

    // Dibuja el sprite usando la paleta recibida y una posicion base.
    void draw(const Sprite& sprite, const ColorPalette& palette, float offset_x, float offset_y) const;

private:
    int pixel_size_;
};

} // namespace sailor_duck

#endif // SAILOR_DUCK_SPRITE_RENDERER_HPP
