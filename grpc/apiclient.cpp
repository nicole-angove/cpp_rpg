#include <grpcpp/grpcpp.h>

#include "grpc/apiclient.h"
#include "grpc/cpprpg.grpc.pb.h"

APIClient::APIClient(std::shared_ptr<grpc::Channel> channel)
    : _stub(PlayerService::NewStub(channel)) {}

bool APIClient::useAbility(const int abilityID) {
  // Data we are sending to the server.
  AbilityID id;
  id.set_id(abilityID);

  // Container for the data we expect from the server.
  Success reply;

  // Context for the client. It could be used to convey extra information to
  // the server and/or tweak certain RPC behaviors.
  grpc::ClientContext context;

  // The actual RPC.
  grpc::Status status = _stub->UseAbility(&context, id, &reply);

  // Act upon its status.
  if (status.ok()) {
    std::cout << reply.success();
    return reply.success();
  } else {
    std::cout << status.error_code() << ": " << status.error_message()
              << std::endl;
    return false;
  }
}
