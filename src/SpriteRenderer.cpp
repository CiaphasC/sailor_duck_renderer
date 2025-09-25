#include "sailor_duck/SpriteRenderer.hpp"

#include "miniwin.h"

namespace sailor_duck {

SpriteRenderer::SpriteRenderer(int pixel_size) : pixel_size_{pixel_size} {}

void SpriteRenderer::draw(const Sprite& sprite, const ColorPalette& palette, float offset_x, float offset_y) const {
    for (int y = 0; y < sprite.height(); ++y) {
        // Recorremos la fila mediante aritmetica de punteros para reducir el trabajo del compilador.
        const char* row_ptr = sprite.row_data(y);
        for (int x = 0; x < sprite.width(); ++x) {
            const char symbol = *(row_ptr + x);
            const Color* color = palette.find(symbol);
            if (!color) {
                continue; // Simbolo reservado para transparencia.
            }

            miniwin::color_rgb(color->r, color->g, color->b);

            const float left = offset_x + static_cast<float>(x * pixel_size_);
            const float top = offset_y + static_cast<float>(y * pixel_size_);
            const float right = left + pixel_size_;
            const float bottom = top + pixel_size_;
            miniwin::rectangulo_lleno(left, top, right, bottom);
        }
    }
}

} // namespace sailor_duck
