#include <map>

template<typename K, typename V>
class interval_map
{
	std::map<K, V> map_; // I have prefered "map_" alias.

public:

	// We can see that Parameterized Constructor below. It is used to initialize the various data elements of different objects with different values when they are created.
	interval_map(V const& val)
	{
		map_.insert(map_.end(), std::make_pair(std::numeric_limits<K>::lowest(), val));
	}

	void assign_to_map(K const& keyBegin, K const& keyEnd, V const& val)
	{
		if (!(keyBegin < keyEnd)) return;

		using itermap_t = typename decltype(map_)::iterator;

		// input range has finished in here
		itermap_t iter_End = map_.find(keyEnd);
		if (auto l = map_.lower_bound(keyEnd); iter_End != map_.end())
			iter_End->second = l->second;
		else
			iter_End = map_.insert(map_.end(), std::make_pair(keyEnd, (--l)->second));

		// beginning of the input range
		auto iter_Begin = map_.insert_or_assign(keyBegin, val).first;

		// cleanup the new range
		map_.erase(std::next(iter_Begin), iter_End);

		// *** how to canonical method? Implementation is here! ***
		auto iter_Right = iter_End;
		// In below lines, If the beginning iteration key is not the same beginning mapping key, map begins will previous key. If not, mapping begins with iteration key.  
		auto iter_Left = (iter_Begin != map_.begin() ? std::prev(iter_Begin) : iter_Begin);
		if (iter_Right != iter_Left)
		{
			auto iter_Next = std::prev(iter_Right);

			// For Example, map.assign_to_map(0, 14, 'i'); and map.assign_to_map(0, 6765, 'i'); have the same "right arg" or we can say "second arg"
			// Therefore, 'i' will be erased and iteration will begin with [-2147483648:i] and finish with [-2147483648:i] as well. 
			if (iter_Right->second == iter_Next->second)
			{
				map_.erase(iter_Right);
			}
			else
			{
				iter_Right = iter_Next;
			}

		}
	}

	// Lambda Expression just include lambda body
	V const& operator[](K const& key) const
	{
		return (--map_.upper_bound(key))->second;
	}

	void print_map()
	{
		for (auto&& [key, val] : map_)
			std::cout << "[" << key << ':' << val << "]";
		std::cout << '\n';
	}
};

int main()
{
	interval_map<int, char> map{ 'i' }; // map is class instance. We can assume there is a class M so that we can create M obj. obj is instance of class M. 
	map.print_map();

	map.assign_to_map(3, 5, 'r');
	map.print_map();

	map.assign_to_map(2, 3, 's');
	map.print_map();

	map.assign_to_map(2, 3, 't');
	map.print_map();

	map.assign_to_map(2, 4, 'x');
	map.print_map();

	// *** We can see implementation instance of canonical structure in below lines.*** 

	map.assign_to_map(4, 18, 'y');
	map.print_map();

	map.assign_to_map(2, 8, 'z');
	map.print_map();

	map.assign_to_map(0, 14, 'i');
	map.print_map();

	map.assign_to_map(0, 6765, 'i'); // output is [-2147483648:i] because right(second) in above = right(second) is here
	map.print_map();

	map.assign_to_map(0, 54365, 'i'); // output is [-2147483648:i] because right(second) in above = right(second) is here
	map.print_map();
}
