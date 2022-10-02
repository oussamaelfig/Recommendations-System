cmake_minimum_required(VERSION 3.22)
project(Recommendations_System)

set(CMAKE_CXX_STANDARD 14)

include_directories(App)

add_executable(Recommendations_System
        App/01_tableau_compilation.cpp
        App/02_tableau_ajouter.cpp
        App/03_tableau_inserer.cpp
        App/04_tableau_enlever.cpp
        App/05_tableau_occurrence.cpp
        App/06_tableau_unique.cpp
        App/07_tableau_vider.cpp
        App/08_membre_compilation.cpp
        App/09_membre_creation.cpp
        App/10_membre_suggestion.cpp
        App/11_membre_suggestion.cpp
        App/12_performances.cpp
        App/extraction.h
        App/membre.h
        App/tableau.h
        App/tp1.cpp)
