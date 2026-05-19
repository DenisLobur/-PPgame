CXX := g++
CXXFLAGS := -std=c++23 -Wall -Wextra -pedantic
TARGET := ppgame
SRC := \
	main.cpp \
	external/imgui/imgui.cpp \
	external/imgui/imgui_draw.cpp \
	external/imgui/imgui_widgets.cpp \
	external/imgui/imgui_tables.cpp \
	external/imgui-sfml/imgui-SFML.cpp

IMGUI_CFLAGS := -Iexternal/imgui -Iexternal/imgui-sfml -DIMGUI_USER_CONFIG=\"imconfig-SFML.h\"
OPENGL_LIBS := -lGL

# Prefer pkg-config so include/lib paths are discovered automatically.
SFML_CFLAGS := $(shell pkg-config --cflags sfml-graphics 2>/dev/null)
SFML_LIBS := $(shell pkg-config --libs sfml-graphics sfml-window sfml-system 2>/dev/null)

# Fallback for systems without pkg-config metadata.
ifeq ($(strip $(SFML_LIBS)),)
SFML_LIBS := -lsfml-graphics -lsfml-window -lsfml-system
endif

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SFML_CFLAGS) $(IMGUI_CFLAGS) $(SRC) -o $(TARGET) $(SFML_LIBS) $(OPENGL_LIBS)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all run clean
