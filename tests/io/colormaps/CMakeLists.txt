SET(DGTAL_TESTS_SRC_COLORMAP
       testColorMaps       )


FOREACH(FILE ${DGTAL_TESTS_SRC_COLORMAP})
  add_executable(${FILE} ${FILE})
  target_link_libraries (${FILE} ${LIBDGTAL_NAME} ${LIBBOARD_NAME})
  add_test(${FILE} ${FILE})
ENDFOREACH(FILE)

