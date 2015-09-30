#include "PreconditionViolationException.h"
#include <stdexcept>


PreconditionViolationException::PreconditionViolationException(const char* message) : std::runtime_error(message) {}

