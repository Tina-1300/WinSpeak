
# Ajouter les fichiers sources de tests
set(TEST_SOURCES
    test_WinSpeak.cpp 
)

# Créer une cible pour les tests
add_executable(tests ${TEST_SOURCES})

# Lier la bibliothèque principale aux tests
target_link_libraries(tests PRIVATE 
    WinSpeak
    
)

# Activer les tests avec CTest
enable_testing()
add_test(NAME Tests COMMAND tests)
