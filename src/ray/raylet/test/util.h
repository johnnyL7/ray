// Copyright 2017 The Ray Authors.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//  http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "ray/raylet/worker.h"

namespace ray {

namespace raylet {

class MockWorker : public WorkerInterface {
 public:
  MockWorker(WorkerID worker_id, int port) : worker_id_(worker_id), port_(port) {}

  WorkerID WorkerId() const { return worker_id_; }

  rpc::WorkerType GetWorkerType() const { return rpc::WorkerType::WORKER; }

  int Port() const { return port_; }

  void SetOwnerAddress(const rpc::Address &address) { address_ = address; }

  void AssignTaskId(const TaskID &task_id) {}

  // TODO(kfstorm): Remove this once `enable_multi_tenancy` is deleted.
  void AssignJobId(const JobID &job_id) {}

  void SetAssignedTask(Task &assigned_task) {}

  const std::string IpAddress() const { return address_.ip_address(); }

  void SetAllocatedInstances(
      std::shared_ptr<TaskResourceInstances> &allocated_instances) {
    allocated_instances_ = allocated_instances;
  }

  void SetLifetimeAllocatedInstances(
      std::shared_ptr<TaskResourceInstances> &allocated_instances) {
    lifetime_allocated_instances_ = allocated_instances;
  }

  std::shared_ptr<TaskResourceInstances> GetAllocatedInstances() {
    return allocated_instances_;
  }
  std::shared_ptr<TaskResourceInstances> GetLifetimeAllocatedInstances() {
    return lifetime_allocated_instances_;
  }

  void MarkDead() { RAY_CHECK(false) << "Method unused"; }
  bool IsDead() const {
    RAY_CHECK(false) << "Method unused";
    return false;
  }
  void MarkBlocked() { RAY_CHECK(false) << "Method unused"; }
  void MarkUnblocked() { RAY_CHECK(false) << "Method unused"; }
  bool IsBlocked() const {
    RAY_CHECK(false) << "Method unused";
    return false;
  }

  Process GetProcess() const {
    RAY_CHECK(false) << "Method unused";
    return Process::CreateNewDummy();
  }
  void SetProcess(Process proc) { RAY_CHECK(false) << "Method unused"; }
  Language GetLanguage() const {
    RAY_CHECK(false) << "Method unused";
    return Language::PYTHON;
  }

  void Connect(int port) { RAY_CHECK(false) << "Method unused"; }

  int AssignedPort() const {
    RAY_CHECK(false) << "Method unused";
    return -1;
  }
  void SetAssignedPort(int port) { RAY_CHECK(false) << "Method unused"; }
  const TaskID &GetAssignedTaskId() const {
    RAY_CHECK(false) << "Method unused";
    return TaskID::Nil();
  }
  bool AddBlockedTaskId(const TaskID &task_id) {
    RAY_CHECK(false) << "Method unused";
    return false;
  }
  bool RemoveBlockedTaskId(const TaskID &task_id) {
    RAY_CHECK(false) << "Method unused";
    return false;
  }
  const std::unordered_set<TaskID> &GetBlockedTaskIds() const {
    RAY_CHECK(false) << "Method unused";
    auto *t = new std::unordered_set<TaskID>();
    return *t;
  }
  const JobID &GetAssignedJobId() const {
    RAY_CHECK(false) << "Method unused";
    return JobID::Nil();
  }
  void AssignActorId(const ActorID &actor_id) { RAY_CHECK(false) << "Method unused"; }
  const ActorID &GetActorId() const {
    RAY_CHECK(false) << "Method unused";
    return ActorID::Nil();
  }
  void MarkDetachedActor() { RAY_CHECK(false) << "Method unused"; }
  bool IsDetachedActor() const {
    RAY_CHECK(false) << "Method unused";
    return false;
  }
  const std::shared_ptr<ClientConnection> Connection() const {
    RAY_CHECK(false) << "Method unused";
    return nullptr;
  }
  const rpc::Address &GetOwnerAddress() const {
    RAY_CHECK(false) << "Method unused";
    return address_;
  }

  const ResourceIdSet &GetLifetimeResourceIds() const {
    RAY_CHECK(false) << "Method unused";
    auto *t = new ResourceIdSet();
    return *t;
  }
  void SetLifetimeResourceIds(ResourceIdSet &resource_ids) {
    RAY_CHECK(false) << "Method unused";
  }
  void ResetLifetimeResourceIds() { RAY_CHECK(false) << "Method unused"; }

  const ResourceIdSet &GetTaskResourceIds() const {
    RAY_CHECK(false) << "Method unused";
    auto *t = new ResourceIdSet();
    return *t;
  }
  void SetTaskResourceIds(ResourceIdSet &resource_ids) {
    RAY_CHECK(false) << "Method unused";
  }
  void ResetTaskResourceIds() { RAY_CHECK(false) << "Method unused"; }
  ResourceIdSet ReleaseTaskCpuResources() {
    RAY_CHECK(false) << "Method unused";
    auto *t = new ResourceIdSet();
    return *t;
  }
  void AcquireTaskCpuResources(const ResourceIdSet &cpu_resources) {
    RAY_CHECK(false) << "Method unused";
  }

  Status AssignTask(const Task &task, const ResourceIdSet &resource_id_set) {
    RAY_CHECK(false) << "Method unused";
    Status s;
    return s;
  }
  void DirectActorCallArgWaitComplete(int64_t tag) {
    RAY_CHECK(false) << "Method unused";
  }

  void ClearAllocatedInstances() { allocated_instances_ = nullptr; }

  void ClearLifetimeAllocatedInstances() { RAY_CHECK(false) << "Method unused"; }

  void SetBorrowedCPUInstances(std::vector<double> &cpu_instances) {
    borrowed_cpu_instances_ = cpu_instances;
  }

  const PlacementGroupID &GetPlacementGroupId() const {
    RAY_CHECK(false) << "Method unused";
    return PlacementGroupID::Nil();
  }

  void SetPlacementGroupId(const PlacementGroupID &placement_group_id) {
    RAY_CHECK(false) << "Method unused";
  }

  std::vector<double> &GetBorrowedCPUInstances() { return borrowed_cpu_instances_; }

  void ClearBorrowedCPUInstances() { RAY_CHECK(false) << "Method unused"; }

  Task &GetAssignedTask() {
    RAY_CHECK(false) << "Method unused";
    auto *t = new Task();
    return *t;
  }

  bool IsRegistered() {
    RAY_CHECK(false) << "Method unused";
    return false;
  }

  rpc::CoreWorkerClientInterface *rpc_client() {
    RAY_CHECK(false) << "Method unused";
    return nullptr;
  }

 private:
  WorkerID worker_id_;
  int port_;
  rpc::Address address_;
  std::shared_ptr<TaskResourceInstances> allocated_instances_;
  std::shared_ptr<TaskResourceInstances> lifetime_allocated_instances_;
  std::vector<double> borrowed_cpu_instances_;
};

}  // namespace raylet

}  // namespace ray
