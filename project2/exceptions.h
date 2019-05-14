#ifndef _EXCEPTIONS_H
#define _EXCEPTIONS_H


#include<string>
using namespace std;

class AbstractException {
public:
   AbstractException(string src) { this->src = src; }
   ~AbstractException(void) { }
   const string &source(void) { return src; }
   virtual const string toString(void) =0;
private:
   string
   src;
};

class Exception : public AbstractException {
public:
   Exception(string src="") : AbstractException(src) { }
   ~Exception(void) { }
   const string toString(void);
};

class ContainerEmptyException : public Exception {
 public:
   ContainerEmptyException(string src="") : Exception(src) { }
   ~ContainerEmptyException(void) { }
   const string toString(void);
};

class ContainerFullException : public Exception {
 public:
   ContainerFullException(string src="") : Exception(src) { }
   ~ContainerFullException(void) { }
   const string toString(void);
};
class KeyNotFoundException : public Exception {
 public: 
   KeyNotFoundException(string src="", string key="") : Exception(src) {this->key=key;}
   ~KeyNotFoundException(void) { }
   const string toString(void);
 private:
   string key;
};
class InvalidIndexException : public Exception {
 public:
   InvalidIndexException(string src="", int index=0) : Exception(src) {this->index=index; }
   ~InvalidIndexException(void) { }
   const string toString(void);
 private:
   int index;
};
   
#endif	/* _welcome_H */