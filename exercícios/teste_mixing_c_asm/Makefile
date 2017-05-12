TARGET        := main.elf
SOURCE_DIR    := Src
OBJ_DIR       := Obj
INCLUDE_DIR   := Include
BIN_DIR       := Bin

SOURCE_EXT    := c

SOURCES       := $(shell find $(SOURCE_DIR) -type f -name *.$(SOURCE_EXT))
OBJECTS       := $(patsubst $(SOURCE_DIR)/%,$(OBJ_DIR)/%,$(SOURCES:.$(SOURCE_EXT)=.o))


INC           := -I ./$(INCLUDE_DIR)

CXX           =msp430-gcc $(FLAGS) -mmcu=msp430g2553

RM            := rm -f
FLAGS					:= -Wall

$(TARGET): $(OBJECTS) 
	@mkdir -p $(BIN_DIR)	
	$(CXX) $^ -o $(BIN_DIR)/$(TARGET)

$(OBJ_DIR)/%.o: $(SOURCE_DIR)/%.$(SOURCE_EXT)
	@mkdir -p $(OBJ_DIR)
	$(CXX) -c  $< -o $@  $(INC)

asm_: $(SOURCE_DIR)/%.$(SOURCE_EXT)
	
	$(CXX) -c  $< -o $@ 
	
run: $(TARGET)
	@mspdebug rf2500
	
clean:
	$(RM) -r $(OBJ_DIR) $(BIN_DIR)

.PHONY: clean

 
