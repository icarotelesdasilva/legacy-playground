idf_component_register(SRCS "main.c"
                       INCLUDE_DIRS "."
                       REQUIRES led-driver
                       PRIV_REQUIRES esp_driver_gpio)
