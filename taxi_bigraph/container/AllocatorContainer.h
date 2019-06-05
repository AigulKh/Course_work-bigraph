#pragma once

#include <memory>
#include <limits>


namespace BigraphProject
{
	template <typename T>
	class AllocatorContainer
	{
	public:
		using value_type = T;

		using pointer = T *;
		using const_pointer = const T*;

		using size_type = size_t;

		template<typename R>
		struct rebind
		{
			using other = AllocatorContainer<R>;
		};

		// default constructors and destructor
		AllocatorContainer() = default;
		~AllocatorContainer() = default;
		template<typename R>
		AllocatorContainer(const AllocatorContainer<R>& other) {};

		// allocate memory
		pointer allocate(size_type num_of_object)
		{
			return static_cast<pointer>(operator new(sizeof(T) * num_of_object));
		};

		// deallocate memory
		void deallocate(pointer p, size_type num_of_object)
		{
			operator delete(p);
		};

		// max memory size
		size_type max_size() const
		{
			return std::numeric_limits<size_type>::max();
		};

		// construct object
		template<typename R, typename ... Args>
		void construct(R* p, Args & ...args)
		{
			new(p) R(std::forward<Args>(args)...);
		};

		// destroy object
		template<typename R>
		void destroy(R *p)
		{
			p->~R();
		};
	};
}
