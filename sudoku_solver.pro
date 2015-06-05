TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp \
    SudokuBoard.cpp \
    SudokuSolverBruteForce.cpp

HEADERS += \
    SudokuBoard.h \
    ISudokuSolver.h \
    SudokuSolverBruteForce.h

