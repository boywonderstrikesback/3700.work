include "exceptions.h"

const string Exception::toString(void) {
 string msg;

 if (source().length() > 0) {
  msg = source() + ": ";
 } else {
  msg = "";
 }
 msg += "generic_exception";

 return msg;
}

const string ContainerEmptyException::toString(void) {
 string msg;

 if (source().length() > 0) {
  msg = source() + ": ";
 } else {
  msg = "";
 }
 msg += "container_empty";

 return msg;
}

const string ContainerFullException::toString(void) {
 string msg;

 if (source().length() > 0) {
  msg = source() + ": ";
 } else {
  msg = "";
 }
 msg += "container_full";

 return msg;
}

const string KeyNotFoundException::toString(void) {
 string msg;

 if (source().length() > 0) {
  msg = "key - " + key + "; src - " + source() + ": ";
 } else {
  msg = "";
 }
 msg += "key_not_found";

 return msg;
}

const string InvalidIndexException::toString(void) {
 string msg;

 if (source().length() > 0) {
  msg = "index - " + std::to_string(index) + "; src - " + source() + ": ";
 } else {
  msg = "";
 }
 msg += "invalid_index";

 return msg;
}