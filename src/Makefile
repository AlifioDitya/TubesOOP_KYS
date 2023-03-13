CXX := g++
CXXFLAGS := -c -Wall
LFLAGS := -Wall
EXECUTABLE := candy_game.out  # Final executable file name

# List of all the source files

SOURCES=cpp/Card/Card.cpp cpp/Card/CardInterface.cpp cpp/Card/Combination.cpp \
        cpp/Program/IO.cpp \
        cpp/GameEnvironment/Player.cpp \
        cpp/GameEnvironment/TableCard.cpp \
        cpp/GameEnvironment/GameDeckCard.cpp cpp/GameEnvironment/AbilityDeckCard.cpp \
        cpp/GameEnvironment/CandyPlayer.cpp \
        cpp/GameEnvironment/CandyGameState.cpp \
        cpp/Commands/Commands.cpp \
        cpp/Commands/Double.cpp cpp/Commands/Half.cpp cpp/Commands/Next.cpp \
        cpp/Commands/Ability.cpp cpp/Commands/Quarter.cpp cpp/Commands/Quadruple.cpp cpp/Commands/Reroll.cpp cpp/Commands/Reverse.cpp \
        cpp/Commands/PlayerInvolvedAbility.cpp cpp/Commands/Abilityless.cpp cpp/Commands/SwapCard.cpp cpp/Commands/Switch.cpp \
        cpp/GameEnvironment/CandyGameManager.cpp \
        main.cpp

# Generate a list of object files from the source file list
OBJECTS = $(SOURCES:.cpp=.o)

# Rule to compile each source file into an object file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

# Default rule to build the executable
all: $(SOURCES) $(EXECUTABLE)

# Rule to build the executable
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(LFLAGS) $(OBJECTS) -o $@

# Rule to clean up object files and the executable
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
