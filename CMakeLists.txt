cmake_minimum_required(VERSION 3.16)

# Diz ao ESP-IDF que estas duas pastas contêm componentes de código
set(EXTRA_COMPONENT_DIRS "botaoconfigs" "componentes")

include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(FIRMWARE-LED-BOOTON)
