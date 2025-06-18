set(lib WinSpeak) # nom de la library


# Définir une fonction pour ajouter des tests facilement
function(add_crypto_test test_name test_source)
    add_executable(${test_name} ${test_source})
    target_link_libraries(${test_name} PRIVATE ${lib})
    add_test(NAME ${test_name} COMMAND ${test_name})
endfunction()

# Activer les tests
enable_testing()


# Ajouter ici tous les fichiers de test
add_crypto_test(test_WinSpeak test_WinSpeak.cpp)

