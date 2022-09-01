add_library(SalesData STATIC Sales_data.cpp)

target_include_directories(SalesData PUBLIC ${CAMKE_CURRENT_SOURCE_DIR})