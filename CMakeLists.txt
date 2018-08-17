cmake_minimum_required(VERSION 3.10)

project(emojicode-sha VERSION 0.1)

file(GLOB EMOJIC_DEPEND "src/*.emojic")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
add_library(emojicode-sha STATIC src/sha.cpp sha_.o)

set_property(TARGET emojicode-sha PROPERTY POSITION_INDEPENDENT_CODE ON)
set_target_properties(emojicode-sha PROPERTIES PREFIX "")
set_target_properties(emojicode-sha PROPERTIES OUTPUT_NAME "sha")

target_compile_options(emojicode-sha PUBLIC -Wall -Wno-unused-result -Wno-missing-braces -pedantic)

add_custom_command(OUTPUT sha_.o COMMAND emojicodec -p sha -o src/sha.o -i
    interface.emojii -c ../src/sha.emojic --color DEPENDS ${EMOJIC_DEPEND})

install(FILES build/sha.a DESTINATION lib/emojicode/sha)
install(FILES interface.emojii DESTINATION lib/emojicode/sha)

#install(TARGETS emojicode-sha
#    ARCHIVE DESTINATION lib/emojicode/sha)
    
#install(FILES src/interface.emojii
#    DESTINATION lib/emojicode/sha)