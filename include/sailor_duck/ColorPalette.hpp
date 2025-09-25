#ifndef SAILOR_DUCK_COLOR_PALETTE_HPP
#define SAILOR_DUCK_COLOR_PALETTE_HPP

#include <cstdint>
#include <string>
#include <unordered_map>
#include <vector>

namespace sailor_duck {

// Estructura simple para mover colores entre componentes sin copias costosas.
struct Color {
    std::uint8_t r;
    std::uint8_t g;
    std::uint8_t b;
};

// Tabla de colores indexada por caracteres para describir sprites de forma compacta.
class ColorPalette {
public:
    ColorPalette();

    // Registra un color identificandolo con un simbolo de la plantilla del sprite.
    void add_color(char symbol, Color color);

    // Devuelve un puntero constante al color asociado o nullptr si el simbolo no existe.
    const Color* find(char symbol) const;

    // Ofrece acceso de solo lectura para diagnosticos o pruebas.
    const std::vector<Color>& colors() const;

private:
    std::vector<Color> colors_;
    std::unordered_map<char, std::size_t> indices_;
};

} // namespace sailor_duck

#endif // SAILOR_DUCK_COLOR_PALETTE_HPP
