#include <grpcpp/grpcpp.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <gtest/gtest.h>

#include "apiclient.h"
#include "apiserver.h"

class GRPCTest : public ::testing::Test {
public:
  GRPCTest()
      : client(grpc::CreateChannel("0.0.0.0:50051",
                                   grpc::InsecureChannelCredentials())) {
    std::tie(server, service) = RunServer();
  }

protected:
  void SetUp() override {}

  void TearDown() override {}

  std::unique_ptr<grpc::Server> server;
  std::unique_ptr<grpc::Service> service;
  APIClient client;
};

TEST_F(GRPCTest, useAbilitySuccess) {
  bool expectedResult = true;

  bool result = client.useAbility(0);

  EXPECT_EQ(expectedResult, result);
}

TEST_F(GRPCTest, useAbilityFailure) {
  bool expectedResult = false;

  bool result = client.useAbility(1);

  EXPECT_EQ(expectedResult, result);
}
