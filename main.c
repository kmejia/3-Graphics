#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"
#include "parser.h"
int main( int argc, char **argv ) {
  screen s;
  color c;
  c.red = 50;
  c.green = 100;
  c.blue = MAX_COLOR;
  clear_screen(s);
  struct matrix *edges;
  struct matrix *transform;
  edges = new_matrix(4, 4);
  transform = new_matrix(4, 4);
  
  if ( argc == 2 )
    parse_file( argv[1], transform, edges, s );
  else
    parse_file( "stdin", transform, edges, s );
  
  add_circle(edges,50,50,20,0.001);
  draw_lines(edges,s,c);
  display(s);
  free_matrix(transform );
  free_matrix(edges);
} 
