# cmake .. -DCMAKE_BUILD_TYPE=Release
# cmake --build .
# cmake --install .

cmake_minimum_required(VERSION 3.10)

# définition du nom de la library
set(PROJECT_NAME WinSpeak)
set(PROJECT_VERSION 1.0.0)

#project(WinSpeak)
project(${PROJECT_NAME} VERSION ${PROJECT_VERSION} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Forcer un build type par défaut si non défini
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()

set(SOURCES
    src/WinSpeak.cpp

)

set(HEADERS
    include/${PROJECT_NAME}/ISpeak.hpp
    include/${PROJECT_NAME}/WinSpeak.hpp

)

# Créer la library static
add_library(${PROJECT_NAME} STATIC ${SOURCES} ${HEADERS})

# Ajouter des options de compilation (par exemple, pour activer les optimisations)
target_compile_options(${PROJECT_NAME} PRIVATE     
    $<$<CONFIG:Debug>:-g>
    $<$<CONFIG:Debug>:-Wall>
    $<$<CONFIG:Debug>:-Wextra>
    $<$<CONFIG:Release>:-O2>
    $<$<CONFIG:Release>:-Wall>
    $<$<CONFIG:Release>:-Wextra>
)

# Linker les option l'ors de la compilation de la library static
target_link_libraries(${PROJECT_NAME} PRIVATE 
    ole32
    uuid    
)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)


# Définir le répertoire de sortie pour la bibliothèque compilée
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Définir l'emplacement d'installation
set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/${PROJECT_NAME})

# Ajouter un dossier pour les fichiers d'en-tête
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_PREFIX}/include)

# Installer la bibliothèque dans le dossier lib/
install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)

#partie des unit test

enable_testing()
add_subdirectory(tests)
