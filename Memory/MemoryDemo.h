#pragma once

#include <stddef.h>
#include <new>

class MemoryDemo
{
public:
	virtual ~MemoryDemo() = default;

	void* operator new(size_t size);
	void operator delete(void* ptr) noexcept;

	void* operator new[](size_t size);
	void operator delete[](void* ptr) noexcept;

	void* operator new(size_t size, const std::nothrow_t&) noexcept;
	void operator delete(void* ptr, const std::nothrow_t&) noexcept;

	void* operator new[](size_t size, const std::nothrow_t&) noexcept;
	void operator delete[](void* ptr, const std::nothrow_t&) noexcept;

	void* operator new(size_t size, int extra);
	void operator delete(void* ptr, int extra) noexcept;
};

