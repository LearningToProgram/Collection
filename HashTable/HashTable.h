#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
class HashEntry
{
public:
	inline HashEntry(int key, int val)
	{
		this->key = key;
		this->val = val;
	}

	inline int GetKey() const { return key; }
	inline int GetValue() const { return val; }
private:
	int key, val;
};

class HashTable
{
public:
	inline HashTable() : mTableSize(128)
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

	inline ~HashTable()
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
			if (nonEmpty && table[i] != NULL)
				std::cout << "i( " << i << " )  \t" << table[i]->GetValue() << "\n";
		}
		std::cout << "-----------------------------------------------\n";
	}

private:
	HashEntry **table;
	const int mTableSize;
}; 

void HashTreeExample()
{
	std::cout << "Insert value -->\n";
	HashTable ht;
	ht.Put(125, 1984);
	ht.Put(128, 1984);
	ht.Put(1, 1985);
	ht.Put(1, 1984);
	ht.Put(1, 19);
	ht.Put(1, 1918745);
	std::cout << "<-- Insert value\n\n";
	ht.ShowTable(true);
	std::cout << "Get value -->\n"
		<< ht.Get(1) << "\n"
		<< ht.Get(2) << "\n"
		<< "<-- Get value\n";
}

#endif