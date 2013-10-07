# 6671 1er c 2013

# Comandos
CPP     = g++
CFLAGS  = -g -Wall --pedantic
LFLAGS  = -lGLEW -lGLU -lGL -lglut -lSOIL
OTHERFLAGS = -DFREEGLUT_STATIC -DGLEW_STATIC

VALG   = valgrind --track-origins=yes --leak-check=full
CPY    = cp -f
RM     = rm -f
RMDIR  = rm -f -r

# Directorios de cada tipo de archivo
SRCDIR   = src
INCDIR   = inc
OBJDIR   = obj
RESDIR   = res
BINDIR   = bin
TEMPDIR  = tmp

# Wildcards
SOURCES      := $(wildcard $(SRCDIR)/*/*.cpp)
SOURCESTEMP  := $(wildcard $(TEMPDIR)/*.cpp)
OBJECTS      := $(SOURCESTEMP:$(TEMPDIR)/%.cpp=$(OBJDIR)/%.o)
INCLUDES     := $(wildcard $(INCDIR)/*/*.h)
INCLUDESTEMP := $(wildcard $(TEMPDIR)/*.h)
RESOURCES    := $(wildcard $(RESDIR)/*/*)

# Nombre del ejecutable
EXENAME = 6671


# ########## #
# DIRECTIVAS #
# ########## #

# Construccion de ejecutable
.SILENT:
all: clean
	@echo "\nDIRECTORIOS:"
	@make directorios
	@echo "\nCOMPILACIONES:"
	@make objetos
	@echo "\nRECURSOS:"
	@make recursos
	@echo "\nCONSTRUCCIONES:"
	@$(CPP) $(CFLAGS) $(OBJDIR)/*.o $(LFLAGS) -o $(BINDIR)/$(EXENAME)
	@echo "	. El ejecutable "$(EXENAME)" ha sido creado exitosamente!"
	@echo "	  Ingresar 'make exe' para ejecutarlo normalmente"
	@echo "	  o 'make vexe' para correrlo con valgrind.\n"
	@$(RMDIR) $(TEMPDIR)

# Creacion de directorios
$(TEMPDIR):
	@mkdir $(TEMPDIR)
	@$(CPY) $(SRCDIR)/*/*.cpp $(TEMPDIR)
	@$(CPY) $(INCDIR)/*/*.h $(TEMPDIR)
	
$(OBJDIR):
	@mkdir $(OBJDIR)
	@echo "	. La carpeta '"$@"' ha sido creada exitosamente!"

$(BINDIR):
	@mkdir $(BINDIR)
	@echo "	. La carpeta '"$@"' ha sido creada exitosamente!"

directorios: $(TEMPDIR) $(OBJDIR) $(BINDIR)

# Creacion de recursos
recursos: | directorios
	@$(CPY) $(RESDIR)/*/*.* $(BINDIR)
	@$(CPY) $(RESDIR)/*/*.* $(OBJDIR)
#	@$(CPY) $(RESDIR)/*/*.* $(TMPDIR)
	@echo "	. Los recursos han sido copiados exitosamente!"

# Compilaciones
$(OBJECTS): $(OBJDIR)/%.o : $(TEMPDIR)/%.cpp | directorios
	@$(CPP) $(CFLAGS) $(OTHERFLAGS) -c $< -o $@
	@echo "	. "$*".cpp ha sido compilado exitosamente!"

objetos: $(OBJECTS)

# Ejecuciones
exe:
	@cd $(BINDIR); ./$(EXENAME); cd ..

vexe:
	@cd $(BINDIR); $(VALG) ./$(EXENAME); cd ..

# Limpieza
.PHONY: clean
clean:
	@echo "\nLIMPIEZA:"
	@$(RMDIR) $(OBJDIR) $(TEMPDIR) $(BINDIR)
	@echo "	. El repositorio ha sido limpiado exitosamente!"
