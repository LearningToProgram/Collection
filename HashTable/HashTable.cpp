#include <iostream>

class HashEntry
{
public:
	inline HashEntry(int key, int val)
	{
		this->key = key;
		this->val = val;
	}

	inline int GetKey() { return key; }
	inline int GetValue() { return val; }
private:
	int key, val;
};

class HashMap
{
public:
	inline HashMap() : mTableSize(128)
	{
		table = new HashEntry*[mTableSize];
		for (int i = 0; i < mTableSize; i++)
			table[i] = NULL;
	}

	inline int Get(int key)
	{
		int hash = (key % mTableSize);
		while (table[hash] != NULL && table[hash]->GetKey() != key)
		{
			hash = (hash + 1) % mTableSize;
			std::cout << "[ GET ] Hash: " << hash << "\n";
		}

		if (table[hash] == NULL)
			return -1;
		else
			return table[hash]->GetValue();
	}

	inline void Put(int key, int value)
	{
		int hash = (key % mTableSize);

		while (table[hash] != NULL && table[hash]->GetKey() == key)
		{
				hash = (hash + 1) % mTableSize;
				key = hash;
				std::cout << "[ PUT ] Hash: " << hash << "\n";
		}

		if (table[hash] == NULL)
			delete table[hash];
		table[hash] = new HashEntry(key, value);
	}

	inline ~HashMap()
	{
		for (int i = 0; i < mTableSize; i++)
			if (table[i] != NULL)
				delete table[i];
		delete[] table;
	}

	inline void ShowTable(bool nonEmpty = false)
	{
		std::cout << "\n---------------TABLE OF CONTENT----------------\n";
		for (int i = 0; i < mTableSize; i++)
		{
			if(nonEmpty && table[i] != NULL)
				std::cout << "i( " << i << " )  \t" << table[i]->GetValue() << "\n";
		}
		std::cout << "-----------------------------------------------\n";
	}

private:
	HashEntry **table;
	const int mTableSize;
};

int main()
{
	std::cout << "Insert value -->\n";
	HashMap hm;
	hm.Put(125, 1984);
	hm.Put(128, 1984);
	hm.Put(1, 1985);
	hm.Put(1, 1984);
	hm.Put(1, 19);
	hm.Put(1, 1918745);
	std::cout << "<-- Insert value\n\n";
	hm.ShowTable(true);
	std::cout << "Get value -->\n"
			  << hm.Get(1) << "\n"
			  << hm.Get(2) << "\n"
			  << "<-- Get value\n";
	
	return 0;
}
