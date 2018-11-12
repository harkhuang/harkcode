
#include <new>// for new
#include <cstddef> //  size_t
#include <climits> // for unit_max
#include <iostream> // for cerr
using namespace std;

namespace SLD {
template <class T>
class allocator
{
public:
	typedef T		value_type;
	typedef T*		pointer;
	typedef const T*	const_pointer;
	typedef T&		reference;
	typedef const T&	const_reference;
	typedef size_t		size_type;
	typedef ptrdiff_t	difference_type;

	template <class U>
	struct rebind
	{
		typedef allocator<U> other;
	};

	//申请内存
	pointer allocate(size_type n, const void* hint = 0)
	{
		T* tmp = (T*)(::operator new((size_t)(n * sizeof(T))));
		//operator new 和new operator是不同的
		if (!tmp)
			cerr << "out of memory"<<endl;
		
		return tmp;

	}

	//释放内存
	void deallocate(pointer p)
	{
		::operator delete(p);
	}
	
	//构造
	void construct(pointer p, const T& value)
	{
		new(p) T(value);
	}
	
	//析构
	void destroy(pointer p)
	{
		p->~T();
	}
	
	//取地址
	pointer address(reference x)
	{
		return (pointer)&x;
	}
	

	const_pointer const_address(const_reference x)
	{
		return (const_pointer)&x;
	}

	size_type max_size() const 
	{
		return size_type(UINT_MAX/sizeof(T));
	}
};
}


int main()
{
	vector<int, SLD::allocator<int> > vec; 
	return 0;
}