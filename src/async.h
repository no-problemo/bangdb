/* Copyright (c) 2012-2013 LevelDOWN contributors
 * See list at <https://github.com/rvagg/node-leveldown#contributing>
 * MIT +no-false-attribs License <https://github.com/rvagg/node-leveldown/blob/master/LICENSE>
 */

#ifndef BD_ASYNC_H
#define BD_ASYNC_H

#include <node.h>
#include "nan.h"
#include "database.h"
#include <bangdb/database.h>
namespace bangdb {

class Database;

/* abstract */ class AsyncWorker : public NanAsyncWorker {
public:
  AsyncWorker (
      bangdb::Database* _db
    , NanCallback *callback
  ) : NanAsyncWorker(callback), _db(_db) {
    NanScope();
    v8::Local<v8::Object> obj = v8::Object::New();
    NanAssignPersistent(persistentHandle, obj);
  }

protected:
  Database* _db;
};

} // namespace leveldown

#endif

