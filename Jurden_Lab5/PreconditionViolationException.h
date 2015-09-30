#ifndef PRECONDITION_VIOLATION_EXCEPTION_H
#define	PRECONDITION_VIOLATION_EXCEPTION_H

#include <stdexcept>

class PreconditionViolationException: public std::runtime_error
{	
	public: 
		PreconditionViolationException(const char* message);
};

#endif
