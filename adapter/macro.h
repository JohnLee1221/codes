#ifndef ADAPTER_MACTOR_H_
#define ADAPTER_MACTOR_H_

#define DISALLOW_COPY_AND_ASSIGN(classname)       \
 private:                                         \
  classname(const classname&);                    \
  classname& operator=(const classname&);

#define DISALLOW_IMPLICIT_CONSTRUCTORS(classname) \
 private:                                         \
  classname();                                    \
  DISALLOW_COPY_AND_ASSIGN(classname);

#define DECLEAR_SINGLETON(classname)              \
 public:                                          \
  static classname* instance() {                  \
    static classname instance;                    \
    return &instance;                             \
  }                                               \
  DISALLOW_IMPLICIT_CONSTRUCTORS(classname)       \
 private:

#endif  // ADAPTER_MACTOR_H_
