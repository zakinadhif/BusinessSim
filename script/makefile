# Special Chars
NULL :=
TAB  := $(NULL)	$(NULL)
define NEWLINE


endef

# Functions
define unique =
  $(eval seen :=)
  $(foreach _,$1,$(if $(filter $_,${seen}),,$(eval seen += $_)))
  ${seen}
endef # Remove duplicates in variable values

define at-source-wildcard =
$(patsubst $(SOURCE_DIR)/%,%,$(wildcard $(SOURCE_DIR)/$(value 1)))
endef # Wildcard but in source directory

define list =
$(NEWLINE) $(patsubst %,$(TAB)%$(NEWLINE),$1)
endef # Display variables down

# Directories
INCLUDE_DIR          := header
SOURCE_DIR           := code
EXTERNAL_INCLUDE_DIR := header/External/imgui header/External/imgui-sfml header/External/box2d
EXTERNAL_LIBRARY_DIR := libs
BUILD_DIR            := build
BINARY_DIR           := bin

# Dependencies, Objects, Libraries required to build the code
_LIBS     := tgui sfml-graphics sfml-window sfml-system GL GLU glut box2d
_SRC      := main.cpp \
	Game.cpp \
	$(call at-source-wildcard,External/*/*.cpp) \
	$(call at-source-wildcard,Component/*.cpp) \
	$(call at-source-wildcard,States/*.cpp)

# Executable Name
EXE_NAME := GameSystem

# Processing the specification above
_OBJ             := $(patsubst %.cpp,%.o,$(_SRC))
_DEPS            := $(patsubst %.cpp,%.d,$(_SRC))
DEPENDENCIES     := $(addprefix $(BUILD_DIR)/,$(_DEPS))
OBJECTS          := $(addprefix $(BUILD_DIR)/,$(_OBJ))
_OBJECT_SUBDIRS  := $(strip $(call unique,$(filter-out ./,$(dir $(_OBJ)))))
OBJECT_SUBDIRS   := $(addprefix $(BUILD_DIR)/,$(_OBJECT_SUBDIRS))
INCLUDES         := $(addprefix -I ,$(INCLUDE_DIR) $(EXTERNAL_INCLUDE_DIR))
LIBRARIES        := $(addprefix -l ,$(_LIBS))
EXTERNAL_LIB_DIR := $(addprefix -L ,$(EXTERNAL_LIBRARY_DIR))
BINARY           := $(BINARY_DIR)/$(EXE_NAME)

# Miscellaneous C Flags, like -Wall or warning flag
override CXXFLAGS += -Wall

# Variables pretty printing
$(info )
$(info General Informations -----)
$(info Compiler          : $(CXX))
$(info Flags             : $(CXXFLAGS))
$(info Source directory  : $(SOURCE_DIR))
$(info Binary directory  : $(BINARY_DIR))
$(info Include directory : $(INCLUDE_DIR) $(EXTERNAL_INCLUDE_DIR))
$(info Library directory : $(EXTERNAL_LIBRARY_DIR))
$(info Build directory   : $(BUILD_DIR))

$(info )
$(info Useful Informations ------)
$(info Libraries         : $(_LIBS))
$(info Codes $(call list,$(_SRC)))
$(info Dependencies $(call list,$(_DEPS)))
$(info Objects $(call list,$(_OBJ)))

$(info )
$(info Verbose Informations -----)
$(info Includes       $(INCLUDES))
$(info Library Dir    $(EXTERNAL_LIB_DIR))
$(info Libraries      $(LIBRARIES))
$(info Dependencies   $(DEPENDENCIES))
$(info Objects        $(OBJECTS))
$(info Object Tree    $(OBJECT_SUBDIRS))
$(info Binary         $(BINARY))

$(info )

# Targets
all: $(BINARY)

$(BINARY): $(OBJECTS)
	$(CXX) $(OBJECTS) $(EXTERNAL_LIB_DIR) $(LIBRARIES) $(CXXFLAGS) -o $@

-include $(DEPENDENCIES)

$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.cpp | $(OBJECT_SUBDIRS)
	$(CXX) $(INCLUDES) $(CXXFLAGS) -MMD -MP -c $< -o $@ 

clean:
	rm -rf $(BUILD_DIR)/* 

$(OBJECT_SUBDIRS):
	mkdir -p $@

.PHONY: clean all
