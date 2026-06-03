# ============================================================
#  CMakeLists.txt — Multi-executable IED build system
#  GI 150kV A — 18 per-IED standalone executables
#
#  Build from MSYS2 MinGW64:
#    mkdir build_ied && cd build_ied
#    cmake .. -G "MinGW Makefiles"
#    mingw32-make -j4
# ============================================================
cmake_minimum_required(VERSION 3.16)
project(sas_ied_suite C)

set(CMAKE_C_STANDARD 11)

# ---- libiec61850 (pre-built) ----
set(LIB61850_ROOT "${CMAKE_CURRENT_LIST_DIR}/../libiec61850")

set(LIB61850_INCLUDE_DIRS
  ${LIB61850_ROOT}/src/iec61850/inc
  ${LIB61850_ROOT}/src/iec61850/inc_private
  ${LIB61850_ROOT}/src/mms/inc
  ${LIB61850_ROOT}/src/mms/inc_private
  ${LIB61850_ROOT}/src/mms/iso_mms/asn1c
  ${LIB61850_ROOT}/src/common/inc
  ${LIB61850_ROOT}/src/logging
  ${LIB61850_ROOT}/src/goose
  ${LIB61850_ROOT}/src/sampled_values
  ${LIB61850_ROOT}/src/r_session
  ${LIB61850_ROOT}/hal/inc
  ${LIB61850_ROOT}/builds/config
)

set(LIB61850_LIBRARIES
  ${LIB61850_ROOT}/builds/src/libiec61850.a
  ${LIB61850_ROOT}/builds/hal/libhal.a
)

# ---- Shared base sources ----
set(BASE_SOURCES
  ${CMAKE_CURRENT_LIST_DIR}/src/shared/ied_server_base.c
  ${CMAKE_CURRENT_LIST_DIR}/src/shared/ied_config.c
  ${CMAKE_CURRENT_LIST_DIR}/src/shared/goose_handler.c
  ${CMAKE_CURRENT_LIST_DIR}/src/shared/cJSON.c
)

# ============================================================
#  Function: Build one IED executable
#  add_ied_exe(<target> <main.c> <model.c> <model_prefix>)
# ============================================================
function(add_ied_exe TARGET_NAME MAIN_SRC MODEL_FILE MODEL_PREFIX)
  add_executable(${TARGET_NAME}
    ${CMAKE_CURRENT_LIST_DIR}/src/relays/${MAIN_SRC}
    ${CMAKE_CURRENT_LIST_DIR}/src/models/${MODEL_FILE}
    ${BASE_SOURCES}
  )
  target_compile_definitions(${TARGET_NAME} PRIVATE MODEL_EXTERN=${MODEL_PREFIX})
  target_include_directories(${TARGET_NAME} PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/src/shared
    ${CMAKE_CURRENT_LIST_DIR}/src/relays
    ${CMAKE_CURRENT_LIST_DIR}/src/models
    ${LIB61850_INCLUDE_DIRS}
  )
  target_link_directories(${TARGET_NAME} PRIVATE
    ${LIB61850_ROOT}/third_party/winpcap/Lib/x64
  )
  target_link_libraries(${TARGET_NAME} PRIVATE
    ${LIB61850_LIBRARIES}
    ws2_32
    wpcap
    Packet
    Iphlpapi
  )
endfunction()

# ============================================================
#  Transformer Bay E01 — TRF-1 (150/30kV)
# ============================================================
add_ied_exe(E01_BCU ied_c264_bcu.c E01_BCU.c model_E01_BCU)
add_ied_exe(E01_P643 ied_p643_diff.c E01_P643.c model_E01_P643)
add_ied_exe(E01_P142 ied_p142_overcurrent.c E01_P142.c model_E01_P142)

# ============================================================
#  Transformer Bay E02 — TRF-2 (150/30kV)
# ============================================================
add_ied_exe(E02_BCU ied_c264_bcu.c E02_BCU.c model_E02_BCU)
add_ied_exe(E02_P643 ied_p643_diff.c E02_P643.c model_E02_P643)
add_ied_exe(E02_P142 ied_p142_overcurrent.c E02_P142.c model_E02_P142)

# ============================================================
#  Transformer Bay E03 — TRF-3 (150/30kV)
# ============================================================
add_ied_exe(E03_BCU ied_c264_bcu.c E03_BCU.c model_E03_BCU)
add_ied_exe(E03_P643 ied_p643_diff.c E03_P643.c model_E03_P643)
add_ied_exe(E03_P142 ied_p142_overcurrent.c E03_P142.c model_E03_P142)

# ============================================================
#  Coupler Bay E04 — Bus Section
# ============================================================
add_ied_exe(E04_BCU ied_c264_bcu.c E04_BCU.c model_E04_BCU)
add_ied_exe(E04_P143 ied_p142_overcurrent.c E04_P143.c model_E04_P143)

# ============================================================
#  Line-1 Bay E05 — 150kV Transmission Line
# ============================================================
add_ied_exe(E05_BCU ied_c264_bcu.c E05_BCU.c model_E05_BCU)
add_ied_exe(E05_P543 ied_p543_distance.c E05_P543.c model_E05_P543)
add_ied_exe(E05_P142 ied_p142_overcurrent.c E05_P142.c model_E05_P142)

# ============================================================
#  Line-2 Bay E06 — 150kV Transmission Line
# ============================================================
add_ied_exe(E06_BCU ied_c264_bcu.c E06_BCU.c model_E06_BCU)
add_ied_exe(E06_P543 ied_p543_distance.c E06_P543.c model_E06_P543)
add_ied_exe(E06_P142 ied_p142_overcurrent.c E06_P142.c model_E06_P142)

# ============================================================
#  Busbar Protection E00 — Station Level
# ============================================================
add_ied_exe(E00_P746 ied_p746_busbar.c E00_P746.c model_E00_P746)
