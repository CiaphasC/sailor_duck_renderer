# Sailor Duck Renderer

Proyecto C++ basado en MiniWin que renderiza pixel art empleando memoria dinamica controlada y aritmetica con punteros.

## Estructura principal

- `src/`: implementacion de la logica, renderizado y punto de entrada.
- `include/`: cabeceras publicas con comentarios en espanol.
- `vendor/miniwin/`: version embebida de MiniWin (sin dependencias externas).
- `project/SailorDuckRenderer.cbp`: proyecto listo para Code::Blocks.
- `CMakeLists.txt`: permite compilar con CMake, Ninja o desde VSCode.

## Compilacion con CMake

```bash
cmake -S . -B build
cmake --build build
```

El ejecutable quedara en `build/sailor_duck_renderer.exe` (Windows) o `build/sailor_duck_renderer` (Linux/macOS).

## Ejecucion rapida (sin CMake)

Ejecuta `scripts\build_and_run.bat` para compilar con el g++ que trae Code::Blocks (o cualquier MinGW en el PATH) y lanzar la ventana en un solo paso.

## Dependencia del compilador MinGW

Si Code::Blocks esta instalado en su ruta por defecto (`C:\\Program Files\\CodeBlocks\\MinGW\\bin\\g++.exe`), el script lo detecta automaticamente. Tambien busca `g++.exe` dentro de MSYS2 (`C:\\msys64\\mingw64\\bin\\g++.exe`) y `clang++.exe` en el PATH o en `C:\\Program Files\\LLVM\\bin\\clang++.exe`.

Si prefieres incluir un toolchain portatil dentro del proyecto, colocalo por ejemplo en `sailor_duck_renderer\\toolchain\\bin` y cambia las variables del script para que apunten alli, o añade temporalmente la carpeta con `g++.exe` o `clang++.exe` al `PATH` antes de ejecutar.




## Uso desde VSCode

1. Instalar la extension **CMake Tools**.
2. Abrir la carpeta `sailor_duck_renderer` en VSCode.
3. Elegir un kit de compilacion y ejecutar la tarea `CMake: build`.
4. Lanzar `sailor_duck_renderer` desde el panel de CMake Targets o con `F5` si se configura una `launch.json` sencilla.

## Apertura en Code::Blocks

1. Abrir Code::Blocks y seleccionar `File > Open...`.
2. Cargar `project/SailorDuckRenderer.cbp`.
3. Elegir el objetivo `Release` o `Debug` y compilar.
4. Ejecutar el binario desde `Build > Run`.

## Controles en tiempo de ejecucion

- La ventana aparece centrada con margen para apreciar el sprite.
- Presiona `ESC` para cerrar de forma limpia.

## Notas tecnicas

- El sprite se define en `src/SailorDuckSprite.cpp` mediante un mapa compacto de caracteres.
- La memoria de pixeles se gestiona con `std::unique_ptr<char[]>` para evitar fugas.
- `SpriteRenderer` realiza la iteracion con punteros para minimizar el coste sobre la CPU.
- Los colores se abstraen en `ColorPalette`, facilitando posibles modificaciones de paleta.



