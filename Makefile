CXX ?= c++
CXXFLAGS ?= -O2 -std=c++17 -Wall -Wextra -pedantic
all: felix mafia
felix: felix-repairman/main.cpp
	$(CXX) $(CXXFLAGS) $< -o $@
mafia: mafia-nights/main.cpp
	$(CXX) $(CXXFLAGS) $< -o $@
test: all
	python3 tests/regression.py
clean:
	rm -f felix mafia felix.exe mafia.exe
.PHONY: all test clean
