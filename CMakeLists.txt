cmake_minimum_required(VERSION 3.10)

project(sha VERSION 0.1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_STANDARD 11)

file(GLOB EMOJIC_DEPEND "src/*.emojic")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
add_library(sha STATIC src/sha.cpp sha_.o)

set_property(TARGET sha PROPERTY POSITION_INDEPENDENT_CODE ON)

target_compile_options(sha PUBLIC -Wall -Wno-unused-result -Wno-missing-braces -pedantic)

get_filename_component(MAIN_FILE src/sha.emojic ABSOLUTE)

add_custom_command(OUTPUT sha_.o COMMAND emojicodec -p sha -o sha_.o -i
    interface.emojii -c ${MAIN_FILE} --color DEPENDS ${EMOJIC_DEPEND})

install(FILES build/sha.a DESTINATION lib/emojicode/sha)
install(FILES interface.emojii DESTINATION lib/emojicode/sha)

#install(TARGETS sha
#    ARCHIVE DESTINATION lib/emojicode/sha)

#install(FILES src/interface.emojii
#    DESTINATION lib/emojicode/sha)
