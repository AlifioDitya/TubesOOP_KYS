CXX := g++  # C++ compiler
CXXFLAGS := -c -Wall  # Flags when compiling into object files
LFLAGS := -Wall  # Flags when linking into executable
EXECUTABLE := ../bin/game.out  # Final executable file path and its name

# List of all the source files
SOURCES := cpp/Card/Card.cpp \
		cpp/Card/CardInterface.cpp \
		cpp/Card/Combination.cpp \
		cpp/Card/Combinations/Flush.cpp \
		cpp/Card/Combinations/FourOfAKind.cpp \
		cpp/Card/Combinations/FullHouse.cpp \
		cpp/Card/Combinations/HighCard.cpp \
		cpp/Card/Combinations/Pair.cpp \
		cpp/Card/Combinations/Straight.cpp \
		cpp/Card/Combinations/StraightFlush.cpp \
		cpp/Card/Combinations/ThreeOfAKind.cpp \
		cpp/Card/Combinations/TwoPair.cpp \
        cpp/Commands/Ability.cpp \
        cpp/Commands/Abilityless.cpp \
        cpp/Commands/Cangkul.cpp \
        cpp/Commands/CangkulCommand.cpp \
        cpp/Commands/Commands.cpp \
        cpp/Commands/Double.cpp \
        cpp/Commands/Half.cpp \
        cpp/Commands/Next.cpp \
        cpp/Commands/PlayerInvolvedAbility.cpp \
        cpp/Commands/Put.cpp \
        cpp/Commands/Quadruple.cpp \
        cpp/Commands/Quarter.cpp \
        cpp/Commands/Reroll.cpp \
        cpp/Commands/Reverse.cpp \
        cpp/Commands/Skip.cpp \
        cpp/Commands/SwapCard.cpp \
        cpp/Commands/Switch.cpp \
        cpp/GameEnvironment/AbilityDeckCard.cpp \
        cpp/GameEnvironment/CandyGameManager.cpp \
        cpp/GameEnvironment/CandyGameState.cpp \
        cpp/GameEnvironment/CandyPlayer.cpp \
        cpp/GameEnvironment/CangkulGameManager.cpp \
        cpp/GameEnvironment/CangkulGameState \
        cpp/GameEnvironment/GameDeckCard.cpp \
        cpp/GameEnvironment/Player.cpp \
        cpp/GameEnvironment/TableCard.cpp \
        cpp/EasterEgg/Solver.cpp \
        cpp/EasterEgg/TFCardGameManager.cpp \
        cpp/Program/IO.cpp \
        cpp/Program/Program.cpp \
        main.cpp

# Generate a list of object files from the source file list
OBJECTS := $(SOURCES:.cpp=.o)

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

# Rule to clean up object files
clean_obj:
	rm -f $(OBJECTS)