
# BUILD_TESTING variable is created by include(CTest)
# It is set to ON by default
if (BUILD_TESTING)


	include_directories(
		"${CMAKE_SOURCE_DIR}/include"
	)

    add_executable(TestCollision TestCollisions.cpp)
    target_link_libraries(TestCollision PRIVATE GTest::gtest_main)
    target_link_libraries(TestCollision PRIVATE PhysiksStatic)

    include(GoogleTest)
    gtest_discover_tests(TestCollision)
endif()