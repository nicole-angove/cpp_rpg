#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>

#include "api.h"
#include "apiserver.h"
#include "cpprpg.grpc.pb.h"

using grpc::ServerContext;
using grpc::Status;

class PlayerServiceImpl final : public PlayerService::Service {
  Status UseAbility(ServerContext *context, const AbilityID *id,
                    Success *reply) override {
    reply->set_success(useAbility(id->id()));
    return Status::OK;
  }
};

std::tuple<std::unique_ptr<grpc::Server>, std::unique_ptr<grpc::Service>>
RunServer() {
  // Set up generic gRPC server on all interfaces
  std::string server_address("0.0.0.0:50051");
  
  grpc::EnableDefaultHealthCheckService(true);
  grpc::reflection::InitProtoReflectionServerBuilderPlugin();
  grpc::ServerBuilder builder;

  // Listen on the given address without any authentication mechanism.
  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());

  // Create service to be hosted by server
  auto service = std::make_unique<PlayerServiceImpl>();

  // Register "service" as the instance through which we'll communicate with
  // clients. In this case it corresponds to a *synchronous* service.
  builder.RegisterService(service.get());

  // Finally assemble the server.
  auto server = builder.BuildAndStart();

  // Wait for the server to shutdown. Note that some other thread must be
  // responsible for shutting down the server for this call to ever return.
  return std::make_tuple(std::move(server), std::move(service));
}
