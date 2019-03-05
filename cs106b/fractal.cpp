//fractals in natrue
// snowflakes
// clouds ...
// coding a fractal
// many fractals are implemented as a function that accepts x/y
// coordinates, size, and a level parameter
// - the level is the number of recurrences of the pattern to draw
// Example, Koch snowflake:
// lv1: snowflake(window, x, y, size, 1);
// lv2: snowflake(window, x, y, size, 2);
// lv3: snowflake(window, x, y, size, 3);

//Cantor set

void cantorSet(Gwindow& window, int x, int y, int length, int levels) {
    if (levels == 1) {
        //base case
        window.drawLine(x, y, x+length, y);
    } else {
        window.drawLine(x, y, x+length, y);
        // recursive case; level > 1
        // I will handle the first level
        //
        CantorSet(window, x, y + 20, length/3, levels -1);
        CantorSet(window, x + 2*length/3, length/3, levels-1);
        
        
    }
}
