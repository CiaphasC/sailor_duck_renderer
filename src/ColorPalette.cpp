#include "sailor_duck/ColorPalette.hpp"

#include <stdexcept>

namespace sailor_duck {

ColorPalette::ColorPalette() {
    // Reservamos memoria de forma anticipada para evitar reallocs durante la carga del sprite.
    colors_.reserve(16);
    indices_.reserve(16);
}

void ColorPalette::add_color(char symbol, Color color) {
    // Permite redefinir un color sin crear nuevas entradas, util en ajustes de tono.
    auto it = indices_.find(symbol);
    if (it != indices_.end()) {
        colors_[it->second] = color;
        return;
    }

    const auto index = colors_.size();
    colors_.push_back(color);
    indices_.emplace(symbol, index);
}

const Color* ColorPalette::find(char symbol) const {
    auto it = indices_.find(symbol);
    if (it == indices_.end()) {
        return nullptr;
    }
    return &colors_[it->second];
}

const std::vector<Color>& ColorPalette::colors() const {
    return colors_;
}

} // namespace sailor_duck
