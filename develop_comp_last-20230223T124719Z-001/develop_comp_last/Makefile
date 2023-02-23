CC		= gcc
RM		= /bin/rm
LIBPATH	= -L/usr/lib
INCPATH	= -I/usr/include
LIBS	= -lGL -lGLU -lglut -lm
OPT1	= -c -O2 -Wall -Wextra -Wno-unused-parameter -Wno-unused-function
TARGET	= run
HEAD	= common.h

OBJECTS = main.o draw_cone.o draw_torus.o draw_sphere.o draw_plane.o\
		  draw_cube.o draw_octahedron.o draw_dodecahedron.o\
		  draw_icosahedron.o draw_teapot.o draw_cylinder.o\
		  myCharacter.o tekiCharacter.o missile.o\
		  collision_judge.o\
		  initialize_Texture.o\
		  keyboard_proc.o mouse_proc.o loadBackground.o read_stl.o draw_stl.o

$(TARGET) : $(OBJECTS) $(HEAD) common.h gl_settings.h
	$(CC) $(OBJECTS) $(LIBPATH) -o $(TARGET) $(LIBS) -O2 -Wall -Wextra -Wno-unused-parameter -Wno-unused-function

main.o : main.c $(HEAD) common.h
	$(CC) $(OPT1) $< $(INCPATH)
draw_plane.o : draw_plane.c $(HEAD)
	$(CC) $(OPT1) $< $(INCPATH)
draw_cone.o : draw_cone.c $(HEAD)
	$(CC) $(OPT1) $< $(INCPATH)
draw_torus.o : draw_torus.c $(HEAD)
	$(CC) $(OPT1) $< $(INCPATH)
draw_sphere.o : draw_sphere.c $(HEAD)
	$(CC) $(OPT1) $< $(INCPATH)
draw_cube.o : draw_cube.c $(HEAD)
	$(CC) $(OPT1) $< $(INCPATH)
draw_octahedron.o : draw_octahedron.c $(HEAD)
	$(CC) $(OPT1) $< $(INCPATH)
draw_dodecahedron.o : draw_dodecahedron.c $(HEAD)
	$(CC) $(OPT1) $< $(INCPATH)
draw_icosahedron.o : draw_icosahedron.c $(HEAD)
	$(CC) $(OPT1) $< $(INCPATH)
draw_teapot.o : draw_teapot.c $(HEAD)
	$(CC) $(OPT1) $< $(INCPATH)
draw_cylinder.o : draw_cylinder.c $(HEAD)
	$(CC) $(OPT1) $< $(INCPATH)
myCharacter.o : myCharacter.c $(HEAD)
	$(CC) $(OPT1) $< $(INCPATH)
tekiCharacter.o : tekiCharacter.c $(HEAD)
	$(CC) $(OPT1) $< $(INCPATH)
collision_judge.o : collision_judge.c $(HEAD)
	$(CC) $(OPT1) $< $(INCPATH)
keyboard_proc.o : keyboard_proc.c $(HEAD)
	$(CC) $(OPT1) $< $(INCPATH)
mouse_proc.o : mouse_proc.c $(HEAD)
	$(CC) $(OPT1) $< $(INCPATH)
missile.o : missile.c $(HEAD)
	$(CC) $(OPT1) $< $(INCPATH)
initialize_Texture.o : initialize_Texture.c $(HEAD)
	$(CC) $(OPT1) $< $(INCPATH)
loadBackground.o : loadBackground.c $(HEAD)
	$(CC) $(OPT1) $< $(INCPATH)
read_stl.o : read_stl.c $(HEAD)
	$(CC) $(OPT1) $< $(INCPATH)
draw_stl.o : draw_stl.c $(HEAD)
	$(CC) $(OPT1) $< $(INCPATH)

clean :
	$(RM) -rf *.o
	$(RM) -rf run
