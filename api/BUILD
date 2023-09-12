cc_library(
  name = "api",
  srcs = [
    "api.cpp",
  ],
  hdrs = [
    "api.h",
  ],
  visibility = ["//visibility:public"]
)

cc_test(
  name = "apitest",
  size = "small",
  srcs = ["apitest.cpp"],
  deps = [
    "@com_google_googletest//:gtest_main",
    ":api",
  ],
)
