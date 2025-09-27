# cmake files support debug production
include("${CMAKE_CURRENT_LIST_DIR}/rule.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/file.cmake")

set(practice_1_default_library_list )

# Handle files with suffix (s|as|asm|AS|ASM|As|aS|Asm), for group default-XC8
if(practice_1_default_default_XC8_FILE_TYPE_assemble)
add_library(practice_1_default_default_XC8_assemble OBJECT ${practice_1_default_default_XC8_FILE_TYPE_assemble})
    practice_1_default_default_XC8_assemble_rule(practice_1_default_default_XC8_assemble)
    list(APPEND practice_1_default_library_list "$<TARGET_OBJECTS:practice_1_default_default_XC8_assemble>")
endif()

# Handle files with suffix S, for group default-XC8
if(practice_1_default_default_XC8_FILE_TYPE_assemblePreprocess)
add_library(practice_1_default_default_XC8_assemblePreprocess OBJECT ${practice_1_default_default_XC8_FILE_TYPE_assemblePreprocess})
    practice_1_default_default_XC8_assemblePreprocess_rule(practice_1_default_default_XC8_assemblePreprocess)
    list(APPEND practice_1_default_library_list "$<TARGET_OBJECTS:practice_1_default_default_XC8_assemblePreprocess>")
endif()

# Handle files with suffix [cC], for group default-XC8
if(practice_1_default_default_XC8_FILE_TYPE_compile)
add_library(practice_1_default_default_XC8_compile OBJECT ${practice_1_default_default_XC8_FILE_TYPE_compile})
    practice_1_default_default_XC8_compile_rule(practice_1_default_default_XC8_compile)
    list(APPEND practice_1_default_library_list "$<TARGET_OBJECTS:practice_1_default_default_XC8_compile>")
endif()

add_executable(practice_1_default_image_cp3SWT_d ${practice_1_default_library_list})

set_target_properties(practice_1_default_image_cp3SWT_d PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${practice_1_default_output_dir})
set_target_properties(practice_1_default_image_cp3SWT_d PROPERTIES OUTPUT_NAME "default")
set_target_properties(practice_1_default_image_cp3SWT_d PROPERTIES SUFFIX ".elf")

target_link_libraries(practice_1_default_image_cp3SWT_d PRIVATE ${practice_1_default_default_XC8_FILE_TYPE_link})


# Add the link options from the rule file.
practice_1_default_link_rule(practice_1_default_image_cp3SWT_d)



