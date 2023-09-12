#include <grpcpp/grpcpp.h>
#include <grpcpp/impl/codegen/service_type.h>

#include "grpc/apiserver.h"

int main(int argc, char **argv) {
  auto server = RunServer();

  std::get<std::unique_ptr<grpc::Server>>(server)->Wait();

  return 0;
}
