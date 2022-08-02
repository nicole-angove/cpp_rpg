cc_library(
  name = "board",
  srcs = [
    "board.cpp",
    "element.cpp",
    "movemap.cpp",
    "sphere.cpp",
  ],
  hdrs = [
    "board.h",
    "element.h",
    "movemap.h",
    "sphere.h",
  ],
)

cc_test(
  name = "hello_test",
  size = "small",
  srcs = ["hello_test.cc"],
  deps = [
    "@com_google_googletest//:gtest_main",
    ":board",
  ],
)
