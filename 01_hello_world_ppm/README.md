# Chapter 1
this is a small CLI program that creates a green red gradient of a user specified size.
the output format is PPM.

## Building
1. `cmake -B build`
2. `cmake --build build`
- Note: An executable called `hello_world` will be generated.

## Usage
`./hello_world <filename> [width] [height]`

### Other Usage Options
- **Option 1:** `./hello_world out.ppm` (Outputs 256x256)
- **Option 2:** `./hello_world out.ppm 512` (Outputs 512x512)
- **Option 3:** `./hello_world out.ppm 1920 1080` (Outputs 1920x1080)

## Possible Future TODOS:
- [ ] Add a TUI for interactive size selection
- [ ] Support user-specified start/end colors
- [ ] Implement Binary PPM (P6) or PNG support for better compression