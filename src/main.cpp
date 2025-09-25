#include "miniwin.h"

#include "sailor_duck/SailorDuckSprite.hpp"
#include "sailor_duck/SpriteRenderer.hpp"

int main() {
    using namespace miniwin;
    constexpr int kPixelSize = 12;
    constexpr int kMargin = 48;

    // Cargamos la paleta y la plantilla de pixeles en memoria dinamica controlada.
    auto palette = sailor_duck::build_sailor_duck_palette();
    auto sprite = sailor_duck::build_sailor_duck_sprite();

    const int canvas_width = sprite.width() * kPixelSize + kMargin * 2;
    const int canvas_height = sprite.height() * kPixelSize + kMargin * 2;

    // Ajustamos la ventana con un margen para que el sprite respire visualmente.
    vredimensiona(canvas_width, canvas_height);
    borra();

    sailor_duck::SpriteRenderer renderer{kPixelSize};
    renderer.draw(sprite, palette, static_cast<float>(kMargin), static_cast<float>(kMargin));
    refresca();

    // Bucle pasivo a la espera de ESC para cerrar sin ocupar CPU de forma innecesaria.
    bool running = true;
    while (running) {
        espera(16);
        const int key = tecla();
        if (key == ESCAPE) {
            running = false;
        }
    }

    vcierra();
    return 0;
}
