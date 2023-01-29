SUFFIX := .cpp
PROGNAME := main
COMPILER := g++
CPPFLAGS := -O2 -std=c++11 -Wall -Wextra -pipe
LIBFLAGS := -lglut -lGLU -lGL -lm

SOURCEDIR := ./src/
INCLUDEDIR := ./include/
OUTDIR := ./build/
ASSETSDIR := ./assets/

TARGET := $(OUTDIR)$(PROGNAME)
SOURCES := $(wildcard $(SOURCEDIR)*$(SUFFIX))
OBJECTS := $(addprefix $(OUTDIR),$(notdir $(SOURCES:$(SUFFIX)=.o)))

all: $(OBJECTS) $(LIBFLAGS)
	$(COMPILER) -I$(INCLUDEDIR) -o $(TARGET) $^

%.o:  $(addprefix $(SOURCEDIR),$(notdir $(%:.o=$(SUFFIX))))
	$(COMPILER) -I$(INCLUDEDIR) $(LIBFLAGS) $(CPPFLAGS) -o $@ -c $(SOURCEDIR)$(basename $(notdir $@))$(SUFFIX)

.PHONY: clean

clean:
	$(RM) $(OUTDIR)*

run:
	cp $(OUTDIR)$(PROGNAME) ./
	./$(PROGNAME)
