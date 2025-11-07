# SPDX-FileCopyrightText: 2023 Carl Zeiss Microscopy GmbH
#
# SPDX-License-Identifier: MIT

include(FetchContent)

# Set necessary build options for libCZI
set(LIBCZI_BUILD_CZICMD OFF CACHE BOOL "" FORCE)
set(LIBCZI_BUILD_DYNLIB OFF CACHE BOOL "" FORCE)
set(LIBCZI_BUILD_UNITTESTS OFF CACHE BOOL "" FORCE)

FetchContent_Declare(
  libCZI
  #GIT_REPOSITORY https://github.com/ptahmose/libCZI.git
  GIT_REPOSITORY https://github.com/ZEISS/libczi
  #GIT_TAG        origin/main
  GIT_TAG        11015ae9aa97abbf9d78293a27115393077f9146 # Freeze to a tested commit
)

# Fetch the content and make it available
FetchContent_MakeAvailable(libCZI)