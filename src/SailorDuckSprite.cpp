#include "sailor_duck/SailorDuckSprite.hpp"

#include <array>
#include <cstddef>
#include <cstring>
#include <memory>
#include <stdexcept>

namespace {

using sailor_duck::Color;
using sailor_duck::ColorPalette;
using sailor_duck::Sprite;

constexpr int kSpriteWidth = 34;
constexpr int kSpriteHeight = 36;

// Patron del pato marinero: 34x36 pixeles en notacion compacta.
constexpr std::array<const char*, kSpriteHeight> kSpriteRows = {
    "..................................",
    ".................OOO..............",
    "................OOOOO.............",
    "...............OOHMHOO............",
    ".............OOOHHMHHOOO..........",
    "............OOHHHHMMHHHOO.........",
    "...........OOHHHHPPPHMHHOO........",
    "..........OOHHMppPPPPppHHOO.......",
    ".........OOHMppPPPPPPPPppHOO......",
    "........OOHMppPPPPPPPPPPppHOO.....",
    ".....OOWWWwOHHppPPPEEEEPpPPppHOO..",
    "....OOWwwwwOHHpPPYYYYyyyyPPppHOO..",
    "....OOWwwwOHHppPPYYYYyyyyyyPPpHOO.",
    ".....OWwwOHHppPPYYYYyyyyyyPPpHOO..",
    "......OwOOHHppPPYYYYyyyyPPppHHO...",
    "......OOHHppPPPPPPPPPPppHHO.......",
    "......OHHppHHHHHHHHHHppHHO........",
    ".......OHppHHHHHHHHHHppHHO........",
    ".......OOHHHHHHHHHHHHHHOO.........",
    "........OOHHHHHHHHHHHHOOO.........",
    "........OOHHHHHHHHHHHHOOO.........",
    ".......OOHHHHHHHHHHHHHHOO.........",
    "......OOHHHHHHHHHHHHHHHOO.........",
    "......OHHHHHHHHHHHHHHHHOOO........",
    "......OHHHHBBBBMMMMBBHHHOO........",
    "......OHHHBBBBBRRRRBBHHOO.........",
    "......OHHHBBBBrrrrrBBHOO..........",
    ".......OHHBBBBrrrrrBBHOO..........",
    ".......OHHBBBBrrrrrBBHOO..........",
    "........OHBBBRRRRRRBHOO...........",
    "........OHHBBRrrrrRBHOO...........",
    ".........OHBBRrrrrRBHO............",
    ".........OHHBRrrrrRBOO............",
    "..........OOBfffffBBO.............",
    "...........OOFFFFFGOO.............",
    "............OFFFFFGO.............."
};

constexpr Color make_color(std::uint8_t r, std::uint8_t g, std::uint8_t b) {
    return Color{r, g, b};
}

}  // namespace

namespace sailor_duck {

ColorPalette build_sailor_duck_palette() {
    ColorPalette palette;
    palette.add_color('O', make_color(54, 23, 84));   // Perfil violeta oscuro.
    palette.add_color('H', make_color(227, 242, 255)); // Cuerpo e indumentaria iluminados.
    palette.add_color('M', make_color(185, 211, 248)); // Azul medio para volúmenes.

    palette.add_color('P', make_color(198, 124, 240)); // Pañuelo púrpura con luz.
    palette.add_color('p', make_color(132, 74, 200));  // Pañuelo en sombra.

    palette.add_color('W', make_color(248, 251, 255)); // Guante brillo.
    palette.add_color('w', make_color(206, 222, 255)); // Guante sombra.

    palette.add_color('E', make_color(255, 255, 255)); // Ojo.
    palette.add_color('Y', make_color(249, 186, 74));  // Pico iluminado.
    palette.add_color('y', make_color(224, 135, 55));  // Pico sombra.

    palette.add_color('B', make_color(143, 162, 230)); // Cinturón y faldón.
    palette.add_color('R', make_color(98, 112, 189));  // Cuerda iluminada.
    palette.add_color('r', make_color(58, 68, 146));   // Cuerda en sombra.

    palette.add_color('F', make_color(245, 150, 66));  // Pata iluminada.
    palette.add_color('f', make_color(209, 103, 40));  // Pata en sombra.
    palette.add_color('G', make_color(120, 67, 36));   // Suela y borde inferior.

    return palette;
}

Sprite build_sailor_duck_sprite() {
    auto pixels = std::make_unique<char[]>(kSpriteWidth * kSpriteHeight);
    char* cursor = pixels.get();

    for (const char* row : kSpriteRows) {
        const std::size_t row_length = std::strlen(row);
        if (row_length != static_cast<std::size_t>(kSpriteWidth)) {
            throw std::runtime_error("Fila del sprite con longitud inesperada");
        }

        std::memcpy(cursor, row, kSpriteWidth);
        cursor += kSpriteWidth; // Avanzamos el puntero a la siguiente fila.
    }

    return Sprite{kSpriteWidth, kSpriteHeight, std::move(pixels)};
}

}  // namespace sailor_duck
