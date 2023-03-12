CC=g++
CFLAGS=-c -Wall
LFLAGS=-Wall

# List of all the source files
SOURCES=cpp/Card/Card.cpp cpp/Card/CardInterface.cpp cpp/Card/Combination.cpp \
        cpp/Commands/Ability.cpp cpp/Commands/Abilityless.cpp cpp/Commands/Commands.cpp \
        cpp/Commands/Double.cpp cpp/Commands/Half.cpp cpp/Commands/Next.cpp \
        cpp/Commands/PlayerInvolvedAbility.cpp cpp/Commands/Quadruple.cpp cpp/Commands/Reroll.cpp \
        cpp/Commands/SwapCard.cpp cpp/Commands/Switch.cpp \
        cpp/GameEnvironment/CandyGameManager.cpp cpp/GameEnvironment/CandyGameState.cpp \
        cpp/GameEnvironment/CandyPlayer.cpp cpp/GameEnvironment/DeckCard.cpp cpp/GameEnvironment/GameDeckCard.cpp cpp/GameEnvironment/AbilityDeckCard.cpp \
        cpp/GameEnvironment/GameManager.cpp cpp/GameEnvironment/GameState.cpp \
        cpp/GameEnvironment/InventoryHolder.cpp cpp/GameEnvironment/Player.cpp \
        cpp/GameEnvironment/TableCard.cpp \
        cpp/Program/IO.cpp main.cpp

# Generate a list of object files from the source file list
OBJECTS=$(SOURCES:.cpp=.o)

# Specify the name of the final executable file
EXECUTABLE=candy_game

# Rule to compile each source file into an object file
%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@

# Default rule to build the executable
all: $(SOURCES) $(EXECUTABLE)

# Rule to build the executable
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LFLAGS) $(OBJECTS) -o $@

# Rule to clean up object files and the executable
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
